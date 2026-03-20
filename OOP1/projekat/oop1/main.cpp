#include <string>
#include "Program.h"
#include <istream>

int main()
{
    Program* program = new Program(cin,cout);
    
    while (true) {
        cout << program->getPrompt() << " ";
        program->run();
    }
}



