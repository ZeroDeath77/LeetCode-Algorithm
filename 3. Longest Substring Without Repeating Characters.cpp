class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>set;
        int sum=0;
        int st=0,end=0;
        for(end=0;end<s.length();end++)
        {
            if(set.find(s[end])!=set.end())
            {
                while(st<end and set.find(s[end])!=set.end())
                {
                    set.erase(s[st]);
                    st++;
                }
            }
            sum=max(sum,end-st+1);
            set.insert(s[end]);
        }
        return sum;
    }
};
