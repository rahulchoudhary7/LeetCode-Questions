class Solution {
public:
    string reverseWords(string s) {
        int i =0, j = s.length()-1;
        vector<string> strings;
        stringstream str(s);
        string word;
        while(str>>word)
            strings.push_back(word);
        
        string ans = "";
        for(auto i: strings){
            reverse(i.begin(), i.end());
            ans.append(i);
            ans+=" ";
        }
        ans.pop_back();
        
        return ans;;
    }
};