class Solution{
	public:
		vector<int> twoSum(vector<int> &numbers, int target)
		{
			vector<int> res;
			map<int,int> hmap;
			hmap.clear();
			for(int i=0; i<numbers.size(); i++)
			{
				hmap[numbers[i]]=i;
			}
			for(int i=0; i<numbers.size(); i++)
			{
				if(hmap.find((target-numbers[i])) != hmap.end())
				{
					if(i<hmap[target-numbers[i]])
					{
						res.push_back(i);
						res.push_back(hmap[target-numbers[i]]);
						return res;
					}
					if(i>hmap[target-numbers[i]])
					{
						res.push_back(hmap[target-numbers[i]]);
						res.push_back(i);
						return res;
					}
				}
			}
            return res;
		}
};
