class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        
        
        while(i<j){
            if(vowels.find(s[i])!= vowels.end() && vowels.find(s[j])!=vowels.end()){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            
            else if(vowels.find(s[i]) == vowels.end() && vowels.find(s[j])== vowels.end()){
                i++;
                j--;
            }
            
            else if(vowels.find(s[i]) == vowels.end()) i++;
            
            else j--;
        }
        
        return s;
    }
};