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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode *myleft = lowestCommonAncestor(root->left, p, q);
        TreeNode *myright = lowestCommonAncestor(root->right, p, q);
        if( (myleft == p && myright == q)||(myleft == q && myright == p)) return root;
        else if(myleft != NULL || myright != NULL) return myleft!=NULL? myleft:myright;
        else return NULL;
    }
};
