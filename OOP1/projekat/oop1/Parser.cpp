#include "Parser.h"
#include "SyntaxException.h"
vector<Command*> Parser::parse(const vector<Token>& tokens)
{
    vector<vector<Token>> groups = splitByPipe(tokens);
    return vector<Command*>();
}

// TODO provera posle kreiranja komandi je l svaka osim prve ima inputStream i svaka osim poslednje ima outputStream ->SyntaxError
// TODO uzimanje redirectiona i njihovo postavljanje
vector<vector<Token>> Parser::splitByPipe(const vector<Token>& tokens)
{
	vector<vector<Token>> groups;
	vector<Token> currentGroup;
	for (Token token : tokens) {
		if (tokens.front().type == PIPE)
			throw SyntaxException("Error - pipe cannot be at start of command line");
		if (tokens.back().type == PIPE)
			throw SyntaxException("Error - pipe cannot be at end of command line");

		if (token.type == PIPE) {
			if (currentGroup.empty()) {
				throw SyntaxException("Error - unexpected pipe");
			}
			groups.push_back(currentGroup);
			currentGroup.clear();
		}
		else {
			currentGroup.push_back(token);
		}
	}
	
   return groups;
}
