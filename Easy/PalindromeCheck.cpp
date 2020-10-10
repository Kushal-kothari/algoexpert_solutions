#include <string>
using namespace std;

bool isPalindrome(string str)
{
    // Write your code here.
    int len = str.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}
