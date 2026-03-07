#include "Lexer.h"
#include "LexicalException.h"
//	Defined constaint of 512 characters
#define MAX 512

Lexer::Lexer(){}
// TODO rewrite
vector<string> Lexer::tokenize(const string& line){
	vector <string> tokens;
	string current;
	int charCount = 0;
	for (char c : line) {
		if (!isValidCharacter(c)) {
			throw LexicalException(line, charCount);
		}
		if (isspace(c)) {
			if (!current.empty()) {
				tokens.push_back(current);
				current.clear();
			}
		}
		else
			current.push_back(c);

		charCount++;
		//	If the specified 512 character limit is breached or the character "\n" is detected -> do not tokenize
		if (charCount == MAX || current == "\n") break;
	}
	if (!current.empty()) {
		tokens.push_back(current);
	}
	return tokens;
	

}

bool Lexer::isValidCharacter(char character)
{
	return isalnum(character)
		|| isspace(character)
		|| character == '-'
		|| character == '|'
		|| character == '<'
		|| character == '>'
		|| character == '"';
}
// poseban rezim rada za ""
