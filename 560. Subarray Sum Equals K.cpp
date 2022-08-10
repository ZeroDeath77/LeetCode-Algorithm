//DP
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefix[nums.size()+1],count=0;
        prefix[0]=0;
        for(int i=1;i<nums.size()+1;i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
            int rem=prefix[i]-k;
            if(mp[rem]>0)
            {
                count+=mp[rem];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};

//Method 2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
           int sum = 0, ans = 0, n = nums.size();
           for(int i = 0; i < n; i++){
               sum += nums[i];
               if(hm.find(sum - k) != hm.end()){
                  ans += hm[sum - k];
               }
               if(sum == k)ans++;
                  hm[sum]++;
           }
           return ans;
    }
};
================================================================
  
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            
            if(sum==k) ans++;
            
            if(mp.find(sum-k)!=mp.end()) {
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};

