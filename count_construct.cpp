#include<bits/stdc++.h>
using namespace std;

map<string, int> memo;

int count_construct(string target, string word_bank[], int n) {
	if(memo[target]) return memo[target];
	if(target=="") return 1;
	
	int total_ways=0;
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
				
			total_ways += count_construct(new_target, word_bank, n);
		}
	}
	memo[target]=total_ways;
	return total_ways;
}

int main() {
	string target; 
	cout << "Enter the target string: "; cin >> target;
	// n=target.size()
	int m; 
	cout << "Enter the total number of sub-string: "; cin >> m;
	string word_bank[m+1];
	cout << "Enter the all sub-string: ";
	for(int i=0; i<m; i++) cin >> word_bank[i];
	
	cout << "Total possible way are: " << count_construct(target, word_bank, n) << endl;
}


// time complexity: O(n*m^2)
// space complexity: O(m^2)
