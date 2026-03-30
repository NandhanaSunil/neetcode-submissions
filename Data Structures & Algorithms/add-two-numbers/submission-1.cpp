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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int sum = 0;
        int carry = 0;

        sum = (carry + l1->val + l2->val)%10;
        carry = (carry + l1->val + l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        cur -> val = sum;

        while (l1!=nullptr || l2!=nullptr){
            if(l1 == nullptr){
                sum = (carry + l2->val)%10;
                carry = (carry + l2->val)/10;
                l2 = l2->next;
                cur->next = new ListNode(sum);
                cur = cur -> next;
            }
            else if (l2 == nullptr){
                sum = (carry + l1->val)%10;
                carry = (carry + l1->val)/10;
                l1 = l1->next;
                cur->next = new ListNode(sum);
                cur = cur ->next;
            }
            else{
                sum = (carry + l1->val + l2->val)%10;
                carry = (carry + l1->val + l2->val)/10;
                l1 = l1->next;
                l2 = l2->next;
                cur->next = new ListNode(sum);
                cur = cur ->next;
            }
        }
        if (carry > 0){
            cur->next = new ListNode(carry);
        }
        return head;
    }
};
