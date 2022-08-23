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
    ListNode* mid(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }
        // ListNode* fast = head;//THis statement will give you
        //Second mid point:

        //THis below statement will always give you
        //first mid point:
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void ReverseLL(ListNode*& head) {
        ListNode*current = head;
        ListNode* prev = NULL;
        ListNode* n;

        while (current != NULL) {
            n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        head = prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* m = mid(head);
        ListNode* h = head;
        ListNode* h1 = m->next;
        m->next = NULL;
        ReverseLL(h1);

        while (h and h1) {
            if (h->val != h1->val) {
                return false;
            }
            h = h->next;
            h1 = h1->next;
        }
        return true;
    }
};