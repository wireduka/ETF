#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Reader.h"
#include "Lexer.h"
#include "Parser.h"
using namespace std;

class Program {
public:
	Program(istream& input, ostream& output);
	~Program();

	virtual ifstream openInputFile(Command* command);
	virtual ofstream openOutputFile(Command* command);

	virtual stringstream consoleInput(Command* command);
	virtual Command* setPipe(vector<Command*> commands);
	virtual istream& setInput(vector<Command*> commands);
	virtual ostream& setOutput(Command* command);
	virtual void executePipe(vector<Command*> commands,istream& in, ostream& out);

	virtual void setPrompt(const string& newPrompt) { prompt = newPrompt; }
	virtual string getPrompt() { return prompt; }
	
	virtual void run();
	virtual void runBatch();
	

protected:
	istream& input;
	ostream& output;
	Reader* reader;
	Lexer* lexer;
	Parser* parser;
	string prompt;

	ifstream fin;
	stringstream stream;
	stringstream console;
	ofstream fout;
};
#endif

