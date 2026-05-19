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

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode dummy(0);
       ListNode* tail = &dummy;
        int cry =0;

        while(l1|| l2|| cry){
            int sum = cry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            tail->next = new ListNode(sum%10);
            tail = tail->next;
            cry = sum/10;
        }
        return dummy.next;
        
    }
};
