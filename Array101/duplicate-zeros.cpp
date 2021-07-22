class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int s=arr.size(), i=s-1;
        while(i>=0)
        {
            if(arr[i] != 0)
            {
                
            }
            else
            {
                arr.insert(arr.begin()+i,0);
                arr.pop_back();
            }
            --i;
        }
    }
};