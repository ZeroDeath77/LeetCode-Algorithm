class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(auto &x:s1)
        {
            mp[x]++;
        }
        
        int n1=s1.size();
        int n2=s2.size();
        int size=mp.size();
        int i=0,j=0;
        while(j<n2)
        {
            if(mp.find(s2[j])!=mp.end())
            {
                mp[s2[j]]--;
                if(mp[s2[j]]==0)
                {
                    size--;
                }
            }
            if(j-i+1<n1)
            {
                j++;
            }
            else if(j-i+1==n1)
            {
                if(size==0)
                {
                    return true;
                }
                if(mp.find(s2[i])!=mp.end())
                {
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1)
                    {
                        size++;
                    }
                }
                j++;
                i++;
            }
        }
        return false;
    }
};

======================================================================================================
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0),req(26,0);
        for(auto ch:s1)
        {
            freq[ch-'a']++;
        }
        int i=0;
        for(int j=0;j<s2.size();j++)
        {
            req[s2[j]-'a']++;
            if(j>=s1.size()-1)
            {
                if(req==freq)
                {
                    return true;
                }
                req[s2[j-s1.size()+1]-'a']--;
            }
        }
        return false;
    }
};
