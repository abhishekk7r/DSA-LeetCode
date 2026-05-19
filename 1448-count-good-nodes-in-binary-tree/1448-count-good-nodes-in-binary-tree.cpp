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
    int helper(TreeNode* root, int largest)
    {
        if(root == nullptr) return 0;
        
        int res = root->val >= largest ? 1 : 0; 
        largest = max(largest, root->val);

        //dfs will carry the maxvalue of the caller node in the call 
        // and when it comes back it will use the same value for the right call
        res += helper(root->left, largest);
        res += helper(root->right, largest);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};