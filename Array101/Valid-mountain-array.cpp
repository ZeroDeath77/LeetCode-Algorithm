class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size(),down=0,up=0;
        if(n<3)
        {
            return false;
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                return false;
            }
            else if(arr[i]>arr[i-1])
            {
                if(down!=0)
                {
                    return false;
                }
                up++;
            }
            else if(arr[i-1]>arr[i])
            {
                down++;
                if(i==n-1 and up>0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};