#include <iostream>
#include <fstream>
#include "lib/lexer.h"

int main(int argc, char** argv){
	ifstream* file = new ifstream(argv[1]);
    if (!file->is_open()) {
        cerr << "I can not open file. Sorry." << endl;
        return -1;
    }

	Lexer l(file);
	l.lexer(argv); 


	return 0;
}