class Solution {
private:
    void trim(string & s){
        int n=s.length();
        if(s[0]==' ') s.erase(0,1);
        if(s[n-1]==' ') s.pop_back();
    }
public:
    string reverseWords(string s) {
        // vector<string> v;
        
        int n = s.size();
        string ans;
        string temp="";
        bool check = false;
        for(int i=n-1; i>=0; i--){
            if(s[i]==' ' && check == true){
                reverse(temp.begin(), temp.end());
                ans.append(temp);
                ans+=' ';
                temp.clear();
                check = false;
            }
            else if(s[i]!=' '){
                temp+=s[i];
                check = true;
            }
            if(i==0 && check == true){
                reverse(temp.begin(), temp.end());
                ans.append(temp);
                temp.clear();
            }
        }
        trim(ans);
        return ans;
    }
};