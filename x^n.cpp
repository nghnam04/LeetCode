#include<iostream>
using namespace std;

//Hàm tính x^n
class Solution {
public:
    double myPow(double x, long n) {
        double ans  = 1;
        if(n==0)
            return 1; //x^0=1
        else if(x==0) 
            return 0; ////0^n=0
        else if(n<0){
            n = n*(-1);
            x = 1/x;
        }
        while(n){
            if(n%2==0){ //Mũ chẵn
                x = x*x;
                n = n/2;
            }
            else{ //Mũ lẻ
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