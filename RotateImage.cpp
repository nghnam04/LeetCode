#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
//Hàm quay ma trận vuông 90 độ sang phải
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Swap các phần tử đối xứng qua đường chéo chính (Bỏ qua các phần tử ở đường chéo chính)
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]); 
            }
        }
        //Reverse từng hàng của matrix mới
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){
    Solution sl;
    vector<vector<int>> vt = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = vt.size();
    sl.rotate(vt);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << vt[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}