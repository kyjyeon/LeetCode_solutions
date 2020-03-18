/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//First time getting clean accepted proper DFS code by myself! (Runtime: 0 ms, faster than 100.00%, Memory Usage: 13.8 MB, less than 100.00% of C++ online submissions)

//Important personal TIP for solving DFS problems : Think of the big picture of the whole process and start coding
//imagining all the minor exception will make it complicated
class Solution {
public:
    //We wanna check that based on each node, if the left and right side is symmetric. So get leftSide and rightSide of root for parameter and flag for &
    void helper(TreeNode* left, TreeNode* right, bool& flag) {
        //if left exists and right is null, it's not symmetric
        if (left && !right)
            flag = false;
        //if right exists and left is null, it's not symmetric
        if (!left && right)
            flag = false;
        //if both exists but the values of left/right aren't same(because it's symmetric you need to compare left and right not left and left), it's not symmetric
        if (left && right) {
            if (left->val != right->val)
                flag = false;

            //Check if leftTree's left side is symmetric with rightTree's right side
            helper(left->left, right->right, flag);
            //Check if leftTree's right side is symmetric with rightTree's left side
            helper(left->right, right->left, flag);
        }

    }

    bool isSymmetric(TreeNode* root) {
        //flag for checking if TreeNode is Symmetric or not
        bool flag = true;
        if (root)
            helper(root->left, root->right, flag);

        return flag;
    }
};