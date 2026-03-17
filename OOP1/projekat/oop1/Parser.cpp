#include "Parser.h"
#include "SyntaxException.h"
#include "SemanticException.h"
#include "EchoCommand.h"


vector<Command*> Parser::parse(const vector<Token>& tokens)
{
	if (tokens.empty()) throw SyntaxException("Error - empty command line");
    vector<vector<Token>> groups = splitByPipe(tokens);
	vector<Command*> commands;
	//	Creates command using the first element of each group, and sets the option flag using the second element of each group, aswell as sets redirections using the last 2 elements
	//	Afterward, deletes the group elements that have already fulfilled their purpose, to make parsing the command simpler
	for (vector<Token> group : groups) {
		Command* cmd = createCommand(group[0].value);
		group.erase(group.begin());
		if (!group.empty() && group[0].value.front() == '-' && group[0].type == WORD) {
			cmd->setOption(group[0].value);
			group.erase(group.begin());
		}

		group = setRedirections(group, cmd);
		cmd->validate(group);
		commands.push_back(cmd);
	}

	
    return commands;
}

vector<vector<Token>> Parser::splitByPipe(const vector<Token>& tokens)
{
	vector<vector<Token>> groups;
	vector<Token> currentGroup;

	if (tokens.front().type == PIPE)
		throw SyntaxException("Error - pipe cannot be at start of command line");
	if (tokens.back().type == PIPE)
		throw SyntaxException("Error - pipe cannot be at end of command line");

	for (Token token : tokens) {
		if (token.type == PIPE) {
			if (currentGroup.empty()) {
				throw SyntaxException("Error - unexpected pipe");
			}
			groups.push_back(currentGroup);
			currentGroup.clear();
		}
		else {
			currentGroup.push_back(token);
		}
	}
	if (!currentGroup.empty()) {
		groups.push_back(currentGroup);
	}
	
   return groups;
}

Command* Parser::createCommand(const string& name)
{
	if (name == "echo") return new EchoCommand();
	else throw SyntaxException("Error - unknown command");
	
}

vector <Token> Parser::setRedirections(vector<Token> group, Command* command)
{
	if (!group.empty() && group.back().type == REDIRECTION_IN ||
		!group.empty() && group.back().type == REDIRECTION_OUT ||
		!group.empty() && group.back().type == REDIRECTION_APPEND)
		throw SemanticException("Error - redirection must have a stream");
	while (group.size() >= 2) {
		TokenType type = group[group.size() - 2].type;
		string filename = group.back().value;
		if (type != REDIRECTION_IN && type != REDIRECTION_OUT && type != REDIRECTION_APPEND)
			break;
		if (type == REDIRECTION_IN)
			if (command->hasInput()) {
				command->setInputFile(filename);
			}
			else
				throw SemanticException("Error - command does not support an input stream");
		else if (type == REDIRECTION_OUT)
			if (command->hasOutput()) {
				command->setOutputFile(filename, false);
			}
			else
				throw SemanticException("Error - command does not support an output stream");
		else if (type == REDIRECTION_APPEND)
			if (command->hasOutput()) {
				command->setOutputFile(filename, true);
			}
			else
				throw SemanticException("Error - command does not support an output stream");

		group.pop_back();
		group.pop_back();
	}
	for (const Token& token : group) {
		if (token.type == REDIRECTION_IN || token.type == REDIRECTION_OUT || token.type == REDIRECTION_APPEND)
			throw SemanticException("Error -  redirection must be at end of command");
	}


	return group;
}


