#include<iostream>
using namespace std;

int main()
{
	int n, temp, i, j, z = 1;
	cin >> n;
	int a[n];
	for(i = 0; i < n; i++){
		for(j = i + 1; z <= n - i - 1; j++, z++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		z = 1;
	}
	for(i = 0; i < n; i++){
		cout << a[i];
	}
	cout << endl;
	return 0; 
}
