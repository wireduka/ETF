#include "WcCommand.h"
#include "SemanticException.h"

void WcCommand::validate(const vector<Token>& tokens){
	Command::validate(tokens);

	//	Add options here
	options.push_back("-w");
	options.push_back("-c");

	if (tokens.size() > 1)
		throw SemanticException("Error - too many arguments for wc command");

	if (option.empty())
		throw SemanticException("Error - command must have an option");
	checkOption();

	if (inputFile.empty()) {
		if (tokens.empty()) {
			return;
		}
		else if (tokens[0].type == QUOTED_STRING) {
			argument = tokens[0].value;
		}
		else if (tokens[0].type == WORD) {
			checkFile(tokens[0].value);
			inputFile = tokens[0].value;
		}
	}
	
}

void WcCommand::execute(istream& in, ostream& out)
{
	int count = 0;
	if (option == "-c") {
		char c;
		while (in.get(c))
			count++;
		out << count;
		
			
	}
}
