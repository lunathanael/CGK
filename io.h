#ifndef IO_H
#define IO_H


#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split_command(const string& command)
{

	stringstream stream(command);
	string intermediate;
	vector<string> tokens;

	while (getline(stream, intermediate, ' '))
	{
		tokens.push_back(intermediate);
	}

	return tokens;
}


#endif