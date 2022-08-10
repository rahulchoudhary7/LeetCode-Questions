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
public:
    TreeNode* buildTreeHelp(vector<int> &inorder, vector<int> &postorder, int &index, int left, int                                  right, unordered_map<int, int> &nodeToIndex){
        if(left>right)
            return NULL;
        
        int pivot = nodeToIndex[postorder[index--]];
        TreeNode* root = new TreeNode(inorder[pivot]);
        
        root->right = buildTreeHelp(inorder, postorder, index, pivot+1, right, nodeToIndex);
        root->left = buildTreeHelp(inorder, postorder, index, left, pivot-1, nodeToIndex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> nodeToIndex;
        for(int i=0; i<n; i++){
            nodeToIndex[inorder[i]] = i;
        }
        
        int index = n-1;
        
        TreeNode* root = buildTreeHelp(inorder, postorder, index, 0, n-1, nodeToIndex);
        
        return root;
    }
};