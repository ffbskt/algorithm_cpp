#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
       if (inorder.empty()) {
           return NULL;
       }
       root = TreeNode(postorder.back());
       treevec.push_back(root); // without this string return boolsheet why?
       //treevec.assign(inorder.size(), -1);   
       AddNode(&root, inorder, postorder);
       //std::cout << (root.val == treevec[0].val) <<"\n";
       return &root;   
    }
    Solution() : root(0), treevec() {}

    //TreeNode() {}
//private:
  void AddNode(TreeNode* root, std::vector<int> ino, std::vector<int> po) {
    int lind = find(ino, root->val);
    int pind = find(po, root->val);
    if (lind && pind > find(po, ino[lind - 1])) {
        treevec.push_back(TreeNode(ino[lind - 1]));
        root->left = &treevec.back();
        AddNode(root->left, ino, po);
    } else {
        //treevec.push_back(TreeNode(-1));
        root->left = NULL;
    }
    if (pind && lind < find(ino, po[pind - 1])) {
        treevec.push_back(TreeNode(po[pind - 1]));
        root->right = &treevec.back();
        AddNode(root->right, ino, po);
    } else {
        //treevec.push_back(TreeNode(-1));
        root->right = NULL;
    }
  }

  int find(const std::vector<int>& vec, int val) {
      //std::ptrdiff_t 
      std::ptrdiff_t pos = std::find(vec.begin(), vec.end(), val) - vec.begin();
      return pos;    
  }
  private:
      std::vector<TreeNode> treevec;
      TreeNode root;
};


int main(int argc, char const *argv[])
{
    std::vector<int> po{9,15,7,20,3};
    std::vector<int> ino{9,3,15,20,7};
    Solution s;
    TreeNode* r = s.buildTree(ino, po);
    std::cout << r->val << r->left->val;
    return 0;
}