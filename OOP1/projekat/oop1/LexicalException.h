#ifndef LEXICALEXCEPTION_H
#define LEXICALEXCEPTION_H
#include "IException.h"
#include <vector>

class LexicalException : public Exception {
public:
	LexicalException(const string& line, const vector<int>& errorPosition);
	LexicalException(const string& message);

	void print() const override;
private:

	string line;
	vector<int> errorPositions;
	string message;
};

#endif