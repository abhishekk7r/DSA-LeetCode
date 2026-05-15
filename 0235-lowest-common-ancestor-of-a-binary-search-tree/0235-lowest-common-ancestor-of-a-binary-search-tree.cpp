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
    TreeNode* lca(TreeNode* root, TreeNode* s, TreeNode* l){
        if(root == nullptr || root->val == s->val || root->val == l->val){
            return root;
        }

        if(root->val < s->val && root->val < l->val){
            return lca(root -> right, s, l);
        } else if (root->val > s->val && root->val > l->val){
            return lca(root -> left, s, l);
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* small = nullptr; TreeNode* large = nullptr;

        if(p->val < q->val){
            small = p;
            large = q;
        } else {
            small = q;
            large = p;
        }

        return lca(root, small, large); 
    }
};