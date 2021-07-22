class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> num (nums.size());
        for(int i=0;i<nums.size();i++)
            num[i] =nums[i]*nums[i];
        sort(num.begin(),num.end());
        return num;
    }
};