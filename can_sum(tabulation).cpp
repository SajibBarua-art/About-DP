#include<iostream>
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
	for(int i=0; i<target; i++) {
		if(can_sum[i]) {
			for(int element:arr) {
				int index=i+element;
				if(index<=target) {
					can_sum[index] = true;
					if(index == target) {
						cout << "It is possible.\n";
						return 0;
					}
				}
			}
		}
	}
	
	cout << "It is impossible.\n";
	return 0;
}
