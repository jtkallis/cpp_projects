#include "Proj5Aux.h"

int main(int argc, char *argv[]) {
    bool doExit;
    DocumentStore docStore;

    do {
	doExit = DoOneCommand(docStore);
    } while (!doExit);
}
