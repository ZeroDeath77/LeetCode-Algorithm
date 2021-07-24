class Solution {
public:
    int maxSubArray(vector<int>& nums) {
 			if(nums.size()==0)
 			{
 			    return 0;
 			}
 			int sum=0;
 			int ma=INT_MIN;
 			
 			for(int n: nums)
 			{
 			    sum=max(sum+n,n);
 			    ma=max(ma,sum);
 			}
 			return ma;
    }
};