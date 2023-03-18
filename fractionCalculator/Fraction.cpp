//File: Fraction.cpp
//
//Implementation of the Fraction class.
//


#include <iostream>
#include "Fraction.h"

Fraction::Fraction(){
	m_nume = 0;
	m_denom = 1;
	m_whole = 0;
	m_sign = false;

}
Fraction::Fraction(bool negFlag, int whole, int numerator, int denominator){
	if (denominator==0)
	{
		cout<<"cannot divide by zero";
		exit(1);
	}
	else{
		m_nume = numerator;
		m_denom = denominator;
		m_whole = whole;
		m_sign = negFlag;
	}	

}
bool Fraction::GetSign() const{
	return m_sign;
}

int Fraction::GetNumerator() const{
	return m_nume;
}

int Fraction::GetDenominator() const{
	return m_denom;
}

int Fraction::GetWhole() const{
	return m_whole;
}


const Fraction Fraction::operator* (const Fraction& rhs) const{
	int WholetoFrac1 = m_denom * m_whole;
	int NewNume1 = WholetoFrac1 + m_nume;
	int WholetoFrac2 = rhs.m_denom * rhs.m_whole;
	int NewNume2 = WholetoFrac2 + rhs.m_nume;



	int MultNume = NewNume1 * NewNume2;
	int MultDenom = m_denom * rhs.m_denom;
	int NewWhole = MultNume / MultDenom;
	int NewNume = MultNume - (NewWhole*MultDenom);
	bool newNegFlag;

	if (NewNume == 0){
		MultDenom = 1;
	}

	if (m_sign == true && rhs.m_sign==true)
	{
		newNegFlag = false;
	}
	else if (m_sign == true || rhs.m_sign == true)
	{
		newNegFlag = true;
	}
	else 
	{
		newNegFlag = false;

	}
	Fraction newMultObject(newNegFlag, NewWhole, NewNume, MultDenom);
	return newMultObject;

}

const Fraction Fraction::operator/ (const Fraction& rhs) const{

	int WholetoFrac1 = m_denom * m_whole;
	int NewNume1 = WholetoFrac1 + m_nume;
	int WholetoFrac2 = rhs.m_denom * rhs.m_whole;
	int NewNume2 = WholetoFrac2 + rhs.m_nume;
	int MultNewNume = NewNume1 *rhs.m_denom;
	int MultNewDenom = m_denom * NewNume2;
	int NewWhole = MultNewNume / MultNewDenom;
	int NewNume = MultNewNume - (NewWhole*MultNewDenom);
	bool newNegFlag;

	for (int i = NewNume*MultNewDenom; i >= 1; --i)
	{
		if (MultNewDenom % i == 0 && NewNume % i == 0){
			NewNume = NewNume / i;
			MultNewDenom = MultNewDenom / i;
			i=0;
		}
	}
	if ( NewNume == 0){
		MultNewDenom = 1;
	}

	if (m_sign == true && rhs.m_sign==true)
	{
		newNegFlag = false;
	}
	else if (m_sign == true || rhs.m_sign == true)
	{
		newNegFlag = true;
	}
	else 
	{
		newNegFlag = false;

	}
	Fraction newMultObject(newNegFlag, NewWhole, NewNume, MultNewDenom);
	return newMultObject;

}

const Fraction Fraction::operator+ (const Fraction& rhs) const{

	int NewDenom = m_denom * rhs.m_denom;
	int NewRhsNume = m_denom * rhs.m_nume;
	int NewNume = rhs.m_denom * m_nume;

	int AddNume,NewWhole, AddNewWhole,AddNewNume;
	bool newNegFlag=false;
	if (m_sign == true && rhs.m_sign == true){


	AddNume = NewNume + NewRhsNume;

	NewWhole = AddNume / NewDenom;
	AddNewWhole = NewWhole + rhs.m_whole + m_whole;
	AddNewNume = AddNume - (NewWhole*NewDenom);
	newNegFlag = true;

	}
	else if (m_sign == true){
		AddNume = NewRhsNume - NewNume;

		NewWhole = abs(AddNume) / NewDenom;
		if (AddNume > 0){
			AddNewWhole = NewWhole + rhs.m_whole - m_whole;
		}
		else{
			AddNume = abs(AddNume);
			AddNewWhole = rhs.m_whole - m_whole - NewWhole;
			if( AddNewWhole > 0){
				newNegFlag = false;
				AddNewWhole = abs(AddNewWhole);
			}

		}
		AddNewNume = AddNume - (NewWhole*NewDenom);
		}
	else if(rhs.m_sign == true){
		AddNume = NewNume - NewRhsNume;

		NewWhole = abs(AddNume) / NewDenom;
		if (AddNume > 0){
			AddNewWhole = NewWhole - rhs.m_whole + m_whole;
		}
		else{
			AddNume = abs(AddNume);
			AddNewWhole = -rhs.m_whole + m_whole - NewWhole;
			if( AddNewWhole < 0){
				newNegFlag = true;
				AddNewWhole = abs(AddNewWhole);
			}

		}
		AddNewNume = AddNume - (NewWhole*NewDenom);
		}
	
	else{
	AddNume = NewNume + NewRhsNume;
	NewWhole = AddNume / NewDenom;
	AddNewWhole = NewWhole + rhs.m_whole + m_whole;
	AddNewNume = AddNume - (NewWhole*NewDenom);
	newNegFlag = false;
	}

	for (int i = AddNewNume*NewDenom; i >= 1; --i)
	{
	if (NewDenom % i == 0 && AddNewNume % i == 0){
		AddNewNume = AddNewNume / i;
		NewDenom = NewDenom / i;
		i=0;

		}
	}
	if (AddNewNume == 0){
		NewDenom=1;
	}
	if (AddNewWhole == 0 && AddNewNume == 0){
		newNegFlag = false;
	}
	Fraction newAddObject(newNegFlag, AddNewWhole, AddNewNume, NewDenom);
	return newAddObject;




}

const Fraction Fraction::operator- (const Fraction& rhs) const{

	int NewDenom = m_denom * rhs.m_denom;
	int NewRhsNume = m_denom * rhs.m_nume;
	int NewNume = rhs.m_denom * m_nume;

	int SubNume,NewWhole, SubNewWhole,SubNewNume;
	bool newNegFlag;
	if (m_sign == true && rhs.m_sign == true){


		SubNume = -NewNume + NewRhsNume;

		NewWhole = abs(SubNume) / NewDenom;
		if (SubNume > 0){
		SubNewWhole = NewWhole + rhs.m_whole - m_whole;

		}
		else{
			SubNewWhole = rhs.m_whole - NewWhole -m_whole;
			SubNume = abs(SubNume);
		}

		SubNewNume = SubNume - (NewWhole*NewDenom);
			if(SubNewWhole > 0){
			newNegFlag = false;
			}
			else{
				newNegFlag = true;
			}
		}
	else if (m_sign == true){
		SubNume = NewRhsNume + NewNume;
		NewWhole = SubNume / NewDenom;
		SubNewWhole = NewWhole + rhs.m_whole + m_whole;
		SubNewNume = SubNume - (NewWhole*NewDenom);
		newNegFlag = true;
	}
	else if(rhs.m_sign == true){
	SubNume = NewNume + NewRhsNume;
	NewWhole = SubNume / NewDenom;
	SubNewWhole = NewWhole + rhs.m_whole + m_whole;
	SubNewNume = SubNume - (NewWhole*NewDenom);
	newNegFlag = false;
	}

	else{
		SubNume = NewNume - NewRhsNume;

		NewWhole = abs(SubNume) / NewDenom;
		if (SubNume >= 0){
		SubNewWhole = NewWhole - rhs.m_whole + m_whole;

		}
		else{
			SubNewWhole = -rhs.m_whole - NewWhole + m_whole;
			SubNume = abs(SubNume);
		}

		SubNewNume = SubNume - (NewWhole*NewDenom);
			if(SubNewWhole > 0){
			newNegFlag = false;
			}
			else{
				SubNewWhole = abs(SubNewWhole);
				newNegFlag = true;
			}
		}
	



	for (int i = SubNewNume*NewDenom; i >= 1; --i)
	{
	if (NewDenom % i == 0 && SubNewNume % i == 0){
		SubNewNume = SubNewNume / i;
		NewDenom = NewDenom / i;
		i=0;

		}
	}
	if (SubNewNume == 0 && SubNewWhole == 0){
		newNegFlag = false;
	}
	if (SubNewNume == 0){
		NewDenom=1;
	}
	Fraction newSubObject(newNegFlag, SubNewWhole, SubNewNume, NewDenom);
	return newSubObject;




}

ostream& operator << (ostream& out, const Fraction& number){

  if(number.GetSign() == true){
    out<<"-"<<number.GetWhole()<<"&"<<number.GetNumerator()<<"/"<<number.GetDenominator();
  }
  else{
    out<<number.GetWhole()<<"&"<<number.GetNumerator()<<"/"<<number.GetDenominator();
  }

  return out;

}
