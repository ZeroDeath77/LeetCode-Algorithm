class Solution {
public:
    string removeOuterParentheses(string s) {
        int st=0;
        string str="";
        int cnto=0,cntc=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                cnto++;
            }
            if(s[i]==')')
            {
                cntc++;
            }
            if(cnto==cntc)
            {
                cnto=0;
                cntc=0;
                str+=s.substr(st+1,i-st-1);
                st=i+1;
            }
        }
        return str;
    }
};
