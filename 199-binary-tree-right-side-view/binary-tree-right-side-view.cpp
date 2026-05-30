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
    vector<int> rightView;

    void helper(TreeNode* node, int level){
        if(level == rightView.size()){
            rightView.push_back(node->val);
        }
        
        if(node->right != NULL) helper(node->right, level+1);
        if(node->left != NULL) helper(node->left, level+1);

    }

    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return rightView;

        helper(root, 0);
        return rightView;
    }
};