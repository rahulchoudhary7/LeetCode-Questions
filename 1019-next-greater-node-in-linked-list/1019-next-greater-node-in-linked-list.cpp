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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        
        ListNode* curr = head;
        
        while(curr){
            ListNode* temp = curr;
            while(curr!=NULL && curr->val <= temp->val){
                curr = curr->next;
            }
            if(curr)
                ans.push_back(curr->val);
            else
                ans.push_back(0);
            curr = temp->next;
        }
        return ans;
    }
};