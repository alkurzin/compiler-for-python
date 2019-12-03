#include "lexer.h"

TypeToken Lexer::defineTypeToken(int intTokenType) {
    TypeToken typeToken = TypeToken(intTokenType);
    return typeToken;
}

void Lexer::identification_token(){
    int tokenType = lex->yylex();
    while (tokenType) {
        string lexem = lex->YYText();

        listToken token(lexem, defineTypeToken(tokenType), yycolumno - lexem.size() + 1, lex->lineno());
        tokensList.push_back(token);

        tokenType = lex->yylex();

        if (tokenType == TypeToken(UNKNOWN)) {
            cerr << "Lexer error: UNKNOWN lexem: " << lexem  << lex->YYText() << endl;
            return;
        }
    }
}

void Lexer::lexer(char **argv){
	identification_token();
	printToken(tokensList, argv);
}

void Lexer::printToken(vector<listToken> token, char **argv){
	for (int i = 0; i < token.size(); ++i){
		TypeToken tmp = token[i].get_type();
		cout << Helper::enumToString(tmp) << " '" << token[i].get_name() << "' " << "Loc=<" << argv[1] << ":" << token[i].get_y() << ":" << token[i].get_x() << ">" << endl;
	}
}