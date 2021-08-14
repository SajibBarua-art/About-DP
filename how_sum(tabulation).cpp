#include<iostream>
#include<vector>
using namespace std;

int main() {
	cout << "Enter the target number: ";
	int target; cin >> target;
	cout << "Enter the length of the array: ";
	int n; cin >> n;
	int arr[n+1];
	for(int i=0; i<n; i++) cin >> arr[i];
	
	bool can_sum[target+1]={};  // initializing all value of the "can_sum" false
	can_sum[0]=true;
	vector<vector<int>> table(target+1);
	table[0]={};
	for(int i=0; i<target; i++) {
		if(can_sum[i]) {
			for(int element:arr) {
				int index=i+element;
				if(index<=target) {
					can_sum[index] = true;
					table[index]=table[i];
					table[index].push_back(element);
				}
			}
		}
	}
	
	int len=table[target].size();
	if(len) {
		for(int i=0; i<len; i++) cout << table[target][i] << " ";
		cout << endl;
		return 0;
	}
	cout << "NO\n";
}
