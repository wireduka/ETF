#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>
using namespace std;

class Tokenizer {
public:
	Tokenizer();
	vector<string> tokenize(const string& line);
private:
	string line;

};

#endif