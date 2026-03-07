#include <iostream>
#include <string>
#include "Tokenizer.h"
#include "Reader.h"
#include "ConsoleReader.h"
using namespace std;
int main()
{
    Reader* reader = new ConsoleReader();
    Tokenizer* tokenizer = new Tokenizer();
    while (true) {
        cout << "$";
        string line = reader->getLine();
        vector<string> tokens = tokenizer->tokenize(line);
        for (const string& token : tokens) {
            cout << token << " ";
        }
        cout << "\n";
    }
    

}




