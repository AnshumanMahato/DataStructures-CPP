#include <bits/stdc++.h>

using namespace std;

int pallindrome_substring(string str,int L,int R)
{

}

string longestPalindromicString(string str)
{
    string max_substr="";
    for(int i=0; i < str.size(); i++)
    {
        int len1 = pallindrome_substring(str,i,i),
            len2 = pallindrome_substring(str,i,i+1);
        if(len1 > len2 && len1 > max_substr.size())
        {
            max_substr = str.substr((i-len1/2),len1);
        }

        else if(len2 > max_substr.size())
        {
            max_substr = str.substr((i+1-len2/2),len2);
        }
    }

    return max_substr;
}

int main()
{
    string input;
    cin >> input;
    cout << longestPalindromicString(input);
    return 0;
}