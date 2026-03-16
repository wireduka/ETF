#include "Lexer.h"
#include "LexicalException.h"
//	Defined constaint of 512 characters
#define MAX 512

Lexer::Lexer(){}
vector<Token> Lexer::tokenize(const string& line){
	vector <Token> tokens;
	vector <int> errorMarkers;
	string current;
	string nline = (line.size() > MAX) ? line.substr(0, MAX) : line;
	// main loop
	for (int i = 0; i < nline.size(); i++) {
		char c = nline[i];
		// quotation subprogram
		if (isQuotationMark(c)) {
			i++; // skip opening " sign
			while ( i < nline.size() && nline[i] != '"') {
				current.push_back(nline[i]);
				i++;
			}
			if (i >= nline.size()) {
				throw LexicalException("Error - unenclosed quotation mark");
			}
			i++; // skip closing " sign
			tokens.push_back(setToken(current, true));
			current.clear();
			continue;
		}
		if (!isValidCharacter(c)) {
			errorMarkers.push_back(i);
		}
		if (isspace(c)) {
			if (!current.empty()) {
				tokens.push_back(setToken(current, false));
				current.clear();
			}
		}
		else
			current.push_back(c);
	}

	if (!current.empty()) {
		tokens.push_back(setToken(current, false));
	}
	if (!errorMarkers.empty()) throw LexicalException(nline, errorMarkers);

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
		|| character == '.';
}
bool Lexer::isQuotationMark(char character)
{
	return character == '"';
}

Token Lexer::setToken(string& word, bool isQuoted)
{
	Token temp;
	temp.value = word;
	if (isQuoted == true) temp.type = QUOTED_STRING;
	else if (word == "|") temp.type = PIPE;
	else if (word == "<") temp.type = REDIRECTION_IN;
	else if (word == ">") temp.type = REDIRECTION_OUT;
	else if (word == ">>") temp.type = REDIRECTION_APPEND;
	else temp.type = WORD;
	return temp;
}

string Lexer::tokenTypeToString(TokenType type)
{
	switch (type) {
	case TokenType::WORD: return "WORD"; break;
	case TokenType::PIPE: return "PIPE"; break;
	case TokenType::REDIRECTION_IN: return "REDIRECTION_IN"; break;
	case TokenType::REDIRECTION_OUT: return "REDIRECTION_OUT"; break;
	case TokenType::REDIRECTION_APPEND: return "REDIRECTION_APPEND"; break;
	case TokenType::QUOTED_STRING: return "QUOTED_STRING"; break;
	default: return "UNKNOWN"; break;
	}
	
}



