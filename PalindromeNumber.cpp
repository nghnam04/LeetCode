#include<iostream>

using namespace std;
//Hàm kiểm tra xem 1 số khi reverse có chính là số đấy không
bool isPalindrome(int x){ 
if(x<0) return false;

long int temp=0, reverse = x, remainNumber; //Biến reverse để lưu lại gtri x ban đầu
while(x!=0){ //Reverse 1 số
remainNumber=x%10;
    temp=temp*10 + remainNumber;
    x/=10;
}
return reverse == temp;
}
int main(){
    int a;
    cin >> a;
     if (isPalindrome(a)) {
        cout << a << " is a palindrome." << endl;
    } else {
        cout << a << " is not a palindrome." << endl;
    }
    
    return 0;
}