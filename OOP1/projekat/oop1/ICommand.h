#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <istream>
using namespace std;
class Command {
public:
	virtual void execute(istream& in, istream& out) = 0;
	virtual void validate() = 0;

	virtual bool hasInput() const { return true; }
	virtual bool hasOutput() const { return true; }
	virtual bool hasOption() const { return false; }
protected:
	string inputFile;
	string outputFle;
	bool appendOutput;
};
#endif