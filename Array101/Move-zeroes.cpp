class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(nums[i]==0 and nums[j]!=0)
            {
                int tmp;
                tmp=nums[i];
                nums[i]=nums[j];
                nums[j]=tmp;
                i++;
            }
            else if(nums[i]!=0)
            {
                i++;
            }
        }
    }
};