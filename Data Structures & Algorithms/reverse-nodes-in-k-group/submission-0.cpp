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
    ListNode* reverse(ListNode* start, ListNode* end){
        if (start == nullptr) return start;
        ListNode* cur = start;
        ListNode* nex = cur->next;

        while(cur!=end){
                ListNode* secnex = nex->next;
                nex->next = cur;
                cur = nex;
                nex = secnex;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* start = cur;
        for(int i=1; i<k; i++){
                if (cur!=nullptr) cur = cur->next;
                else break;  
        }
        ListNode* nex = cur->next;
        ListNode* newhead = reverse(head, cur);
        head->next = nex;
        ListNode* prev = head;
        cur = nex;
        while(cur != nullptr){
                start = cur;
                // bool full = true;
                for (int i=1; i<k; i++){
                        if (cur!=nullptr) cur = cur->next;
                        else {
                                // full = false;
                                break;
                                }
                }
                if (cur!=nullptr){
                        ListNode* nex =cur->next;
                        ListNode* nextnodes = reverse(start, cur);
                        prev->next = nextnodes;
                        prev = start;
                        start->next = nex;
                        cur = nex;
                }
        }
        return newhead;
    }
};
