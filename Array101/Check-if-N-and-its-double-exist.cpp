class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        /*for(int i=0;i<n;i++)
        {
            signed int val=(arr[i])*2;
            if(count(arr.begin(),arr.end(),val))
            {
                return true;
            }
        }
        return false;*/
        map<int,int> val;
        for(int i=0;i<n;i++)
        {
            val[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0 && val[arr[i]]%2==0)
            {
                return true;
            }
            if(arr[i]!=0 && val.count(arr[i]*2))
            {
                return true;
            }
        }
        return false;
    }
};