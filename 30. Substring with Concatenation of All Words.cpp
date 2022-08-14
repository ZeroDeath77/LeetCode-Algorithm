class Solution {
public:
    bool solve(unordered_map<string,int>mp,string str,int wl)
    {
        for(int i=0;i<str.length();i+=wl)
        {
            string tmp=str.substr(i,wl);
            if(mp.find(tmp)!=mp.end())
            {
                if(--mp[tmp]==-1)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int len=s.length();
        int wordLen=words[0].size();
        unordered_map<string,int>mp;
        for(int j=0;j<words.size();j++)
        {
            mp[words[j]]++;
        }
        int ptr=0;
        int size=wordLen*words.size();
        while(ptr+size<=len)
        {
            if(solve(mp,s.substr(ptr,size),wordLen))
            {
                ans.push_back(ptr);
            }
            ptr++;
        }
        return ans;
    }
};
