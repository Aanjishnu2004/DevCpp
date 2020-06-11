#include <iostream>
#include <string>

using namespace std;

struct pattern
{
	void p1(const string& s , const string& a)
	{
		for(int i = 0 ; i<s.length() ; i++)
		{
			cout << a;
			for(int j = 0 ; j<=i ; j++)
			{
				cout << s[j];
			}
			cout << endl ;
		}
	}
	void p2(const string& s , const string& a)
	{
		for(int i = 0 ; i<s.length() ; i++)
		{
			cout << a;
			for(int j = 0 ; j<=i ; j++)
			{
				cout << s[s.length()-1-j];
			}
			cout << endl ;
		}
	}
	void p3(const string& s , const string& a)
	{
		for(int i = 0 ; i<s.length() ; i++)
		{
			cout  << a << s[i] << endl;
		}
	}
	void p4(const string& s , const string& a)
	{
		for(int i = 0 ; i<s.length() ; i++)
		{
			cout << a;
			for(int j = i ; j<s.length() ; j++)
			{
				cout << s[j];
			}
			cout << endl ;
		}
	}
	void p5(const string& s , const string& a)
	{
		for(int i = s.length()-1 ; i >= 0 ; i--)
		{
			cout << a;
			for(int j = 0 ; j<=i ; j++)
			{
				cout << s[j];
			}
			cout << endl ;
		}
	}
};

int main()
{
	
	string s = "BOOK" ;
	string a = "";
	pattern p;

	while(1)
	{
		p.p1(s,a);
		p.p2(s,a);
		p.p3(s,a);
		p.p4(s,a);
		p.p5(s,a);
		a+=" ";
		cin.get();
		system("cls");
	}
}