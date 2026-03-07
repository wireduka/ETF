#ifndef READER_H
#define READER_H

#include <string>
#include <istream>
using namespace std;

class Reader {
public:
	Reader(istream* input);
	virtual ~Reader() {}

	string getLine();
	bool isEof();

protected:
	istream* input;
};

















#endif
