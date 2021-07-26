class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        vector<int>::iterator it;
        it=find(nums.begin(),nums.end(),target);
        int mn=0,mx=nums.size()-1;
        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mn]<=nums[mid])
            {
                if(nums[mn]<=target && target<=nums[mid])
                {
                    mx=mid-1;
                }
                else
                {
                    mn=mid+1;
                }
            }
            else
            {
                if(nums[mid]<target && target<=nums[mx])
                {
                    mn=mid+1;
                    
                }
                else
                {
                    mx=mid-1;
                }
            }
        }
        return -1;
    }
};