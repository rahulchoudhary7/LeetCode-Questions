class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        string temp ="";
        unordered_map<string, int> mp;
        for(int i=0; i<10; i++){
            temp+=s[i];
        }
        
        mp[temp]++;
        
        int i=0;
        int j = 10;
        
        while(j<s.size()){
            temp.erase(0,1);
            temp+=s[j++];
            mp[temp]++;
        }
        
        for(auto it : mp){
            if(it.second >1) ans.push_back(it.first);
        }
        return ans;
    }
};