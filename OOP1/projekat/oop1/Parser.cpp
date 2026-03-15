#include "Parser.h"

vector<Command*> Parser::parse(const vector<Token>& tokens)
{
    vector<vector<Token>> groups = splitByPipe(tokens);
    return vector<Command*>();
}
// TODO prvi,posledji token ne moze biti pipe -> SyntaxError
// provera posle kreiranja komandi je l svaka osim prve ima inputStream i svaka osim poslednje ima outputStream ->SyntaxError
vector<vector<Token>> Parser::splitByPipe(const vector<Token>& tokens)
{
    for()
    return vector<vector<Token>>();
}
