#include <iostream>
#include <vector>
#include <stack>
#include <queue>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        std::stack<TreeNode*> st;
        if (root == NULL) {
            return vec;
        }
        TreeNode* node = root;
        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else if (!st.empty()) {
                node = st.top();
                st.pop(); 
                vec.push_back(node->val);
                node = node->right;
            } else {
                return vec;      
            } 
        
        }
    }
};

void inorderTraversal(TreeNode* root, std::vector<int>* vec) {
    //std::cout << "ss"<< root->val;
    if (root->left != NULL) {
        inorderTraversal(root->left, vec);
    }
    vec->push_back(root->val);
    if (root->right != NULL) {
        inorderTraversal(root->right, vec);
    }
}

std::vector<int> IT(TreeNode* root) {
    std::vector<int> vec;
    inorderTraversal(root, &vec);
    return vec;
}

std::vector<TreeNode> AddNodes(const std::vector<int>& vec) {
    std::vector<TreeNode> tree(vec.size(), 0);
    // std::cout << cur_it << " " << tree.size();
    
    for (int i = 0; i < vec.size(); ++i) {
        tree[i].val = vec[i];
        if (2 * i + 2 < vec.size() && vec[2 * i + 2] != 0) {
            std::cout<<"right";
            tree[i].right = &tree[2 * i + 2];
        }
        if (2 * i + 1 < vec.size() && vec[2 * i + 1] != 0) {
            std::cout<<"left";
            tree[i].left = &tree[2 * i + 1];
        }
        
    }
    return tree;
}



int main(int argc, char const *argv[])
{
    
    //int myints[] = {1, 0, 2, 0, 0, 3};
    std::vector<int> vec{1, 0, 2, 0, 0, 3};

    
    std::vector<TreeNode> tv = AddNodes(vec);
    TreeNode* root = &tv[0];

    std::cout << root->val << root->right->val << root->right->left->val<< "\n";
    std::cout << tv[0].val << tv[1].val << "\n";

    //std::vector<int> v = IT(root);

    Solution s;
    // std::vector<int> iv{1,2,3};
    std::vector<int> v = s.inorderTraversal(root);
    std::cout << "\n Ans \n";
    for (int i=0; i<v.size(); ++i) {
        std::cout << v[i] << "\n";
    }
    
    return 0;
}
