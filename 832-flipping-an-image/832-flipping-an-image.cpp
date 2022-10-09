class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for(int i=0; i<n; i++){
            int s=0, e = n-1;
            while(s<e){
                swap(image[i][s++], image[i][e--]);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(image[i][j]==1) image[i][j] = 0;
                else image[i][j] = 1;
            }
        }
        return image;
    }
};