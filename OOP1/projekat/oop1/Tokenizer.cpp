#include "Tokenizer.h"
//	Defined constaint of 512 characters
#define MAX 512

Tokenizer::Tokenizer(){}

vector<string> Tokenizer::tokenize(const string& line){
	vector <string> tokens;
	string current;
	int count = 0;
	for (char c : line) {
		if (isspace(c)) {
			if (!current.empty()) {
				tokens.push_back(current);
				current.clear();
			}
		}
		else
			current.push_back(c);

		count++;
		//	If the specified 512 character limit is breached or the character "\n" is detected-> do not tokenize
		if (count == MAX || current == "\n") break;
	}
	if (!current.empty()) {
		tokens.push_back(current);
	}
	return tokens;
	

}
