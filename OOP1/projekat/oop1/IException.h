#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
using namespace std;

class Exception{
public:
	Exception(const string& line, int errorPosition);
	virtual ~Exception() = default;

	virtual void callException() const = 0;
	

protected:
	string line;
	int errorPosition;
};

#endif