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
    void helper(TreeNode* currNode, int remainingSum, vector<int> &currNodes, vector<vector<int>> &ansPaths) {
        if(currNode == NULL) return;

        currNodes.push_back(currNode->val);

        if(remainingSum == currNode->val && currNode->left == NULL && currNode->right == NULL) {
            ansPaths.push_back(vector<int>(currNodes));
        } else {
            this->helper(currNode->left, remainingSum - currNode->val, currNodes, ansPaths);
            this->helper(currNode->right, remainingSum - currNode->val, currNodes, ansPaths);
        }

        currNodes.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ansPaths;
        vector<int> currNodes;
        this->helper(root, targetSum, currNodes, ansPaths);
        return ansPaths;
    }
};