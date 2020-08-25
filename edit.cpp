#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std; 

vector<string> v ; 
char* name ; 

void printmyname()
{
	cout << "*******************************************************" << endl ;
       	cout << "**                                                   **" << endl ;	
	cout << "**            THE CRINGE EDITOR FOR ARE USE          **" << endl ;
	cout << "**            1. to edit line with line no.          **" << endl ;
	cout << "**            2. add new text to line no.            **" << endl ;
	cout << "**            3. to delete a line from copy          **" << endl ;
	cout << "**            4. to display the show again           **" << endl ;
	cout << "**            0. to exit system ok write             **" << endl ;
	cout << "**                                                   **" << endl ;
	cout << "**     --------------------------------------------  **" << endl ;
      	cout << "**     |    @Author: Aanjishnu Bhattacharyya      |  **" << endl ;
	cout << "**     | @version: 1.0.0(Seriosly what did think) |  **" << endl ;
	cout << "**     --------------------------------------------  **" << endl ;
	cout << "**                                                   **" << endl ;
	cout << "**************************THNX*************************" << endl << endl << endl ;
}

int restorevectorfromfile(char* ham, bool willinit = true)
{
	fstream f(ham, ios::in);
	string s;
       	int i = 1 ;	
	while(getline(f,s,'\n'))
	{
		cout << i << ":\t| " << s << endl ;
		if (willinit) v.push_back(s) ;
		i++ ;	
	}
	
	f.close();
	return i ; 
}

void inputoutputguys(int len)
{
	while(1)
	{
		int opcode = 0 ; int lineNO = 0 ; 
		
		cout << "\ncommand: " ;
		cin >> opcode ;
		cin.get() ;
		string temp ; 
		switch(opcode)
		{
			case 0 :// exit prog
				return ;  
			break ; 
			case 1 : // writeinline
				cout << "\neditwhich: " ; 
				cin >> lineNO ; 
				cin.get() ;
				if(lineNO > len || lineNO <= 0)
				{
				        cout << "Out of range!!" << endl ;
					break ; 
				}
				cout << "|=>" ;
				getline(cin, temp, '\n'); 
				v[lineNO-1] = temp ; 
			break ;
			case 2 : // add more
		       		cout << "\naddWhich: " ;
				int gmene ;
				cin >> gmene ;
			       	cin.get() ;	
				if(gmene < 0 || gmene < len)
				{
					cout << "Out of range" << endl;
					break ;
				}
				cout << "|:=> "; // i wanted to change some thing
			       	getline(cin, temp, '\n'); 
				for(int i = 0 ; i < gmene-len ; i++)v.push_back("");
				v.push_back(temp);len++ ; 
			break ;
			case 3: // delete line
				cout << "\ndelWhich: " ;
				cin >> lineNO ; 
				cin.get() ;
				if(lineNO > len || lineNO < 0)
				{
					cout << "Out of Range!!" ;
				       	break ; 
				}
				v.erase(v.begin()+lineNO-1,v.begin()+lineNO) ;
			break ;
			case 4 : // redisp
				restorevectorfromfile(name, false);
			break ;
		}
	}
}

void writetofile()
{
	fstream ff(name, ios::out) ;

	for(string& lex : v)
	{
		ff << lex << endl ;	
	}

	ff.close();
}

int main(int ag, char** args)
{
	if(ag>1)
		name = args[1] ;
	else 
		name = "new(form_crap_edit)";	
	printmyname();	
	int len = restorevectorfromfile(args[1]);
	inputoutputguys(len) ;
	writetofile() ;
}
