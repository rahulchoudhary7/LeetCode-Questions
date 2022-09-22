class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";
        stringstream str(s);
        string word;
        while(str>>word){
            reverse(word.begin(), word.end());
            ans.append(word);
            ans+=" ";
        }
        ans.pop_back();
        
        return ans;;
    }
};