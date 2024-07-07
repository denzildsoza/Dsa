#include "../headers.h"

int is_palindrome(char string[],int beg,int end)
{
    if(beg==end){
        return 1;
    }
    if(string[beg]==string[end]){
        return is_palindrome(string,beg+1,end-1);
    }
    else{
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    char ch[] = "racecar";
    int size = strlen(ch);
    int is_palindr = is_palindrome(ch,0,size-1);
    printf("%d",is_palindr);
    return 0;
}
