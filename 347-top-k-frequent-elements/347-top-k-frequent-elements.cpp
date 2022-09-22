class Solution {
private:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
    
    void sortt(unordered_map<int, int> &m, vector<pair<int, int> >&temp){
        for(auto &it: m)
            temp.push_back(it);
        
        sort(temp.begin(), temp.end(), cmp);           
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        
        vector<pair<int, int> > temp;
        sortt(freq, temp);
        
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};