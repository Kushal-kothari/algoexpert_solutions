#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array)
{
    // Write your code here.
    for (int end = array.size() - 1; end >= 0; end--)
    {
        for (int i = 0; i < end; i++)
        {
            if (array[i] > array[i + 1])
                swap(array[i], array[i + 1]);
        }
    }
    return array;
}
