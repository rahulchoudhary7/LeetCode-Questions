class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        
        // int n = nums.size();
//         unordered_map<int, int> m;
        
//         for(int i =0; i<n; i++){
//             m[nums[i]]++;
//         }
        
//         set< vector<int> > s;
       
//         for(int i = 0; i<n; i++){
//             m[nums[i]]--;
//             for(int j = i+1; j<n; j++){
//                 m[nums[j]]--;
//                 vector<int> temp;
//                 int value = -1*(nums[i] + nums[j]);
//                 if(m.find(value) != m.end() && m[value]>=1){
//                     temp.push_back(value);
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
                    
//                     sort(temp.begin(), temp.end());
//                     if(temp.size()>0 && s.find(temp) == s.end()){
//                         s.insert(temp);
//                         ans.push_back(temp);
//                     }
                    
//                 }
//                 m[nums[j]]++;
//             }
//             m[nums[i]]++;
        //}
            int n = nums.size();
            vector<vector<int> > res;
            sort(nums.begin(), nums.end());
            
            for(int i = 0; i<n-2; i++){
                if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                    int low(i+1), high(n-1), sum(0-nums[i]);
                    
                    while(low<high){
                        if(nums[low]+nums[high] == sum){
                            res.push_back({nums[i], nums[low], nums[high]});
                            
                            while(low<high && nums[low] == nums[low+1]) low++;
                            while(low<high && nums[high] == nums[high-1]) high--;
                            low++;
                            high--;
                        }
                        
                        else if(nums[low]+nums[high] < sum)
                            low++;
                        else
                            high--;
                    }
                }
            }
        return res;
    }
};