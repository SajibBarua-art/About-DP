/* Q: It is possiblt to generate the target_number using numbers from the array by only sum operation.
 * All inputs are non-negative.
 * You may use an element of the array as many as needed. */

#include<iostream>
using namespace std;

bool can_sum(int target_number, int numbers[], int n, int memo[]) {
	// base case
	if(target_number == 0) return 1;
	if(target_number < 0) return 0;
	
	// for memoization
	if(memo[target_number] == -1) return 0;
	if(memo[target_number] == 1) return 1;

    // To check all the elements of the numbers array
	for(int i=0; i<n; i++) {
		int remainder = target_number-numbers[i];
		if(can_sum(remainder, numbers, n, memo)) {
			memo[target_number] = 1;
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
	
	if(can_sum(target_number, numbers, n, memo))
		cout << "Possible.\n";
	else cout << "Impossible.\n";
}

// time complextiy: O(target_number*array_size)
// space complexity: O(target_number)
