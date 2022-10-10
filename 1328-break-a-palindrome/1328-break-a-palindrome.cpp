class Solution {
public:
    
    bool aCheck(string s){
        int n = s.length();
        int i=0;
        
        while(i<n){
            if(s[i++]!= 'a') return false;
        }
        
        return true;
    }
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        
        if(n==1) return "";
        int i;
        bool changed;
        char prev;
        for(i=0; i<n; i++){
            if(palindrome[i]!='a'){
                prev = palindrome[i];
                changed = true;
                palindrome[i] = 'a';
                break;
            }
        }
        
        
        if(aCheck(palindrome)){
            if(changed) palindrome[i] = prev;
            palindrome[n-1] = 'b';
        }
        
        return palindrome;
    }
};