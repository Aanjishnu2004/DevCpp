#include <iostream>

struct T3
{
	private:
		int state[9] ;
	public:
		bool gameisstillon ;
		void start() ;
		void update() ;
		void display() ;
		bool checkfor(int) ;
		int input(int) ;	
};
