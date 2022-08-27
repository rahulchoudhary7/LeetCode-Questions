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
private:
    ListNode* reverse(ListNode* curr, int &count){
        ListNode* prev = NULL;
        while(curr){
            count++;
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // vector<int> ans;
        
        // ListNode* curr = head;
        
        // while(curr){
        //     ListNode* temp = curr;
        //     while(curr!=NULL && curr->val <= temp->val){
        //         curr = curr->next;
        //     }
        //     if(curr)
        //         ans.push_back(curr->val);
        //     else
        //         ans.push_back(0);
        //     curr = temp->next;
        // }
        
        int count = 0;
        ListNode* newHead = reverse(head, count);
        
        ListNode* temp = newHead;
        
        while(temp){
            cout<<temp->val;
            temp = temp->next;
        }
        
        vector<int> ans(count);
        int n = count-1;
        ListNode* curr = newHead;
        stack<int> s;
        s.push(0);
        
        while(n>=0 && curr){
            while(s.top()!=0 && s.top() <= curr->val){
               s.pop();
            }
            ans[n--] = s.top();
            s.push(curr->val);
            curr = curr->next;
        }
        
        return ans;
    }
};