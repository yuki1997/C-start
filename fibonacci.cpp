#include<iostream>
using namespace std;

int main()
{
	unsigned long s = 0, f1 = 1, f2 = 1, f3 = 1, n = 0;
	cin >> n;
	
	if(n > 2)
	for(s = 3; s <= n; s++){
		f3 = (f2 + f1) % 10007;
		f1 = f2;
		f2 = f3;
	}
	
	cout << f3;
	return 0;
}
