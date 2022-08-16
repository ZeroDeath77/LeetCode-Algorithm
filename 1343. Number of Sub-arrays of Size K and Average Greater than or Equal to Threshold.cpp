class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int count=0;
        double avg=0;
        for(int i=0;i<k;i++)
        {
            avg+=arr[i];
        }
        if((avg/k)>=threshold)
        {
            count++;
        }
        for(int i=k;i<n;i++)
        {
            avg+=(arr[i]-arr[i-k]);
            if((avg/k)>=threshold)
            {
                count++;
            }
        }
        return count;
    }
};
