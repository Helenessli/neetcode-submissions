class Solution {
public:
    int dfs(TreeNode* root, int &maxDia) {
        if (!root) {
            return 0;
        }

        int leftHeight = dfs(root->left, maxDia);
        int rightHeight = dfs(root->right, maxDia);

        // Diameter passing through this node
        maxDia = max(maxDia, leftHeight + rightHeight);

        // Return height of this subtree
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        dfs(root, maxDia);
        return maxDia;
    }
};