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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int total = 0;
        while(cur != nullptr){
            cur = cur -> next;
            total++;
        }
        int i = total - n;
        ListNode* start = head;
        if (i == 0) return head->next;
        int c = 1;
        while(c<i){
            start = start->next;
            c++;
        }
        start->next = start->next->next;
        return head;
    }
};
