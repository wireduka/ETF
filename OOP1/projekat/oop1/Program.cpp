#include "Program.h"
#include "Reader.h"
#include "Lexer.h"
#include "LexicalException.h"
Program::Program(istream& input) : input(input), prompt("$")
{
	reader = new Reader(input);
	lexer = new Lexer();
	parser = new Parser();
	
}

Program::~Program()
{
	delete reader;
	delete lexer;
	delete parser;
}

void Program::run()
{
	while (true) {
		cout << prompt;
		string line = reader->getLine();
		try {
			vector<Token> tokens = lexer->tokenize(line);
			// TEMP for debugging
			for (const Token& token : tokens) {
				cout << '|' << lexer->tokenTypeToString(token.type) << ", " << token.value;
			}
			cout << "\n";
		}

		catch (const LexicalException& e) {
			e.print();
		}
	}
}
