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
private:
    int max_sum;
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
    int dfs(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        int left_sum = dfs(node -> left);
        int right_sum = dfs(node -> right);
        max_sum = max(max_sum, node -> val + left_sum + right_sum);
        return max(0, node -> val + max(left_sum, right_sum));
    }
};
