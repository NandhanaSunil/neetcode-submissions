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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(l1!=nullptr && l2!=nullptr){
                if (l1->val <= l2->val){
                        cur ->next = l1;
                        l1 = l1->next;
                        cur = cur ->next;
                }
                else{
                        cur ->next = l2;
                        l2 = l2->next;
                        cur = cur->next;
                }
        }
        while(l1!=nullptr){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
        }
        while(l2!=nullptr){
                cur ->next = l2;
                l2 = l2->next;
                cur = cur->next;
        }
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n==0) return nullptr;
        ListNode* cur = lists[0];
        for (int i=1; i<n; i++){
                cur = merge(cur, lists[i]);
        }
        return cur;

    }
};
