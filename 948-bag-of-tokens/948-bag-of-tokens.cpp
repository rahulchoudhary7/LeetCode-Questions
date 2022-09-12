class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int n = tokens.size();
        int s = 0;
        int e = n-1;
        int score = 0;
        int res = 0;
        while(s<=e){
            if(power>=tokens[s]){
                power-=tokens[s++];
                res = max(res, ++score);
            }
            else if(score>0){
                power+=tokens[e--];
                score--;
            }
            else{
                break;
            }
        }
        
        return res;
    }
};