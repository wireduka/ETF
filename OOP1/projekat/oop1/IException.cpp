#include "IException.h"

Exception::Exception(const string& line, int errorPosition) : line(line), errorPosition(errorPosition)
{} 
