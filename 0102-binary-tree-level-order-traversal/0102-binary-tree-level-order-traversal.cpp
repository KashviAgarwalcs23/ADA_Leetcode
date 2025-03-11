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
    vector<vector<int>> res;
    void doLevelOrderTraversal(queue<TreeNode*> qu) {
        if (qu.empty()) {
            return;
        }
        queue<TreeNode*> newQu;
        vector<int> v;
        while (!qu.empty()) {
            TreeNode* ptr = qu.front();
            qu.pop();
            if (ptr->left)
                newQu.push(ptr->left);
            if (ptr->right)
                newQu.push(ptr->right);
            v.push_back(ptr->val);
        }
        res.push_back(v);
        doLevelOrderTraversal(newQu);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        doLevelOrderTraversal(qu);
        return res;
    }
};