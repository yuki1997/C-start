#include<iostream>
using namespace std;

int main(){
	int n;
	int sum = 0;
	cout << "Please input the number" << endl;
	cin >> n;
	for(int i = 0; i <= n; i++){
		sum += i;
	}
	cout << sum << endl;
	return 0;
}
