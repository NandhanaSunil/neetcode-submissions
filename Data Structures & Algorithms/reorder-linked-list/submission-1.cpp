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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        if (head == nullptr || head->next == nullptr) return;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is in the middle of the list

        ListNode* cur = slow->next;
        ListNode* nex = cur ->next;
        slow->next = nullptr;
        cur ->next = nullptr;

        while(nex!=nullptr){
            ListNode* secnext = nex->next;
            nex->next = cur;
            cur = nex;
            nex = secnext;
        }
        // ListNode* print = cur;
        // while (print!=nullptr){
        //     cout << print -> val << " ";
        //     print = print ->next;
        // }
        // cout << endl;
        ListNode* start = head;

        while(cur != nullptr){
            ListNode* startnex = start->next;
            ListNode* curnext = cur->next;
            start->next = cur;
            cout << "s : " << start->val << " e : " << cur->val <<endl;
            cur ->next = startnex;
            start = startnex;
            cur = curnext;
        }
        
        // return head;
    }
};
