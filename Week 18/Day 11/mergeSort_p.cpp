#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> nums, int si, int ei, int mid){
	vector<int> ans;
	int i = si, j = mid+1;
	while (i <= mid && j <= ei)
	{
		if (nums[i] < nums[j])
		{
			ans.push_back(i++);
		}else
		{
			ans.push_back(j++);
		}
	}

	while (i <= mid)
	{
		ans.push_back(i++);
	}
	
	while (j <= mid)
	{
		ans.push_back(j++);
	}

	for (int i = si; i < ei; i++)
	{
		nums[i] = ans[i];
	}
	
}

void divide(vector<int> nums, int si, int ei){
	if (si >= ei)
		return;
	
	int mid = (si+ei)/2;
	divide(nums, si, mid);
	divide(nums, mid+!, ei);
	merge(nums, si, ei, mid);
	
}

int main(){
	vector<int> nums;
	int data;
	cin>>data;
	while (data < 0)
	{
		nums.push_back(data);
		cin>>data;
	}
	
	divide(nums, 0, nums.size());
	return 0;
}