#include<iostream>
using namespace std;

int main() {
	long long fib[1000]={};
	fib[1]=1;
	cout << "Enter the position of fibonacci number: ";
	int n; cin >> n;
	for(int i=1; i<=n-2; i++) fib[i+1]+=fib[i], fib[i+2]+=fib[i];
	fib[n]+=fib[n-1];
	
	cout << "The fibonacci numbers of " << n << "th position is: " << fib[n] << endl;
}
