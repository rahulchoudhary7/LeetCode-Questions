class Solution {
private:
    
        vector<int> right(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i = n-1; i>=0; i--){
            int curr = heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
        
        }
    
        vector<int> left(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i = 0; i<n; i++){
            int curr = heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = right(heights);
        vector<int> prev(n);
        prev = left(heights);
        int maxArea = INT_MIN;
        for(int i = 0; i<n; i++){
            int l = heights[i];
            if(next[i]==-1){
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;
            int area = l*b;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> M(n , vector<int> (m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(matrix[i][j]=='0')
                    M[i][j] = 0;
                else
                    M[i][j] = 1;
            }
        }
        
        int maxArea = largestRectangleArea(M[0]);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(M[i][j]!=0)
                    M[i][j]= M[i-1][j]+ M[i][j];
                
                else
                    M[i][j] = 0;
            }
            
            int area = largestRectangleArea(M[i]);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};