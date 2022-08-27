class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--){
            while(s.top()!=-1 && s.top()<=nums2[i]) s.pop();
            
            nge[i] = s.top();
            s.push(nums2[i]);
        }
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
            mp[nums2[i]] = nge[i];
        int m = nums1.size();
        
        vector<int> ans(m);
        
        for(int i=0; i<m; i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};