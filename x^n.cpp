#include<iostream>
using namespace std;

//Hàm tính x^n
class Solution {
public:
    double myPow(double x, long n) {
        double ans  = 1;
        if(n==0)
            return 1;
        else if(x==0)
            return 0;
        else if(n<0){
            n = n*(-1);
            x = 1/x;
        }
        while(n){
            if(n%2==0){
                x = x*x;
                n = n/2;
            }
            else{
                n = n-1;
                ans = ans*x;
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    int x, n;
    cin >> x >> n;
    cout << solution.myPow(x, n);
    return 0;
}