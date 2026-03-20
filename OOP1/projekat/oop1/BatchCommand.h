#ifndef BATCHCOMMAND_H
#define BATCHCOMMAND_H
#include "ICommand.h"
#include "Program.h"
class BatchCommand : public Command {

	void validate(const vector<Token>& tokens) override;
	void execute(istream& in, ostream& out) override;




};
#endif