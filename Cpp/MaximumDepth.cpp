#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ans = 1;
        int depth = 1;
        md(root, depth, &ans);
        return ans;
    }
    
    void md(TreeNode* node, int depth, int* maxans) {
        if (node == NULL) {
            return;
        }
        *maxans = std::max(depth, *maxans);
        md(node->left, depth + 1, maxans);
        md(node->right, depth + 1, maxans);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode r(9);
    std::cout << s.maxDepth(&r);
    return 0;
}
