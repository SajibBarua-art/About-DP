/*  Write a function "can_construct(string target, string word_bank[])".
The function should return a boolean indicating wether or not the "target"
string can be constructed by concatenating elements of the "word_bank" array. */

#include<bits/stdc++.h>
using namespace std;

map<string, int> memo;

int can_construct(string target, string word_bank[], int n) {
	if(memo[target]) return memo[target];
	if(target=="") return 1;
	
	for(int j=0; j<n; j++) {
		string word=word_bank[j];
		int word_len=word.size(), flag=1;
		for(int i=0; i<word_len; i++) {
			if(word[i] != target[i]) {
				flag=0;
				break;
			}
		}
		if(flag) {
			string new_target="";
			for(int i=word_len; i<(int)target.size(); i++)
				new_target.push_back(target[i]);
				
			memo[new_target] = can_construct(new_target, word_bank, n);
			if(memo[new_target] == 1) return 1;
		}
	}
	return -1;
}

int main() {
	string target; 
	cout << "Enter the target string: "; cin >> target;
	int n; 
	cout << "Enter the total number of sub-string: "; cin >> n;
	string word_bank[n+1];
	cout << "Enter the all sub-string: ";
	for(int i=0; i<n; i++) cin >> word_bank[i];
	
	if(can_construct(target, word_bank, n) == 1)
		cout << "Possible\n";
	else cout << "Impossible\n";
}
