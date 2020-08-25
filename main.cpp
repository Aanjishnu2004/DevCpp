#include "main.h"

char map(int i)
{
	if(i == 0) return ' ' ;
       	if(i == 1) return 'X' ;
	if(i == -1) return 'O' ; 
	return 'F' ;
}

void T3::start()
{
	for(int i = 0 ; i < 9 ; i++)
		state[i] = 0 ;
       	gameisstillon = true ;	
}

int T3::input(int k)
{
	int i , j ; 
Alpha:  std::cout << "Enter the position of the cross: " ;
	std::cin >> i >> j ; i-- ; j-- ; 
	if(i*3+j >= 9 || i*3+j < 0 || state[i*3+j] == 1 || state[i*3+j] == -1)
	{
		std::cout << "What the hell!!" << std::endl ;
	       	goto Alpha ;	
	}
	state[i*3+j] = k; 
	return k ; 
}

void T3::display()
{
	for(int i =0  ; i < 9 ; i++)
	{
		std::cout << "+---+---+---+" << std::endl;
	       	std::cout << "| " << map(state[i++]) << " | " << map(state[i++]) << " | " << map(state[i]) << " |" << std::endl ;	
	}
	std::cout << "+---+---+---+" << std::endl ;
}

void T3::update()
{
	this->display() ;
	
	//logic 
	
	if(checkfor(1))
	{
		gameisstillon = false ;
		std::cout << "Player one winns!!" << std::endl;
		return ;
	}
	
	std::cout << "player1 :- " << std::endl;
       	input(1) ;
	
	if(checkfor(-1))
	{
		gameisstillon = false ;
		std::cout << "Player two winns!!" << std::endl;
	       	return ;	
	}	

	std::cout << "player2 :- " << std::endl ;
	input(-1) ;

	int cc = 0 ;
	for(int i = 0 ; i < 9 ; i++) cc += state[i] == 0 ;
	if(cc == 0) {std::cout << "DRAW MF'S!!" << std::endl ; gameisstillon = false ; return ;}
}

bool T3::checkfor(int k)
{
	//horizontal checking

	for(int i = 0 ; i < 3 ; i++)
	{ 
		bool g = false  ;
		for(int j = 0 ; j < 3 ; j++)
		{
			if(state[i*3+j] == k) g = true ;
			else {g = false ;break;}
		}

		if(g) return true ; 
	}

	for(int i = 0 ; i < 3 ; i++)
	{ 
		bool g = false  ;
		for(int j = 0 ; j < 3 ; j++)
		{
			if(state[j*3+i] == k) g = true ;
			else {g = false ;break;}
		}

		if(g) return true ; 
	}

	bool g = false ;
	for(int i = 0 ; i < 3 ; i++)
	{ 
		if(state[i*3+i] == k) g = true ;
		else {g = false ;break;}
	}
	if(g) return true ;

	for(int i = 0 ; i < 3 ; i++)
	{ 
		if(state[i*3+2-i] == k) g = true ;
		else {g = false ;break;}
	}
	
	if(g) return true ;

	return false ;
}

int main()
{
	T3 t ;

	t.start() ;
	while(t.gameisstillon)
	{
		t.update() ;
	}
	t.display() ;
}
