class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp,temp;
        vector<int>ans;
        int len=s.length();
        int plen=p.length();
        for(auto x:p)
        {
            mp[x]++;
        }
        for(int i=0;i<len;i++)
        {
            temp[s[i]]++;
            if(i==plen-1 and mp==temp)
            {
                ans.push_back(i-plen+1);
            }
            if(i>=plen)
            {
                temp[s[i-plen]]--;
                if(temp[s[i-plen]]==0)
                {
                    temp.erase(s[i-plen]);
                }
                if(mp==temp)
                {
                    ans.push_back(i-plen+1);
                }
            }
        }
        return ans;
    }
};

===================================================================================================
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans,freq(26,0),word(26,0);
        int len=s.length();
        int plen=p.length();
        if(plen>len)
        {
            return ans;
        }
        for(int i=0;i<plen;i++)
        {
            freq[p[i]-'a']++;
            word[s[i]-'a']++;
        }
        if(freq==word)
        {
            ans.push_back(0);
        }
        for(int i=plen;i<len;i++)
        {
            word[s[i]-'a']++;
            word[s[i-plen]-'a']--;
            if(word==freq)
            {
                ans.push_back(i-plen+1);
            }
        }
        return ans;
    }
};
