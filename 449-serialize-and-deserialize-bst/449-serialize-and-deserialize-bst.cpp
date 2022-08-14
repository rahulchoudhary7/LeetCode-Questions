/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        string s ="";
        if(!root) return s;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front == NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(front->val));
                s.append(",");
                q.push(front->left);
                q.push(front->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n==0) return NULL;
        
        stringstream ss(data);
        string str;
        getline(ss, str,',');
        
        TreeNode* newRoot = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(newRoot);
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            
            getline(ss, str, ',');
            
            if(str == "#"){
                frontNode->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                frontNode->left = leftNode;
                q.push(leftNode);
            }
                        
            
            getline(ss, str, ',');
            
            if(str == "#"){
                frontNode->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                frontNode->right = rightNode;
                q.push(rightNode);
            }
            
        }
        return newRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;