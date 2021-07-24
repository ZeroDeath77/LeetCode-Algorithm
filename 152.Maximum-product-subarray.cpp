class Solution {
public:
    int maxProduct(vector<int>& nums) {
			int maxall=nums[0];
			int maxend=nums[0];
			int minend=nums[0];
			
			for(int i=1;i<nums.size();i++)
			{
				int tmp=maxend;
				maxend=max({nums[i],nums[i]*maxend,nums[i]*minend});
				minend=min({nums[i],nums[i]*tmp,nums[i]*minend});
				maxall=max(maxall,maxend);
			}
			return maxall;
    }
};