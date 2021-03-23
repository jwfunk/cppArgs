//
//cppArgs.h
//
//Header file for cppArgs class
#ifndef CPPARGS
#define CPPARGS

#include <string>
#include <vector>
#include <tuple>

class cppArgs {

	public:

	cppArgs(std::vector<std::tuple<std::string,char,std::string> > a): args(a) {}

	void input(int, char**);
	std::string get(int);
	std::string get(std::string);
	private:

	std::vector<std::tuple<std::string,char,std::string> > args;
};

#endif
