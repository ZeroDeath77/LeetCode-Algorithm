class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(i<n-1)
            {
                if(mp[s[i]]>=mp[s[i+1]])
                {
                    ans+=mp[s[i]];
                }
                else
                {
                    ans-=mp[s[i]];
                }
            }
            else
            {
                ans+=mp[s[i]];
            }
        }
        return ans;
    }
};

===========================================================================================
  class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
        };
        int ans =0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]<mp[s[i+1]])
                ans-=mp[s[i]];
            else
                ans+=mp[s[i]];
        }
        return ans;
    }
};
