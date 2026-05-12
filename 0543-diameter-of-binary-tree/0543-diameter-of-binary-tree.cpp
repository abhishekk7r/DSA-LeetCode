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
public:
    int diameter = 0;

    int helper(TreeNode* root){
        if(root == nullptr) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        // Diameter through current node = left subtree height + right subtree height.
        // Keep track of maximum diameter seen anywhere in the tree.
        diameter = max(diameter, left + right);

        //Why add 1? height = current node + taller subtree
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return diameter;
    }
};