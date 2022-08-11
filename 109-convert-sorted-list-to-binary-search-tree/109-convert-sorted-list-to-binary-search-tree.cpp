/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//     TreeNode* buildTree(TreeNode* root, int data){
//         if(root == NULL){
//             TreeNode* root = new TreeNode(data);
//             return root;
//         }
        
//         if(data > root->val){
//             root->right = buildTree(root->right, data);
//         }
//         else{
//             root->left = buildTree(root->left, data);
//         }
//         return root;
//     }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        
        if(!head->next){
            TreeNode* root= new TreeNode(head->val);
            return root;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        auto mid = slow->next;
        slow->next = nullptr;
        auto root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};