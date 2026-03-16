#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include "ICommand.h"
#include "Lexer.h"

class Parser {
public:
	Parser() = default;
	~Parser() = default;
	vector <Command*> parse(const vector <Token>& tokens);
	vector <vector<Token>> splitByPipe(const vector <Token>& tokens);
};
#endif