#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getSecondLargest(vector<int> &arr) {
        // Code Here
    int max = arr[1];
    int secMax = -1;
    for(int i = 0; i < arr.size(); i++) {
    	if(arr[i] > max) {
            max = arr[i];
        }
    }
        
    for(int i = 0; i < arr.size(); i++) {
    	if(arr[i] > secMax && arr[i] < max) {
        	secMax = arr[i];
        }    
    }        
    return secMax;
}

int betterSecLargest(vector<int> nums) {
	int max = arr[0], secMax = INT_MIN;
	for(int i = 1; i < nums.size(); i++) {
		if(nums[i] > max) {
			secMax = max;
			max = nums[i];
		}
	}
	return secMax;
}

int main() {
	vector<int> test = {12, 35, 1, 10, 34, 1};
	cout<<betterSecLargest(test);
}