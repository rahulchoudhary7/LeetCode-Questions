/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:    
    TreeNode* treeBuild(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd,
                       int &index, unordered_map<int, int> &nodeToIndex){
        if(inStart>inEnd)
            return NULL;
        
        int pivot = nodeToIndex[preorder[index++]];
        
        TreeNode* root = new TreeNode(inorder[pivot]);
        
        root->left = treeBuild(preorder, inorder, inStart, pivot-1,  index, nodeToIndex);
        
        root->right = treeBuild(preorder, inorder, pivot+1, inEnd, index, nodeToIndex);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> nodeToIndex;
        
        for(int i = 0; i<n; i++){
            nodeToIndex[inorder[i]] = i;
        }
        
        int index = 0;
        TreeNode* ans = treeBuild(preorder, inorder, 0, n-1, index, nodeToIndex);
        return ans;
    }
};