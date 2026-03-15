#ifndef LEXICALEXCEPTION_H
#define LEXICALEXCEPTION_H
#include "IException.h"
#include <vector>

class LexicalException : public Exception {
public:
	LexicalException(const string& line, vector<int>& const errorPosition);
	LexicalException(const string& message);

	virtual void print() const override;
private:

	string line;
	vector<int> errorPositions;
	string message;
};

#endif