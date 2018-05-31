#include <iostream>
#include <vector>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {return false; }
        return psum(root, sum, 0);
    }
private:    
    bool psum(TreeNode* node, const int& sum, int cursum) {
        cursum += node->val;
        bool ans = false;
        if (node->left != NULL) {
            ans = psum(node->left, sum, cursum);
        }
        if (node->right != NULL) {
            ans = ans || psum(node->right, sum, cursum);
        }
        if (node->right == NULL && node->left == NULL) {
            return ans || cursum == sum;
        }
        return ans;
    }
};

 
int main(int argc, char const *argv[])
{
    TreeNode r(9);
    TreeNode r2(6);
    r.right = &r2;
    Solution s;
    std::cout << s.hasPathSum(&r, 9);
    return 0;
}
