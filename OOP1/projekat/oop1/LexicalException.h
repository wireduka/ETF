#ifndef LEXICALEXCEPTION_H
#define LEXICALEXCEPTION_H
#include "IException.h"

class LexicalException : public Exception {
public:
	LexicalException(const string& line, int errorPosition) : Exception(line, errorPosition) {}

	virtual void callException() const override;
	
};

#endif