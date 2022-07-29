class Solution {
public:
    bool maxCandy(vector<int> candies, int extraCandies, int index){

        candies[index]+=extraCandies;
        auto maxIt = max_element(candies.begin(), candies.end());
        int maxC = *maxIt;
        // candies[index]-=extraCandies;
        return (candies[index]>=maxC);
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(); 
        vector<bool> res(n);
        for(int i = 0; i<n; i++){
            res[i] = maxCandy(candies, extraCandies, i);
        }
        return res;
    }
};