#include<iostream>
using namespace std;

//Cấu trúc một Node của cây
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
//Hàm kiểm tra xem 2 cây có đối xứng nhau hay không
class Solution {
public:
     bool isSymmetric(TreeNode* left, TreeNode* right){
        if(!left && !right) return true; //Cây rỗng là cây đối xứng
        if(!left || !right) return false; //Một trong hai cây con trái/ phải rỗng -> không đối xứng
        return (left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
    }
};
int main(){
 Solution sl;
 // Tạo cây thứ nhất
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->left = new TreeNode(4);
    tree1->left->right = new TreeNode(5);

    // Tạo cây thứ hai giống hệt cây thứ nhất
    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->right->left = new TreeNode(4);
    tree2->right->right = new TreeNode(5);

    // Tạo cây thứ ba khác
    TreeNode *tree3 = new TreeNode(1);
    tree3->left = new TreeNode(3);
    tree3->right = new TreeNode(2);
    tree3->right->left = new TreeNode(5);
    tree3->right->right = new TreeNode(4); 

    // Kiểm thử
    cout << "Tree 1 and Tree 2 are symmetric: " << (sl.isSymmetric(tree1, tree2) ? "Yes" : "No") << endl;
    cout << "Tree 1 and Tree 3 are symmetric: " << (sl.isSymmetric(tree1, tree3) ? "Yes" : "No") << endl;

    // Xóa bộ nhớ
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete tree3->left;
    delete tree3->right;
    delete tree3;

    return 0;
}