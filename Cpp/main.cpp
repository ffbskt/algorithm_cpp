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
        st.push(root);
        while (true) {
            TreeNode* node = st.top();
            if (node->left != NULL) {
                st.push(node->left);
            } else {
                while (node->right == NULL) {
                    vec.push_back(node->val);
                    st.pop();
                    if (st.empty()) {
                        return vec;
                    }   
                }
                vec.push_back(node->val);
                st.pop();
                //if (st.empty()) {
                //    return vec;
                //}    
                st.push(node->right);
            }
        }
        return vec;
    }
};

void inorderTraversal(TreeNode* root) {
    std::cout << "ss"<< root->val;
    if (root->left != NULL) {
        inorderTraversal(root->left);
    }
    std::cout << root->val;
    if (root->right != NULL) {
        inorderTraversal(root->right);
    }
}

std::vector<TreeNode> AddNode(const std::vector<int>& vec, int cur_it, TreeNode* root) {
    std::cout << cur_it << " " << vec[cur_it];
    std::vector<TreeNode> tree(0, vec.size());
    // for (int i; i < vec.size(); ++i) {

    // }
    //if (cur_it < vec.size()) {
    //    if (vec[cur_it] != 0) {
    //        TreeNode node(vec[cur_it]);
    //        root->left = &node;
    //        std::cout << "{" << node.val << "\n";
    //        AddNode(vec, 2 * cur_it - 1, &node);     
    //    } else {
    //        root->left = nullptr;
    //    }
    //} else {
    //     root->left = nullptr;
    //     root->right = nullptr;
    // }
    // if (cur_it < vec.size()) {
    //     if (vec[cur_it] != 0) {
    //         TreeNode node(vec[cur_it]);
    //         root->right = &node;
    //         std::cout << "{" << node.val << "\n";
    //         AddNode(vec, 2 * cur_it, &node);     
    //     } else {
    //         root->right = nullptr;
    //     }
    // }
    return tree;
}

struct node {
    int v = -1;
    node* u = NULL;
    ~node() {v = 909; std::cout<<"destroy";}
};


class H {
  public:
    void cl(node* root) {
        node u;
        u.v = 100;
        
        Q.push(u);
        root->u = &(Q.front());
        //return k;
    }
  std::queue<node> Q;  
};


int main(int argc, char const *argv[])
{
    node y;
    H h;
    h.cl(&y);
    std::cout << y.u->v << "\n";
    //cl(&y);
    //std::cout << y.u->v << "\n";
    return 0;
}
//     //int myints[] = {1, 0, 2, 3};
//     std::vector<int> vec{1, 0, 2, 3};

//     TreeNode root(vec[0]);
//     AddNode(vec, 1, &root);

//     std::cout << root.val;// << root.right->val << "\n";

//     //inorderTraversal(&root);

//     Solution s;
//     // std::vector<int> iv{1,2,3};
//     std::vector<int> v{1}; //= s.inorderTraversal(&root);
//     std::cout << "\n Ans \n";
//     for (int i=0; i<v.size(); ++i) {
//         std::cout << v[i] << "\n";
//     }
    
//     return 0;
// }
