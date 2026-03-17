#include "Program.h"
#include "Reader.h"
#include "Lexer.h"
#include "LexicalException.h"
#include "SyntaxException.h"
#include "SemanticException.h"
#include "ICommand.h"
#include "FileFormatException.h"
#include <fstream>
#include <sstream>

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

ifstream Program::openInputFile(Command* command)
{
	ifstream fin;
	if (!command->getInputFile().empty()) {
		fin.open(command->getInputFile());
		if (!fin.is_open())
			throw SemanticException("Error - file does not exist");
	}
	return fin;
}

ofstream Program::openOutputFile(Command* command){

	ofstream fout;
	if (!command->getOutputFile().empty()) {
		fout.open(command->getOutputFile(), command->isAppend() ? ios::app : ios::trunc);
	}
	return fout;
}

stringstream Program::consoleInput(Command* command)
{
	stringstream console;
	if (command->getArgument().empty() && command->getInputFile().empty()) {
		string line;
		while (getline(cin, line))
			console << line << "\n";
	}
	string content = console.str();
	if (!content.empty() && content.back() == '\n')
		content.pop_back();
	console.str(content);
	console.clear();
	return console;
}

void Program::run()
{

	while (true) {
		cout << prompt;
		try {
			string line = reader->getLine();
			reader->isEof();

			vector<Token> tokens = lexer->tokenize(line);
			vector<Command*> commands = parser->parse(tokens);
			if(commands.empty()) throw SyntaxException("");
			
			Command* cmd = commands[0]; //TEMP
			ifstream fin = openInputFile(cmd);
			ofstream fout = openOutputFile(cmd);
			stringstream stream(cmd->getArgument());
			stringstream console = consoleInput(cmd);
			cin.clear();
			
			istream& in = (!cmd->getArgument().empty() ? (istream&)stream : !cmd->getInputFile().empty() ? (istream&)fin : console);
			ostream& out = (!cmd->getOutputFile().empty() ? (ostream&)fout : cout);

			cmd->execute(in, out);
			if (cmd->getOutputFile().empty())
				cout << "\n";
		}
		catch (const LexicalException& e) {
			e.print();
		}
		catch (const SyntaxException& e) {
			e.print();
		}
		catch (const SemanticException& e) {
			e.print();
		}
		catch (const FileFormatException& e) {
			e.print();
		}

	}
}
