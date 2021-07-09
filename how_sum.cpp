/* Q: Is it possiblt to generate the target_number using numbers from the array by only sum operation?
 * If yes, then return an array with numbers.
 * All inputs are non-negative.
 * You may use an element of the array as many as needed. */

#include<iostream>
#include<vector>
using namespace std;

bool how_sum(int target_number, int numbers[], int n, int memo[], vector<int> &result) {
	cout << target_number << " ";
	if(target_number < 0) return 0;
	if(target_number == 0) return 1;
	
	if(memo[target_number] == 1) return 1;
	if(memo[target_number] == -1) return 0;
	
	for(int i=0; i<n; i++) {
		int remainder=target_number-numbers[i];
		if(how_sum(remainder, numbers, n, memo, result)){
			memo[target_number] = 1;
			result.push_back(numbers[i]);
			return 1;
		}
		else {
			memo[target_number] = -1;
		}
	}
	return 0;
}

int main() {
	int target_number, numbers[100], n;
	cout << "Enter the target number: ";
	cin >> target_number;
	cout << "Enter the total number: ";
	cin >> n;
	cout << "Enter all the value of the number: ";
	for(int i=0; i<n; i++) cin >> numbers[i];
	
	// for memoization
	int memo[1001]={};
	
	vector<int>result;
	if(how_sum(target_number, numbers, n, memo, result)) {
		cout << "Possible.\n";
		for(auto it=result.begin(); it!=result.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else cout << "Impossible.\n";
}

// time complextiy: O(target_number*array_size)
// space complexity: O(target_number^2)
