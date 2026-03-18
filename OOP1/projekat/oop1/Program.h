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
	ifstream openInputFile(Command* command);
	ofstream openOutputFile(Command* command);
	stringstream consoleInput(Command* command);
	string setPrompt(const string& newPrompt) { return prompt = newPrompt; }
	virtual void run();
	

private:
	istream& input;
	Reader* reader;
	Lexer* lexer;
	Parser* parser;
	string prompt;
};
#endif