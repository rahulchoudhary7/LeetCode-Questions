class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.length();
        
        string target = "";
        
        int start=0, end=m-1;
        
        
        for(int i=0; i<m; i++){
            target+=haystack[i];
        }
        for(int i=0; i<=n-m; i++){
            if(target==needle) return i;
            target.erase(target.begin()+0);
            target.push_back(haystack[i+m]);
            
        }
        return -1;
    }
};