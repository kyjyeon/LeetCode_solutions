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
public:
    int maxDepth(TreeNode* root) {
        if (!root) //If root does not exist, return 0
            return 0;
        else
            //return the maximum int between two recursive function + 1(curnode)
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};