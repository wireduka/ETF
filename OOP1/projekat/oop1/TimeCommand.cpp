#include "TimeCommand.h"
#include "SemanticException.h"
#include <ctime>
void TimeCommand::validate(const vector<Token>& tokens)
{
	if (!tokens.empty()) {
		throw SemanticException("Error - time does not support arguments");
	}
}

void TimeCommand::execute(istream& in, ostream& out)
{
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);
	out << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec;
}
