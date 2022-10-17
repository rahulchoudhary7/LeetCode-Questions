class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> hash(26, 0);
        
        int n = sentence.size();
        
        for(int i=0; i<n; i++){
            hash[sentence[i]-'a'] = 1;
        }
        
        for(int i=0; i<26; i++)
            if(hash[i]!=1) return false;
        
        return true;
    }
};