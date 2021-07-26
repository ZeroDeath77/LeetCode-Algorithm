class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j++] == nums[j]);
                    while(j < k && nums[k--] == nums[k]);
                }else if(sum < 0){
                    while(j < k && nums[j++] == nums[j]);
                } else{
                    while(j < k && nums[k--] == nums[k]);
                }
            }
        }

        return res;
    }
};