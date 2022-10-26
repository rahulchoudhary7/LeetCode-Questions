class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> positions;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]==c) positions.push_back(i);
        }
        int n = s.length();
        vector<int> ans(n, INT_MAX);
        
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<positions.size(); j++){
                ans[i] = min(abs(i-positions[j]), ans[i]); 
            }
        }
        return ans;
    }
};