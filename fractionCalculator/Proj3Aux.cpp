#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Proj3Aux.h"
#include "Fraction.h"

using namespace std;

static bool ParseTerm(stringstream& strIn, Fraction& result);
static bool ParseFraction(string& fracStr, Fraction& result);
static bool ParseExpr(stringstream& strIn, Fraction& result);
static bool GetNumber(string bufferStr, size_t start, size_t end, int& value,
    bool& negFlag);
static void ShowParseErrorPt(stringstream& strIn);

/*
 * Parse:
 *   Method to drive the parsing of the top-level expression
 *   (i.e., the whole enchilada).
 *   It simply sets up the I/O infrastructure and kicks off the
 *   recursion by looking for a "term"
 *
 * Expected form parser is looking for:
 *    "( * 3&7/8 ( + ( * 15&7/2 12 ) ) ) 
 *
 * Error is at strIn.tellg();
 */
bool Parse(string input) {
    Fraction result;
    stringstream strIn(input);
    bool status;

    if ((status = ParseTerm(strIn, result))) {
	cout << result << endl;
    }
    else {
	ShowParseErrorPt(strIn);
    }
    return status;
}

/*
 * A "term" is either a simple Fraction, or a parenthesized expression
 * wrapping an operator and two terms.  This function peeks ahead at
 * input stream, and decides which of these it is likely to be, then
 * recurses to process it.
 */
static bool ParseTerm(stringstream& strIn, Fraction& result) {
    string tokenStr, endParenStr;
    Fraction tmpResult;
    bool status = false;  // Pessimistic initial value

    strIn >> tokenStr;
    if (tokenStr.compare("(") == 0) {
	if ((status = ParseExpr(strIn, tmpResult))) {
	    strIn >> endParenStr;
	    if (endParenStr.compare(")") != 0) {
		// ERROR
		cerr << "Didn't get expected ')'\n";
		status = false;
	    }
	    else {
		result = tmpResult;
		status = true;
	    }
	}
    }
    else {
	// A simple term: just a Fraction
	if ((status = ParseFraction(tokenStr, tmpResult))) {
	    result = tmpResult;
	}
    }
    return status;
}

/*
 * ParseFraction:
 *   We are called by ParseTerm() if it decides we have a simple fraction.
 *   Since it had to look ahead to determine this, it passes in to us
 *   the peek-ahead string, which has our entire fraction string
 * Precondition:
 *   fracStr: the read-ahead string buffer it read before calling us
 *
 * Postconditions:
 *   result: if success, contains the fraction that was input, in original
 *     (i.e., non-normalized) form; if error, "result" is NOT modified.
 *   Returns true if all went well, false if error.
 */
static bool ParseFraction(string& fracStr, Fraction& result) {
    size_t ampPos, slashPos;
    int whole = 0;
    int numerator = 0;
    int denominator = 1;
    string tmpStr;
    bool negFlag, tmpNegFlag;
    bool status = true;  // Optimistic initial value

    ampPos = fracStr.find('&');
    slashPos = fracStr.find('/');
    negFlag = true;

    // Parse the string into its 1, 2, or 3 parts
    if (ampPos != string::npos) {
	// Found a full 3-part fraction spec
	// The '/' is now mandatory
	if (slashPos == string::npos) {
	    cerr << "ERROR: missing '/' in fraction--";
	    status = false;
	}
	else {
	    status = GetNumber(fracStr, 0, ampPos, whole, negFlag) &&
		GetNumber(fracStr, ampPos + 1, slashPos, numerator, tmpNegFlag) &&
		GetNumber(fracStr, slashPos + 1, string::npos, denominator, tmpNegFlag);
	}
    }
    else if (slashPos != string::npos) {
	// Found a '/', so must be just the fractional part
	status = GetNumber(fracStr, 0, slashPos, numerator, negFlag) &&
	    GetNumber(fracStr, slashPos + 1, string::npos, denominator, tmpNegFlag);
    }
    else {
	// Just a whole number
	status = GetNumber(fracStr, 0, string::npos, whole, negFlag);
    }

    if (status) {
	// Finally, only update ref param if everthing went okay
	result = Fraction(negFlag, whole, numerator, denominator);
    }
    return status;
}



/*
 * ParseExpr:
 *   We are called by ParseTerm() if it decides we have an arithmetic expr.
 *   It consumed the opening '(' in the look ahead to determine this.
 *   We parse contents of parenthesized expr, but leave the closing right-paren
 *   to caller to consume.
 *
 *   Note that the surrounding '('/')' has already been processed/will be
 *   processed by caller
 * Precondition:
 *   fracStr: the stringstream our input is being parsed from
 *
 * Postconditions:
 *   result: if success, contains the fraction that was calculated as the
 *     result of the requested operation, in NORMALIZED FORM;
 *     if error, "result" is NOT modified.
 *   Returns true if all went well, false if error.
 */
/*
 */
static bool ParseExpr(stringstream& strIn, Fraction& result) {
    string operatorStr, endParenStr;
    Fraction term1, term2, newTerm;
    bool status = true;  // Optimistic initial assumption

    // The first thing we see must be an operator
    strIn >> operatorStr;
    if (operatorStr.size() != 1) {
	cerr << "ERROR: \"" << operatorStr << "\": unknown operator\n";
	status = false;
    }
    else if (!ParseTerm(strIn, term1) || !ParseTerm(strIn, term2)) {
	status = false;
    } else {
	// NOTE: following implements applying the requested operator
	// to the given operands.  It does this by recursing to get values
	// of the two operands (done above) which might be complex terms,
	// and then using operator overloading to to allow Fractions to be
	// added, subtracted, etc. using the '+', '-', '*', and '/'
	// operators in the C++ code below:

	switch (operatorStr[0]) {
	case '+':
	    newTerm = term1 + term2;
	    break;
	case '-':
	    newTerm = term1 - term2;
	    break;
	case '*':
	    newTerm = term1 * term2;
	    break;
	case '/':
	    newTerm = term1 / term2;
	    break;
	default:
	    status = false;
	}
    }

    if (status) {
	result = newTerm;
    }
    return status;
}


/*
 * Show user approximately where error occurred in input stream
 */
static void ShowParseErrorPt(stringstream& strIn) {
    int errPt = static_cast<int>(strIn.tellg());

    cerr << "Problem detected at:\n" << strIn.str() << endl;
    for (int cnt = errPt - 1; cnt > 0; cnt--) {
	cerr << ' ';
    }
    cerr << "^\n";
}


/*
 * Note: parameters have different sense from string::substr(): we
 * use "end", which is position just beyond end of region of interest
 */
static bool GetNumber(string bufferStr, size_t start, size_t end, int& value,
    bool& negFlag) {
    string subStr;
    char *unused;

    // Don't use anonymous object here and call c_str() directly--
    // returned C-string will not be valid once anonymous object is reclaimed.
    size_t len = (end == string::npos ? end : end - start);
	subStr = bufferStr.substr(start, len);
    value = static_cast<int> (strtol(subStr.c_str(), &unused, 10));
    if (value < 0) {
	value = -value;  // no matter what, convert to positive
	if (!negFlag) {
	    cout << "Bad input: unexpected '-' sign; ignoring??\n";
	}
    }
    else {
	negFlag = false;
    }
    return unused == 0 || *unused == '\0';
}
