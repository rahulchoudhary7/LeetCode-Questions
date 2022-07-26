class Solution {
public:
    int firstUniqChar(string s) {
        // queue<char> q;
        unordered_map<char,int> m;
        int n = s.length();
        // int ansIndex = -1;
        
        for(int i = 0; i<n; i++){
            char ch = s[i];
            m[ch]++;
        }
        
        for(int i = 0; i<n; i++){
            if(m[s[i]]==1)
                return i;
            
        }
        
        return -1;
    }
};