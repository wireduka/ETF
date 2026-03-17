#include "ICommand.h"
#include "SemanticException.h"
#include "FileFormatException.h"
#include <array>

using namespace std;

Command::Command(): hasOption(false), append(false){}
// Checks if command has both an argument and input redirection
void Command::validate(const vector<Token>& tokens)
{
	if (hasInput() && !tokens.empty() && !inputFile.empty()) {
		throw SemanticException("Error - cannot use both argument and input redirection");
	}
}

void Command::setInputFile(const string& filename){
	if (!inputFile.empty()) {
		throw SemanticException("Error - multiple input directions");
	}
	checkInputFile(filename);
	inputFile = filename;
}
void Command::setOutputFile(const string& filename, bool isAppend){
	if (!outputFile.empty()) {
		throw SemanticException("Error - multiple output directions");
	}
	outputFile = filename;
	if (isAppend)
		append = true;


}

void Command::setOption(const string& optionName)
{
	if (hasOption) {
		option = optionName;
	}
	else
		throw SemanticException("Error - command does not support options");
}

void Command::checkInputFile(const string& filename)
{
	bool valid = false;
	const int numOfExtensions = 3;
	const array<string, numOfExtensions> allowedExtensions = { ".txt",".csv",".log" };
	for (const string& extension : allowedExtensions) {
		if (filename.size() > extension.size() && filename.substr(filename.size() - extension.size()) == extension)
			valid = true;
	}
	if (!valid)
		throw FileFormatException("Error - invalid file format");
	
}


