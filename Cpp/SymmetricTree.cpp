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
    bool isSymmetric(TreeNode* root) {
      if (root == NULL) {
          return true;
      }
      std::vector<int> ltree;
      std::vector<int> rtree;
      PreordTR(root->left, &ltree);
      PreordTL(root->right, &rtree);
      for (int i = 0; i < ltree.size(); ++i) {
          if (ltree.size() != rtree.size()) {
              return false;  
          }
          if (ltree[i] != rtree[i]) {
              return false;
          }
      }
      return true;  
    }

    void PreordTR(TreeNode* node, std::vector<int>* vec) {
        if (node == NULL) {
            vec->push_back(-1);
            return;
        }
        vec->push_back(node->val);
        PreordTR(node->left, vec);
        PreordTR(node->right, vec);
    } 
    void PreordTL(TreeNode* node, std::vector<int>* vec) {
        if (node == NULL) {
            vec->push_back(-1);
            return;
        }
        vec->push_back(node->val);
        PreordTL(node->right, vec);
        PreordTL(node->left, vec);
        
    } 
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode r(9);
    TreeNode r2(3);
    r.right = &r2;
    std::cout << s.isSymmetric(&r);
    return 0;
}