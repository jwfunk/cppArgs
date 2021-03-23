//
//cppArgs.cpp
//
#include "cppArgs.h"
#include <iostream>


void cppArgs::input(int argc, char** argv) {
	int noNames = 0;
	for(int i = 0; i < argc; ++i) {
		std::string s(argv[i]);
		if(s[0] == '-') {
			++i;
			if(i == argc) {
				std::cout << "No arg given for " << s << "\n";
				break;
			}
			std::string v(argv[i]);
			bool found = false;
			for(auto it = args.begin(); it != args.end(); ++it) {
				if(std::get<0>(*it) == s) {
					found = true;
					*it = std::make_tuple( std::get<0>(*it), std::get<1>(*it), v);
				}
			}
			if(!found) 
				std::cout << "No arg named " << s << "\n";
		}
		else {
			if(std::get<0>(args[noNames]) == "") {
				args[noNames] = std::make_tuple( "", std::get<1>(args[noNames]), s);
				++noNames;
			}
		}
	}
	for( auto it = args.begin(); it != args.end(); ++it) {
		if(std::get<1>(*it) == 'r' && std::get<2>(*it) == "") {
			if(std::get<0>(*it) == "") {
				std::cout << "Not enough args\n";
			}
			else {
				std::cout << "Missing " << std::get<0>(*it) << "\n";
			}
			exit(1);
		}
	}
}

std::string cppArgs::get(int i) {
	return std::get<2>(args[i]);
}

std::string cppArgs::get(std::string key) {
	for( auto it = args.begin(); it != args.end(); ++it){
		if( std::get<0>(*it) == key)
			return std::get<2>(*it);
	}
	return "";
}

//	std::vector<std::pair<std::string,char> > args;

