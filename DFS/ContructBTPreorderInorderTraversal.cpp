/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Use preorder to get root node, inorder index to sepreate left/right node from the root
//Preorder always repeats Root->left->right , Inorder repeats left->root->right
//++ rootIndex by every recursion to move on to next root node in preorder vector
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //First root value will be preorder[0] since preorder always starts with root node
        int rootInex = 0;
        //Insert parameter helper(preorder vector, root Index, inorder vector, starting index location, last index location from inorder vector)
        return helper(preorder, rootInex, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int start, int end) {
        //if preorder size is 0 or lower / if starting index becomes bigger than end index
        if (rootIndex >= preorder.size() || start > end) return nullptr;

        //Create new TreeNode with preorder[rootIndex] value
        TreeNode* root = new TreeNode(preorder[rootIndex]);
        
        //auto pos = Distance between 0 ~ index location of preorder[rootIndex] value, in inorder vector
        auto pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, preorder[rootIndex]));
        //++ rootIndex to move on to next root node
        rootIndex++;
        root->left = helper(preorder, rootIndex, inorder, start, pos - 1);
        root->right = helper(preorder, rootIndex, inorder, pos + 1, end);
        return root;
        
    }
};
