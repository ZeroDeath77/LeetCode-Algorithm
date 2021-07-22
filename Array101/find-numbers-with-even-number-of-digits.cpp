class Solution {
public:
    int findNumbers(vector<int>& nums) {
        string str;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            str=to_string(nums[i]);
            if(str.length()%2==0)
                count++;
        }
        return count;
    }
};