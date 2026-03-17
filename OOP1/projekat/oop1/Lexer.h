#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
using namespace std;

enum TokenType {
	WORD,
	QUOTED_STRING,
	REDIRECTION_IN,
	REDIRECTION_OUT,
	REDIRECTION_APPEND,
	PIPE
};

struct Token {
	TokenType type = WORD;
	string value;
};

class Lexer {
public:
	Lexer();
	//	Tokenizes reader output into seperate tokens
	vector<Token> tokenize(const string& line);

	bool isValidCharacter(char character);
	bool isQuotationMark(char character);
	//	Maps the token into the adequate enum member
	Token setToken(string& word,bool isQuoted);
	string tokenTypeToString(TokenType type);


private:

};

#endif