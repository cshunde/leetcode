/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }
        ListNode* kGroupHead = head;
        int step = k;
        while (head != nullptr && step > 1) {
            head = head->next;
            step--;
        }
        ListNode* kGroupTail = head;
        // If the number of nodes is not a multiple of k 
        // then left-out nodes in the end should remain as it is
        if (kGroupTail == nullptr) {
            return kGroupHead;
        }
        ListNode* remainHead = kGroupTail->next;
        kGroupTail->next = nullptr;

        ListNode* newHead = reverse(kGroupHead);
        kGroupHead->next = reverseKGroup(remainHead, k);

        return newHead;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* tail = nullptr;
        while(head != nullptr) {
            ListNode* p = head;
            head = head->next;
            p->next = tail;
            tail = p;
        }
        return tail; 
    }
};
