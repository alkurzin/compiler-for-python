#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "listToken.h"
#include "TypeToken.h"
#include "Helper.h"
#include "scan.h"

extern int32_t yycolumno;

using namespace std;

class Lexer{
	private:
		vector<listToken> tokensList;
		FlexLexer *lex;
	public:
		Lexer() {
		    lex = new yyFlexLexer();
		}
		Lexer(ifstream *in) {
		    lex = new yyFlexLexer(*in, cout);
		}
		TypeToken defineTypeToken(int intTokenType);
		void identification_token();
		void lexer(char **argv);
		void printToken(vector<listToken> token, char **argv);
};
