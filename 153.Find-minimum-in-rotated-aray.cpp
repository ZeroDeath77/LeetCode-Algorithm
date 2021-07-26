class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size()-1;
        int mn=0, mx=nums.size()-1;
        while(mn<mx)
        {
            int mid = mn + (mx-mn)/2;
            if(nums[mid]<nums[mx])
            {
                mx=mid;
            }
            else
            {
                mn=mid+1;
            }
        }
        return nums[mn];
    }
};