#include<bits/stdc++.h>
using namespace std;

//Hàm duyệt cây theo thứ tự giữa
 struct TreeNode { //Định nghĩa một Node
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    private :

   void traversal(TreeNode* root,vector<int>& arr){

        if(root==NULL){
            return ;
        }
        traversal(root->left,arr);
        arr.push_back(root->val);
        traversal(root->right,arr);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> arr;
       traversal(root,arr);

       return arr;
    }
};

#include <iostream>
#include <vector>

int main() {
    // Tạo cây nhị phân để kiểm thử
    // Ví dụ về cây nhị phân:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Tạo đối tượng Solution và gọi hàm inorderTraversal
    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // In kết quả
    cout << "Inorder traversal of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
