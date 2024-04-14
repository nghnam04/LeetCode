#include<iostream>
#include<vector>
using namespace std;
//Hàm loại bỏ các giá trị val có trong vector nums và sắp xếp lại vector(nếu gặp val đổi chỗ phần tử val với phần tử tương ứng đầu bên kia vector)
int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        if(nums.size()==1){ //Nếu vector có 1 phần tử thì xóa nó đi
            if(nums[0]==val){
                nums.pop_back();
                return 0;
            }
        }
        while(i<=j){
            if(nums[i]==val){ //Nếu gặp phần tử i có gtri val thì đổi chỗ với phần tử đầu kia vector tương ứng
                swap(nums[i],nums[j]);
                j--;
                nums.pop_back(); //Và xóa khỏi vector
            }
            else i++; //Nếu không gặp val thì tiếp tục tăng i
        }
        return nums.size();
    }
    
    int main(){
        vector<int> nums ={0,1,2,2,3,0,4,2};
        int val=2;
        cout << removeElement(nums, val) << endl;
        for(int i : nums){
            cout << i;
        }
        return 0;
    }