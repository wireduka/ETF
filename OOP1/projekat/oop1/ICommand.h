#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <istream>
#include "Lexer.h"
using namespace std;

//	Base command class
class Command {
public:
	Command();
	virtual ~Command() = default;

	virtual void execute(istream& in, ostream& out) = 0;

	// Validates syntax and semantics of command
	virtual void validate(const vector<Token>& tokens);

	virtual bool hasInput() const { return true; }
	virtual bool hasOutput() const { return true; }
	


	virtual void setInputFile(const string& filename);
	virtual void setOutputFile(const string& filename, bool isAppend);
	virtual void setOption(const string& optionName);
	

	virtual bool isAppend() const { return append; }
	virtual void checkInputFile(const string& filename);

	virtual string getInputFile() const { return inputFile; }
	virtual string getOutputFile() const { return outputFile; }
	virtual string getArgument() const { return argument; }



protected:

	string argument;
	string option;
	string inputFile;
	string outputFile;
	bool hasOption;
	bool append;
};
#endif