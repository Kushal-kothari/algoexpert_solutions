#include <vector>
using namespace std;

void quickSort(vector<int>& array, int left, int right);
int partition(vector<int>& array, int left, int right);

vector<int> quickSort(vector<int> array)
{
    quickSort(array, 0, array.size() - 1);
    return array;
}

void quickSort(vector<int>& array, int left, int right)
{
    if (left >= right)
        return;
    int pivotIdx = partition(array, left, right);
    quickSort(array, left, pivotIdx - 1);
    quickSort(array, pivotIdx + 1, right);
}

int partition(vector<int>& array, int left, int right)
{
    int randIdx = rand() % (right - left + 1) + left;
    swap(array[left], array[randIdx]);

    int pivot = array[left];
    int i = left + 1;
    int j = right;
    while (i <= j)
    {
        if (array[i] > pivot && array[j] < pivot)
        {
            swap(array[i], array[j]);
        }
        if (array[i] <= pivot)
        {
            i++;
        }
        if (array[j] >= pivot)
        {
            j--;
        }
    }
    swap(array[left], array[j]);
    return j;
}
