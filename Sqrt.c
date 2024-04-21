#include<stdio.h>
//Hàm tính căn bậc hai của một số, làm tròn chỉ lấy phần nguyên
int mySqrt(int x) {
     if (x == 0)
            return x;
            //Sử dụng ctdl binary search tree
        int first = 1, last = x;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (mid  == x / mid)
                return mid;
            else if (mid > x / mid) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        return last;
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d", mySqrt(x));
    return 0;
}