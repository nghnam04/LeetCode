#include<iostream>
using namespace std;
//Hàm đếm số cách để đi được số bậc thang nhập vào từ bàn phím, mỗi bước đi 1 hoặc 2 bậc
class Solution{
    public:
    int climbStairs(int n) {
        int secondLast = 1;
        int last = 1;
        int sum = 0;
        for(int i=2;i<=n;i++) {
            sum = last + secondLast;
            secondLast = last;
            last = sum;
        }
        return last;
    }
};


int main(){
    Solution solution;
    int n;
    cout << "Nhập vào số bậc thang: ";
    cin >> n;
    cout << "Số cách khác nhau để đi được số bậc thang là: " << solution.climbStairs(n);
    return 0;
}