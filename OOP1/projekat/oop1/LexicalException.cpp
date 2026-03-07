#include "LexicalException.h"
#include <string>
#include <iostream>
using namespace std;
void LexicalException::callException() const
{
	// TODO dodaj implementaciju za vise markera, odnosno da pokaze sve leksicke greske
	cout << endl;
	cout << "Error - unexpected characters:" << endl;
	cout << line << endl;
	string marker(line.size(), ' ');
	marker[errorPosition] = '^';
	cout << marker << endl;


}