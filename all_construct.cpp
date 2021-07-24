#include<bits/stdc++.h>
using namespace std;

vector<string> single_way;
bool is_constructable=false;

void all_construct(string target, string word_bank[], int m) {
	if(target=="") {
		for(auto it=single_way.begin(); it!=single_way.end(); it++)
			cout << *it << " ";
		cout << endl;

		is_constructable=true;
		if(single_way.size())single_way.pop_back();
		return;
	}
	
	
	for(int j=0; j<m; j++) {
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
			
			single_way.push_back(word);
			all_construct(new_target, word_bank, m);
		}
	}
	
	if(single_way.size())single_way.pop_back();
	return;
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
	
	all_construct(target, word_bank, m);
	if(!is_constructable) cout << "NO\n";
}
