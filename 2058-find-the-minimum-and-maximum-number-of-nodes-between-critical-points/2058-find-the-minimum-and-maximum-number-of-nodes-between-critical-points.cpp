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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* curr = head->next;
        ListNode* prev = head;
        int m =2;
        vector<int> ans(m,-1);
        
        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;
        
        vector<int> indexes;
        int count=0;
        
        while(curr->next){
            if((curr->next->val < curr->val && prev->val < curr->val) or (curr->next->val > curr->val && prev->val > curr->val)) {
                indexes.push_back(count);
            }
            count++;
            curr = curr->next;
            prev = prev->next;
        }
        
        int n = indexes.size();
        if(n==0 or n==1) return ans;
        
        maxDistance = indexes[n-1]-indexes[0];
        int j = 0;
        for(int i=0; i<n-1; i++){
            
            j = i + 1;
            
            minDistance = min(minDistance, indexes[j]-indexes[i]);
            
        }
        ans[0] = minDistance;
        ans[1] = maxDistance;
        return ans;
        
    }
};