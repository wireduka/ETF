#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
using namespace std;

class Lexer {
public:
	Lexer();
	vector<string> tokenize(const string& line);

	bool isValidCharacter(char character);
private:
	string line;
	bool hasError = false;
};

#endif