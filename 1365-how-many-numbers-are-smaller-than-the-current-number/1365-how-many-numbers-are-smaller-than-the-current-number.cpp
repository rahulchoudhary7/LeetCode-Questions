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
        int n = nums.size();
        vector<int> temp(nums);
        vector<int> res;
        
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> m;
        
        for(int i = 0; i<n; i++){
            if(m.find(temp[i])== m.end())
                m[temp[i]] = i;
        }
        
        for(int i = 0; i<n; i++){
            int target = nums[i];
            int ans = m[target];
            res.push_back(ans);
        }
        return res;
    }
};