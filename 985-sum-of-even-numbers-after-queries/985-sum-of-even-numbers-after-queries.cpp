class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int evenSum = 0;
        unordered_map<int, int> evenIndices;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(!(nums[i]&1)){
                evenSum+=nums[i];
                evenIndices[i] = nums[i];
            }            
        }
        
        for(int i=0; i<queries.size(); i++){
            int index = queries[i][1];
            int val = queries[i][0];
            if(evenIndices.find(queries[i][1])== evenIndices.end()){
                if(!((nums[index]+val)&1)){
                    evenSum+= nums[index]+val;
                    evenIndices[index] = nums[index] + val;
                }
                nums[index] = nums[index] + val;
            }
            else{
                evenSum-= nums[index];
                if(!((nums[index]+val)&1)) evenSum+= nums[index]+val;
                else evenIndices.erase(index);
                nums[index] = nums[index] + val;
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};