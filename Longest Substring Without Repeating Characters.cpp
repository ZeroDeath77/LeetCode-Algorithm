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

==================================================================================
  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int st=0,end=0,len=0;
        while(end<s.size())
        {
            if(mp[s[end]]!=-1)
            {
                st=max(mp[s[end]]+1,st);
            }
            mp[s[end]]=end;
            len=max(len,end-st+1);
            end++;
        }
        return len;
    }
};
