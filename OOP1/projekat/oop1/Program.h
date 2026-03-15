#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <string.h>
#include "Reader.h"
#include "Lexer.h"
#include "Parser.h"
using namespace std;

class Program {
public:
	Program(istream& input);
	~Program();
	virtual void run();
	

private:
	istream& input;

	Reader* reader;
	Lexer* lexer;
	Parser* parser;

	string prompt;

};


#endif