class Solution {
public:
    bool isAnagram(string s, string t) {
//         int hsh[26] ={0};
//         for(int i =0;i<s.size(); i++){
//             hsh[s[i]-'a']++;
//         }
//         int hsh2[26]={0};
//         for(int i =0; i< t.size(); i++){
//             hsh2[t[i]-'a']++;
//         }
        
//         for(int i =0; i<26; i++){
//             if(hsh[i]!=hsh2[i]) return false;
//         }
//         return true;
        unordered_map<char, int> m1, m2;
        for(auto ch : s){
            m1[ch]++;
        }
        
        for(auto ch : t){
            m2[ch]++;
        }
        
        return (m1==m2) ? true : false;
    }
};