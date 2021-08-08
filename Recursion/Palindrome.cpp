#include <bits/stdc++.h>
using namespace std;


bool checkValid(char c)
{
    if ( c >= 'A' && c  <= 'Z')
    return true;
    else if ( c >= 'a' && c <= 'z' )
    return true;
    else if ( c >= '0' && c <= '9')
    return true;

    return false;
}


bool isPalindrome(int start, int end, string str)
{

    if(start > end) return true;

    if(!checkValid(str[start]))
    {
        return isPalindrome(start+1,end,str);
    }

    else if(!checkValid(str[end]))
    {
        return isPalindrome(start,end-1,str);
    }

    else if(str[start] != str[end])
    {
        return false;
    }

    return isPalindrome(start+1, end-1, str);


}

int main()
{
    string str;
    getline(cin, str);
    // cout<<str;

    if(isPalindrome(0, str.length(), str))
    {
        printf("Palindrome\n");
    }
    else printf("Nope\n");
    return 0;

}
