#include "DateCommand.h"
#include "SemanticException.h"
#include <ctime>
void DateCommand::validate(const vector<Token>& tokens)
{
	if (!tokens.empty())
		throw SemanticException("Error - command does not support arguments");
}

void DateCommand::execute(istream& in, ostream& out)
{
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);
	out << localTime->tm_mday << "." << localTime->tm_mon + 1 << "." << localTime->tm_year + 1900;
}
