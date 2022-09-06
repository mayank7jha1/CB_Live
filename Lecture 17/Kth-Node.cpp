/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	unordered_map<TreeNode*, TreeNode*>um;
	unordered_set<TreeNode*>vis;

	void Connect(TreeNode* root, TreeNode* parent) {
		if (root == NULL) {
			return;
		}

		um[root] = parent;
		Connect(root->left, root);
		Connect(root->right, root);
	}

	void dfs(TreeNode* target, int k, vector<int>&ans) {
		if (target == NULL or vis.count(target) == 1) {
			return;
		}

		vis.insert(target);
		if (k == 0) {
			ans.push_back(target->val);
		}
		dfs(target->left, k - 1, ans);
		dfs(target->right, k - 1, ans);
		dfs(um[target], k - 1, ans);
	}
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		vector<int>ans;
		if (root == NULL) {
			return ans;
		}

		Connect(root, NULL);
		dfs(target, k, ans);
		return ans;
	}
};

