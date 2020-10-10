#include <vector>
#include <queue>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array)
{
    priority_queue<int> q;
    for (auto i : array)
    {
        q.push(i);
    }

    vector<int> res(3, 0);
    for (int i = 2; i >= 0; i--)
    {
        res[i] = q.top();
        q.pop();
    }
    return res;
}
