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
    int length(ListNode* head) {
        int ans = 0;
        while (head) {
            ans++;
            head = head->next;
        }
        return ans;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = length(root);
        ListNode* head = root;
        int ElementsRemaining = n % k;
        int parts = n / k;
        int len = n / k;//Minimum Length
        int count = 1;

        vector<ListNode*>ans;
        if (parts == 0) {
            //Every part will at max contain one element only;
            for (int i = 0; i < k; i++) {
                if (head) {
                    ListNode* n = head->next;
                    head->next = NULL;
                    ans.push_back(head);
                    head = n;
                } else {
                    ans.push_back(NULL);
                }
            }
        } else {
            while (head) {
                ans.push_back(head);
                int x = ElementsRemaining > 0 ? 1 : 0;
                ElementsRemaining--;
                for (int i = 1; i < len + x; i++) {
                    head = head->next;
                }
                ListNode* n = head->next;
                head->next = NULL;
                head = n;
                count++;
                if (count == k) {
                    ans.push_back(head);
                    break;
                }
            }

        }
        return ans;
    }
};



// 1->2->3->4->5->6________->10;

// ans{1->2->3->4->NULL}
// ans{1, 5}

// ans{8->9->10}

