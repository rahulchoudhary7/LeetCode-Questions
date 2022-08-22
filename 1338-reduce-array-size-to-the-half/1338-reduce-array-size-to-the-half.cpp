class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> freq;
        int c = 1;
        sort(arr.begin(), arr.end());
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]) c++;
            else{
                freq.push_back(c);
                c=1;
            }
        }
        freq.push_back(c);
        for(auto i: freq) cout<<i;
        
        sort(freq.begin(), freq.end());
        
        int n = arr.size()/2, ans(0);
        
        for(int i=freq.size()-1; i>=0; i--){
            n-=freq[i];
            ans++;
            if(n<=0){
                break;
            }
        }
        return ans;
    }
};