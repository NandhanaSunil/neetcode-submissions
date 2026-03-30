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
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead =  nullptr;
        while(head != nullptr){
            int val =  head->val;
            head = head->next;
            if (newhead == nullptr){
                newhead = new ListNode();
                newhead-> val = val;
            }
            else{
                ListNode* newnode = new ListNode();
                newnode -> val = val;
                newnode -> next = newhead;
                newhead = newnode;
            }
        }
        return newhead;
    }
};
