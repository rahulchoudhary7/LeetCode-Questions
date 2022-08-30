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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* start = list1;
        int count = 0;

        while(start && count<a-1){
            start = start->next;
            count++;
        }
        
        ListNode* temp = start->next;
        
        while(count<b-1){
            temp = temp->next;
            count++;
        }
        
        ListNode* temp2 = list2;
        
        while(temp2->next){
            temp2 = temp2->next;
        }
        
        start->next = list2;
        
        if(temp) temp2->next = temp->next;
        return list1;
        
    }
};