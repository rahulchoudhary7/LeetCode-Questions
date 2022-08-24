class Solution {
private:
    
    unordered_map<int, bool> checkRow;
    unordered_map<int, bool> checkUpper;
    unordered_map<int, bool> checkLower;
    
    void createRes(vector<vector<int> > &board, vector<vector<string>> &res, int n){
        
        vector<string> temp;
        for(int i=0; i<n; i++){
            string s ="";
            for(int j=0; j<n; j++){
                if(board[i][j]==1) s.push_back('Q');
                else s.push_back('.');
            }
            temp.push_back(s);
        }
        res.push_back(temp);
    }
    
    
    bool isSafe(int row, int col, int n, vector<vector<int> > & board){
        
        // if(checkRow[row]==true) return false;
        // if(checkUpper[row+col]==true) return false;
        // if(checkLower[(n-1)+row-col]==true) return false;
        
        int x  = row;
        int y = col;
        
        while(y>=0){
            if(board[x][y]!=0) return false;
            y--;
        }
        
        x = row;
        y = col;
        
        while(x>=0 && y>=0){
            if(board[x][y]!=0) return false;
            x--;
            y--;
        }
        
        
        x = row;
        y = col;
        
        while(x<n && y>=0){
            if(board[x][y]!=0) return false;
            x++;
            y--;
        }
        
        return true;
        
        return true;
        
    }
    void solve(int col, vector<vector<int> > &board, vector<vector<string>> &res, int n){
        if(col == n){
            createRes(board, res, n);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 1;
                // checkRow[0] = true;
                // checkLower[row+col] = true;
                // checkUpper[(n-1)+ col -row] = true;
                
                solve(col+1, board, res, n);
                board[row][col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int> > board (n, vector<int> (n,0));
        
        vector<vector<string> > res;
        
        solve(0, board, res, n);
        return res;
    }
};