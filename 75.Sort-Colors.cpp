#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<limits.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
        
    }
};

int main()
{
	Solution s1;
	vector<int> v {0,1,1,0,0,2,0,1,1,2,0,1};
	s1.sortColors(v);
	for(auto x:v)
	{
		cout<<x<<" ";
	}
	return 0;
}
