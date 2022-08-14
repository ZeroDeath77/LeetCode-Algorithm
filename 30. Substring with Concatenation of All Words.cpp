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
=================================================================================================================
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        int w=words[0].size();
        unordered_map<string,int>mp;
        unordered_map<string,int>tmp;
        
        if(n*w>s.length())
            return {};
        
        vector<int>ans;
        
        for(auto word: words)
            mp[word]++;
        
        for(int i=0;i<w;i++)
        {
            tmp.clear();
            int found=0;
            int left=i;
            for(int j=i;j<=s.length()-w;j+=w)
            {
                string wrd=s.substr(j,w);
                if(mp.find(wrd)!=mp.end())
                {
                    tmp[wrd]++;
                    found++;
                    while(tmp[wrd]>mp[wrd])
                    {
                        tmp[s.substr(left,w)]--;
                        found--;
                        left+=w;
                    }
                    if(found==n)
                        ans.push_back(left);
                }
                else
                {
                    found=0;
                    left=j+w;
                    tmp.clear();
                }
            }
        }
        return ans;
    }
};
