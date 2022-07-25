int ans =-1;
int leftOcc(vector<int>& nums,int s, int e, int target){
    
    
    if(s>e)
        return ans;
    int mid = s + (e - s)/2;
    if(nums[mid] == target){
        ans = mid;
        return leftOcc(nums, s, mid -1, target);
    }
    else if(nums[mid]>target){
        return leftOcc(nums, s, mid -1, target);
    }
    else{
        return leftOcc(nums, mid+1, e, target);
    }

}
         
 int ansr =-1;       
int rightOcc(vector<int>& nums,int s, int e, int target){
   
    // int ans =-1;
    if(s>e)
        return ansr;
    int mid = s + (e - s)/2;
    if(nums[mid] == target){
        ansr = mid;
        return rightOcc(nums, mid+1, e, target);
    }
    else if(nums[mid]>target){
        return rightOcc(nums, s, mid -1, target);
    }
    else{
        return rightOcc(nums, mid+1, e, target);
    }
    
     
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return {-1, -1};
        vector<int> answ;
        answ.push_back(leftOcc(nums, 0, n-1, target));
        answ.push_back(rightOcc(nums,0, n-1, target));
        ans = -1;
        ansr = -1;
        return answ;
    }
};