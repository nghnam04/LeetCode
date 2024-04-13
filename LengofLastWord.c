#include<stdio.h>
#include<string.h>

//Hàm in ra độ dài của từ cuối cùng
int lengthOfLastWord(char* s) {
    int length=0;
    int lengthS = strlen(s)-1;
     //Loại bỏ các khoảng trắng cuối xâu trước khi đếm độ dài từ cuối cùng
    while(s[lengthS] == ' ' && lengthS>=0){
       lengthS--;
    }
    for(int i=lengthS; i>=0; i--){ //Duyệt từ cuối xâu trở về
        if(s[i] != ' ') length++;
        else break;
    }
    return length;
}

    int main(){
        char s[100];
        fgets(s, sizeof(s), stdin);
        printf("The length of last word is %d", lengthOfLastWord(&s));
    }