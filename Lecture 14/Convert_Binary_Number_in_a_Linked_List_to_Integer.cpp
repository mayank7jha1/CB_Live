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
	int getDecimalValue(ListNode* head) {
		ListNode* temp = head;
		int ans = 0;
		while (temp != NULL) {
			int value = temp->val;
			ans = (ans * 2) + value;
			temp = temp->next;
		}
		return ans;
	}
};



/*1->0->1->0->NULL;

2 ^ 3 * 1 + 2 ^ 2 * 0 + 2 ^ 1 * 1 + 2 ^ 0 * 0 = 1010
        1010 = 20;
8 + 2 = 10;*/



/*1->0->1->NULL;

101 == 5;
cout << 5;*/