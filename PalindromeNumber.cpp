#include<iostream>
using namespace std;
bool isPalindrome(int x){
if(x<0 || (x!=0 && x%10==0)) return false;
int temp=0;
while(x>temp){
    temp=(temp*10)+(x%10);
    x%10;
}
return x==temp;
}
int main(){
    int a;
    cin >> a;
    cout << isPalindrome(a);
    return 0;
}