#include <string>
#include "Program.h"
#include <istream>

int main()
{
    Program* program = new Program(cin);
    program->run();
}




