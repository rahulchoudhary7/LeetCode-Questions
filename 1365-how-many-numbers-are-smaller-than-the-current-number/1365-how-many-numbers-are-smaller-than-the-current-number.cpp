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
//         int n = nums.size();
//         vector<int> temp(nums);
        
//         vector<int> res;
//         sort(temp.begin(), temp.end());
        
//         unordered_map<int, int> hash_map;
        
//         for(int i = n-1; i>=0; i--)
//             hash_map[temp[i]] = i;
        
        
//         for(int i = 0; i<n; i++)
//             res.push_back(hash_map[nums[i]]);
        
        int n = 101;
        
        vector<int> hash(n, 0);
        vector<int> res;
        
        for(int i = 0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        
        for(int i = 1; i<n; i++){
            hash[i] = hash[i] + hash[i-1];
        }
        
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == 0)
                res.push_back(0);
            
            else
                res.push_back(hash[nums[i] -1]);
        }
        
        
        return res;
    }
};