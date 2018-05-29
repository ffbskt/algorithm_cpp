#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> qu;
        std::queue<TreeNode*> bl;
        std::vector<std::vector<int>> levec;
        std::vector<int> vec;
        if (root == NULL) {
            return levec;
        }
        qu.push(root);
        while(true) {
            while (!bl.empty()) {
                qu.push(bl.front());
                bl.pop();            
            }
            
            while(!qu.empty()) {
                push(&bl, qu.front());
                vec.push_back(qu.front()->val);
                qu.pop();
            }

            levec.push_back(vec);
            vec.clear();

            if (qu.empty() && bl.empty()) {
                return levec;
            }

        }
    }
    private:
    void push(std::queue<TreeNode*>* qu, TreeNode* node) {
        if (node->right != NULL) {
            qu->push(node->right);
        }
        if (node->left != NULL) {
            qu->push(node->left);
        }
    }
};


int main() {
    Solution s;
    TreeNode root{2};
    TreeNode n1{3};
    root.left = &n1;
    std::vector<std::vector<int>> vec = s.levelOrder(&root);
    std::cout << vec[0][0];
    //s.push();
    return 0;
}