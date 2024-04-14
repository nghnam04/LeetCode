#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
    
int main(){
    int m, n;
    cout << "Nhap m: "; cin >> m; cout << endl;
    cout << "Nhap n: "; cin >> m; cout << endl;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, m, nums2, n);
    for(int v : nums1){
        cout << v <<" ";
    }
    return 0;
}