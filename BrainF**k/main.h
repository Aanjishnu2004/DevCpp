#include <iostream>
#include <vector>
#include <fstream>

namespace BrainF
{
	std::string prog ;  
	
	void _init_(const char* fname);
	
	void interpret();
	
	void panic(const char* s);
}
