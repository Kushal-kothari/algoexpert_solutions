#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target)
{
    int left = 0;
    int right = array.size() - 1;
    // [left, right]
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array[mid] > target)
        {
            right = mid - 1;
        }
        else if (array[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/********************* Solution 2 *********************/
// int binarySearch(vector<int> array, int target)
// {
//     int left = 0;
//     int right = array.size();
//     // [left, right)
//     while (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         if (array[mid] > target)
//         {
//             right = mid;
//         }
//         else if (array[mid] < target)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     return -1;
// }
