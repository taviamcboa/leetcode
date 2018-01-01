class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // difference between unordered_map and map. 
        // map sort by key value


        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) 
            mp[nums[i]] = i;
        
        vector<string> ans(mp.size(), "");
        int cnt = 1; 
        for (map<int, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++, cnt++) {
            if (cnt == 1) ans[it->second] = "Gold Medal";
            else if (cnt == 2) ans[it->second] = "Silver Medal";
            else if (cnt == 3) ans[it->second] = "Bronze Medal";
            else ans[it->second] = to_string(cnt);
        }
        
        return ans;
    }

    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        vector<string> res(nums.size(),"");
        int count = 1;
        for(int i=0; i<nums.size();i++)
        {
            if(count==1) {res[pq.top().second] = "Gold Medal"; count++;}
            else if(count==2) {res[pq.top().second] = "Silver Medal"; count++;}
            else if(count==3) {res[pq.top().second] = "Bronze Medal"; count++;}
            else {res[pq.top().second] = to_string(count); count++;}
            pq.pop();
        }
        return res;
    }
};