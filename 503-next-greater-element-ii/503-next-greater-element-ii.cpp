class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            int j = (i+1)%n;
            while(j!=i){
                if(nums[j]>nums[i]){
                    ans[i] = nums[j];
                    break;
                }
                
                j = (j+1)%n;
            }
            if(j==i) ans[i] = -1;
        }
        return ans;
    }
};