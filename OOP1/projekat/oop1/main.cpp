#include <iostream>
#include <string>
#include "Lexer.h"
#include "Reader.h"
#include "ConsoleReader.h"
#include "LexicalException.h"
using namespace std;
int main()
{
    Reader* reader = new ConsoleReader();
    Lexer* lexer = new Lexer();
    while (true) {
        cout << "$ ";
        string line = reader->getLine();
        try {
            vector<string> tokens = lexer->tokenize(line);
            for (const string& token : tokens) {
                cout << token << " ";
            }
            cout << "\n";
        }
        catch (const LexicalException& e) {
            e.callException();
		}

    }
    
	delete reader;
	delete lexer;
}




