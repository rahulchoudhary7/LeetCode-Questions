class Solution {

public:
    
    bool isPossible(vector<int>&nums, int n, int target, int mid){
    int sum = 0;
    for(int i =0; i< mid; i++){
        sum+=nums[i];
    }
    // int maxi = sum;
    if (sum>=target) return true;
    int l =0, r = mid ;
    while(r!=n){
        sum-=nums[l++];
        sum+=nums[r++];
        if (sum>=target) return true;
    }
    // if(maxi>=target) return true;
    return false;
 }
    
    
    int minSubArrayLen(int target, vector<int>& nums) {
        // int n = nums.size();
        // int lo =0;
        // int mid =0;
        // int sum =0, len = INT_MAX;
        // while(mid<n){
        //     sum+=nums[mid++];
        //     while(sum>=target){
        //         len = min (len, mid - lo);
        //         sum-=nums[lo++];
        //     }
        // }
        // return len == INT_MAX ? 0 : len;
    int n = nums.size();
    int lo =0;
    int hi = n+1;
    bool answerPossible = false;
    while(lo<hi){
        int mid = lo + (hi - lo)/2;
        if(isPossible(nums, n, target, mid)){
            answerPossible = true;
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
        
    }
    if(answerPossible) return lo;
    return 0;
    }
};