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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while(list1!= nullptr || list2!=nullptr){
            if(head == nullptr){
                if (list1 == nullptr){
                    head = new ListNode(list2->val);
                    list2 = list2->next;
                }
                else if (list2 == nullptr){
                    head = new ListNode(list1-> val);
                    list1 = list1-> next;
                }
                else{
                    if(list1->val < list2->val){
                        head = new ListNode(list1->val);
                        list1 = list1->next;
                    }
                    else{
                        head = new ListNode(list2->val);
                        list2 = list2->next;
                    }
                }
                cur = head;
            }
            else{
                if(list1 == nullptr){
                    cur->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                else if (list2 == nullptr){
                    cur->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else{
                    if(list1->val < list2->val){
                        cur->next = new ListNode(list1->val);
                        list1 = list1->next;
                    }
                    else{
                        cur->next = new ListNode(list2->val);
                        list2 = list2->next;
                    }
                }
                cur = cur->next;
            }
        }
        return head;
    }
};
