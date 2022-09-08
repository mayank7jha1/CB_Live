/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, bool>um;
    int camera;

    void PlaceCamera(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return;
        }

        PlaceCamera(root->left, root);
        PlaceCamera(root->right, root);

        if ((parent == NULL and um.count(root) == 0) or um.count(root->left) == 0 or um.count(root->right) == 0) {
            camera++;
            um[parent] = true;
            um[root] = true;
            um[root->left] = true;
            um[root->right] = true;
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        camera = 0;
        um.insert({NULL, true});
        PlaceCamera(root, NULL);
        return camera;
    }
};