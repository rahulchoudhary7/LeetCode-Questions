class Solution {
private:
    int binarySearch(vector<int> &arr, int k){
        int n = arr.size();
        int s(0), e(n-1);
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid]==k)
                return mid;
            else if(arr[mid]<k)
                s = mid+1;
            else
                e = mid-1;
        }
        return -1;
    }
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // vector<int> temp(nums);
        vector<int> res;
        
        // sort(temp.begin(), temp.end());
        
        for(int i = 0; i<nums.size(); i++){
            int count = 0;
            for(int j = 0; j<nums.size(); j++){
                if(i == j) continue;
                if(nums[i]>nums[j])
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};