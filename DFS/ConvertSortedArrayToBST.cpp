/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//Reference
//Own comments added to understand each code lines
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& num) {
        //Base case
        if (num.size() == 0) return NULL;   //if size is 0 no node exists, so return NULL
        if (num.size() == 1)                //if size is 1 only one node exists, so just return one node without any additional code;
            return new TreeNode(num[0]);


        //General Case
        //Question refered "the depth of the two subtrees of every node never differ by more than 1."
        //Meaning pivot has to be middle to balance the BST;
        int middle = num.size() / 2; 

        //Create a new TreeNode with putting middle value of the vector to TreeNode val
        TreeNode* root = new TreeNode(num[middle]);

        //Based on pivot(middle index), divide into left, right side
        //Because BST has the root val's left side always contains smaller value, while right side always must contain larger value;
        //If its 0 1 2, root val should be 1 to make 0 be left child and 1 be right child
        vector<int> leftInts(num.begin(), num.begin() + middle);
        vector<int> rightInts(num.begin() + middle + 1, num.end());

        //Most important part(DFS recursive)
        //Divide the vector left/right until it meets the BaseCase
        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);

        return root;
    }
};

//My code(Wrong approach... Gotta work harder to get used to DFS/BFS algo.....)
class Solution {
public:
    void InsertNode(TreeNode*& root, vector<int>& nums, int curIndex, int mid) {
        if (curIndex < 0 || curIndex == mid)
            return;

        TreeNode* newNode = new TreeNode(nums[curIndex]);

        if (nums[curIndex] < nums[mid]) {
            root->left = newNode;
            --curIndex;
            InsertNode(newNode, nums, curIndex, mid);
        }
        else if (nums[curIndex] > nums[mid]) {
            if (root->val == nums[mid])
                root->right = newNode;
            else
                root->left = newNode;

            --curIndex;
            InsertNode(newNode, nums, curIndex, mid);
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        if (nums.size() == 1) {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        if (nums.size() == 2) {
            TreeNode* root = new TreeNode(nums[0]);
            TreeNode* newNode = new TreeNode(nums[1]);
            root->right = newNode;
            return root;
        }

        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        InsertNode(root, nums, mid - 1, mid);
        InsertNode(root, nums, nums.size() - 1, mid);

        return root;
    }
};