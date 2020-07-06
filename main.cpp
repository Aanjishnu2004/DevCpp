#include <iostream>
#include <cmath>

/*
	This code was develouped by me for fun
	but it turned out nice so its getting up on github
	The cod ehere prints a parabola and a circle
	Console properties (RECOMENDED!!)
	The font size : 10
	Height = 500 
	Width = 500
	buffs are equal to the size
	
	and if u daspaly one thing at a time it looks cooler :)
*/

double translator(int d)
{
	return d/std::pow(10 , (std::log(d)+1));
}
 // THIS IS THE CODE FOR A PARABOLA
 
inline void pattern(int x , int y , int width , int height)
{
	if(500*translator(x-50)*translator(x-50) >= translator(height-y) || -500*translator(x-50)*translator(x-50) >= translator(height-y))
		std::cout << "#";
	else if(500*translator(-x+51)*translator(-x+51) >= translator(height-y) || -500*translator(-x+51)*translator(-x+51) >= translator(height-y))
		std::cout << "#";
	else
		std::cout << " ";
}


inline void pattern1(int x , int y , int width , int height)
{
	x-=120 ; y -= 30;
	if(0.25*x*x+y*y <= 250)
		std::cout << "#" ;
	else
		std::cout << " "; 
}

int main()
{
	int x=  0 , y = 0 , width = 300 , height = 60;
	
	for(y = 0 ; y<=height ; y++)
	{
		for(x = 0 ; x<=width ; x++)
		{
			pattern(x,y,width,height);
			pattern1(x,y,width,height);
		}	
		std::cout << '\n' ; 
	}
	std::cin.get();
}
