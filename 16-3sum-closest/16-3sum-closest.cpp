class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX;
        int min_diff = INT_MAX;
        
        for(int k = 0; k < nums.size();k++){
            int i = k+1;
            int j = nums.size()-1;
            while(i<j){
                int temp_sum = nums[i] + nums[j] + nums[k];
                
                int diff = abs(target - temp_sum);
                
                if(min_diff > diff){
                    min_diff = diff;
                    ans = temp_sum;
                    if(ans == target) return ans;
                }
                
                if(temp_sum>target) j--;
                else i++;
            }
        }
        
        return ans;
    }
};