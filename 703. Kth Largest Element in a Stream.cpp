class KthLargest {
public:
    int k,n;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->n=nums.size();
        for(auto it:nums)
        {
            pq.push(it);
        }
        while(n>k)
        {
            pq.pop();
            n--;
        }
    }
    
    int add(int val) {
        if(pq.empty()||n<k)
        {
            pq.push(val);
            this->n=n+1;
        }
        else if(pq.top()<val)
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
