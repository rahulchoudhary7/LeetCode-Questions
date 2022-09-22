class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n<2) return 0;
        int ans = INT_MIN;
        int diff = 0;
        for(int i =1; i<n; i++){
            diff = nums[i] - nums[i-1];
            ans = max(ans, diff);
        }
        return ans;
    }
};