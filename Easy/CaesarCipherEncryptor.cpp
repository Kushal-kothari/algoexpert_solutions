#include <string>
using namespace std;

string caesarCypherEncryptor(string str, int key)
{
    // Write your code here.
    string res;
    for (auto c : str)
    {
        int diff = (c - 'a' + key) % 26;
        char temp = 'a' + diff;
        res += temp;
    }
    return res;
}
