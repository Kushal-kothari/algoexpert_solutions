#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array)
{
    // Write your code here.
    for (int i = 0; i < array.size(); i++)
    {
        int min_index = i;
        for (int j = i; j < array.size(); j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        swap(array[i], array[min_index]);
    }
    return array;
}
