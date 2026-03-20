#include "BatchCommand.h"
#include "SemanticException.h"

void BatchCommand::validate(const vector<Token>& tokens)
{
	Command::validate(tokens);
	if (tokens.size() > 1)
		throw SemanticException("Error -command does not support multiple arguments");
	if (!tokens.empty()) {
		if (tokens[0].type == WORD) {
			checkFile(tokens[0].value);
			argument = tokens[0].value;
		}
		else {
			throw SemanticException("Error - argument must be a filename");
		}
	}
	
}

void BatchCommand::execute(istream& in, ostream& out)
{
	if (!argument.empty()) {
		ifstream file(argument);
		if (!file.is_open())
			throw SemanticException("Error - file does not exist");
		Program program(file,out);
		program.runBatch();
	}
	else {
		Program program(in,out);
		program.runBatch();
	}
}
