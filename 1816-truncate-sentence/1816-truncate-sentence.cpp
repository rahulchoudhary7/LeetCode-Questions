class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans ="";
        
        stringstream ss(s);
        
        string temp;
        int count = 0;
        
        while(count<k && ss>>temp){
            count++;
            ans.append(temp);
            ans.push_back(' ');
        }
        
        ans.pop_back();
        return ans;
    }
};