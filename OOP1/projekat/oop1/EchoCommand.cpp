#include "EchoCommand.h"
#include "SemanticException.h"
#include <iostream>
void EchoCommand::validate(const vector<Token>& tokens){
	Command::validate(tokens);
	if (tokens.size() > 1)
		throw SemanticException("Error - too many arguments for echo command");
	if (inputFile.empty()) {
		if (tokens.empty()) {
			return;
		}
		else if (tokens[0].type == QUOTED_STRING) {
			argument = tokens[0].value;
		}
		else if (tokens[0].type == WORD) {
			checkInputFile(tokens[0].value);
			inputFile = tokens[0].value;
		}
	}
}

void EchoCommand::execute(istream& in, ostream& out)
{
	char c;
	while (in.get(c)) {
		out.put(c);
	}
}
