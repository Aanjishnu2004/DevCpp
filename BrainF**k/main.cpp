/*
	This a BrainFuck Interpreter written in c++
	@Author: Aanjishnu Bhattacharyya
	@version: 1.0.0
	@date: 9th June 2020
*/

#include "main.h"

// reads in a file and stores it in a string prog
void BrainF::_init_(const char* c)
{
	std::ifstream read(c , std::ios::in);
	if(!read.good()) BrainF::panic("File not found or some error with file!!");
	
	read.seekg(0 , std::ios::beg);
	BrainF::prog = "";
	
	while(!read.eof())
	{
		std::string s ;
		read >> s; 
		BrainF::prog+=s;
	}
	read.close();
}

void BrainF::interpret()
{
	std::vector<unsigned char> mem ;
	mem.push_back(0); 
	int p = 0 ;
	
	for(int i = 0; i < prog.length() ; i++)
	{
		if(prog[i] == '+') mem[p]++; // Adds one to the current pointer
		else if(prog[i] == '-') mem[p]--; // Subtracts one from the current pointer
		else if(prog[i] == '.') std::cout << mem[p]; // Prints ASCII to the screen
		else if(prog[i] == ',') std::cin >> mem[p]; // Accepts input from user
		else if(prog[i] == '>') {p++;mem.push_back(0);} // moves pointer to the right
		else if(prog[i] == '<') {p--;if(p<0) panic("WTF!!");} // moves pointer to the left
		else if(prog[i] == '[' && !mem[p]) // loop start in BrainF
		{
			int open = 0;
			while(open)
			{
				i++;
				if(prog[i] == '[') open++;
				if(prog[i] == ']') open--;
				if(i > prog.length()) panic("WTF!! write correct code!!!"); 
			}
		}
		else if(prog[i] == ']' && mem[p]) // loop end in BrainF
		{
			int open = 1;
			while(open)
			{
				i--;
				if(prog[i] == ']') open++;
				if(prog[i] == '[') open--; 
				if(i < 0) panic("WTF!! write correct code!!!");
			}
		}  
	}
}

void BrainF::panic(const char* s)
{
	std::cout << s ;
	std::exit(0); 
}

int main(int ags, char** args)
{
	BrainF::_init_(args[1]);
	BrainF::interpret(); 
}
