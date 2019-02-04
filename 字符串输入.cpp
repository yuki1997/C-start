#include<iostream>
#include<string>
using namespace std;

int main()
{
	string mystr;
	cout << "what is your name?";
	getline(cin, mystr);
	cout << "Hello " << mystr << ".\n";
	cout << "What is your favourite team?";
	getline(cin, mystr);
	cout<< "I like " << mystr << "too!\n";
	return 0;
}
