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
	parser = new Parser(*this);
	
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
	if (command->hasInput() && command->getArgument().empty() && command->getInputFile().empty()) {
		string line;
		while (getline(cin, line))
			console << line << "\n";
	}
	string content = console.str();
	if (command->trailingNewLine()) {
		if (!content.empty() && content.back() == '\n')
			content.pop_back();
		console.str(content);
		console.clear();
	}

	return console;
}

void Program::run()
{

	while (true) {
		cout << prompt << " ";
		try {
			string line = reader->getLine();
			reader->isEof();

			vector<Token> tokens = lexer->tokenize(line);
			vector<Command*> commands = parser->parse(tokens);
			
			Command* cmd;
			if (parser->getPipe())
				cmd = commands.back();
			else
				cmd = commands.front(); 
			ifstream fin = openInputFile(commands.front());
			ofstream fout;

			fout = openOutputFile(cmd); 

			stringstream stream(commands.front()->getArgument());
			stringstream console = consoleInput(commands.front());

			cin.clear();
			
			istream& in = (!commands.front()->getArgument().empty() ? (istream&)stream
				: !commands.front()->getInputFile().empty() ? (istream&)fin
				: (istream&)console);

			ostream& out = (!cmd->getOutputFile().empty() ? (ostream&)fout : cout);

			if (parser->getPipe()) {
				stringstream pipeStream;
				commands.front()->execute(in, pipeStream);
				for (int i = 1; i < commands.size() - 1; i++) {

					stringstream nextStream;
					commands[i]->execute(pipeStream, nextStream);
					pipeStream.str(nextStream.str());
					pipeStream.clear();
				}
				commands.back()->execute(pipeStream, out);
			}
			else {

				cmd->execute(in, out);

			}
			if (cmd->getOutputFile().empty() && cmd->hasOutput())
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
