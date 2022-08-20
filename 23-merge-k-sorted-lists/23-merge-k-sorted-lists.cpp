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
class Compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return (a->val > b->val);
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for(int i=0; i<k; i++){
            ListNode* temp = lists[i];
            if(temp) pq.push(temp);
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        
        while(pq.size()>0){
            ListNode* temp = pq.top();
            pq.pop();
            
            tail->next = temp;
            tail = temp;
            
            if(temp->next) pq.push(temp->next);
        }
        return dummy->next;
    }
};