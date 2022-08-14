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
            TreeNode* frontNode = q.front();
            q.pop();
            
            if(frontNode!=NULL){
                s.append(to_string(frontNode->val));
                s.append(",");
            }
            else{
                s.append("#,");
            }
            
            if(frontNode!=NULL){
                q.push(frontNode->left);
                q.push(frontNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        
        queue<TreeNode*> q;
        
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            getline(ss, str, ',');
            
            if(str=="#"){
                temp->left == NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                temp->left = leftNode;
                q.push(leftNode);
            }
            
            getline(ss, str, ',');
            if(str == "#"){
                temp->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                temp->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));