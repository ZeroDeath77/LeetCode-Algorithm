class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int max=0;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
            if(i==n-1)
            {
                arr[i]=-1;
            }
            else
            {
                arr[i]=max;
            }
        }
        return arr;
    }
};