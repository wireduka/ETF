#ifndef ECHOCOMMAND_H
#define ECHOCOMMAND_H
#include "ICommand.h"
class EchoCommand : public Command {

	void validate(const vector<Token>& tokens) override;
	void execute(istream& in, ostream& out) override;
	
};
#endif