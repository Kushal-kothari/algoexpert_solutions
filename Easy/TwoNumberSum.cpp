#include <vector>
#include <algorithm>
using namespace std;

/********************* Solution 1 *********************/
vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    sort(array.begin(), array.end());
    int left = 0;
    int right = array.size() - 1;
    while (left < right)
    {
        int sum = array[left] + array[right];
        if (sum == targetSum)
        {
            return vector<int>{array[left], array[right]};
        }
        if (sum > targetSum)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return {};
}


/********************* Solution 2 *********************/
// vector<int> twoNumberSum(vector<int> array, int targetSum)
// {
//     sort(array.begin(), array.end());
//     int left = 0;
//     int right = array.size() - 1;
//     while (left < right)
//     {
//         int sum = array[left] + array[right];
//         if (sum == targetSum)
//         {
//             return vector<int>{array[left], array[right]};
//         }
//         if (sum > targetSum)
//         {
//             right--;
//         }
//         else
//         {
//             left++;
//         }
//     }
//     return {};
// }
