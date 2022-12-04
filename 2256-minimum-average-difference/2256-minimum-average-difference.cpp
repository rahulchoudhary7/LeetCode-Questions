class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        
        vector<long> preLeftToRight(n);
        vector<long> preRightToLeft(n);
        preLeftToRight[0] = nums[0];
        preRightToLeft[n-1] = nums[n-1];
        
        for(int i=1; i<n; i++){
            preLeftToRight[i]= preLeftToRight[i-1] + nums[i];
        }
        
        for(int i=n-2; i>=0; i--){
            preRightToLeft[i]= preRightToLeft[i+1] + nums[i];
        }
        
        // reverse(preRightToLeft.begin(), preRightToLeft.end());
        
        int ansIndex = INT_MAX;
        int ans ;
        
        for(int i=0; i<(n-1); i++){
            int a = preLeftToRight[i]/(i+1);
            int b = preRightToLeft[i+1]/(n-i-1);
            
            if(abs(a-b) < ansIndex){
                ansIndex = abs(a-b);
                ans = i;
            }
        }
        
        // int ansIndex1 = min((preLeftToRight[n-1])/n, ansIndex);
        if((preLeftToRight[n-1])/n < ansIndex){
                // ansIndex = abs(a-b);
                ans = n-1;
            }
        
        // for(int i=0; i<n; i++){
        //     cout<<preLeftToRight[i]<<" "<<preRightToLeft[i]<<endl;
        // }
        
        // if(preLeftToRight[n-1]==0) return 0;
        
        return ans;
    }
};