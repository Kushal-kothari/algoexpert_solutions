#include <vector>
using namespace std;

void mergeSort(vector<int>& array, int l, int r);
void merge(vector<int>& array, int l, int m, int r);

vector<int> mergeSort(vector<int> array)
{
    if (array.size() < 2)
        return array;
    mergeSort(array, 0, array.size() - 1);
    return array;
}

void mergeSort(vector<int>& array, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(array, l, mid);
    mergeSort(array, mid + 1, r);
    merge(array, l, mid, r);
}

void merge(vector<int>& array, int l, int m, int r)
{
    vector<int> help(r - l + 1);
    int i = 0;
    int p1 = l;
    int p2 = m + 1;
    while (p1 <= m && p2 <= r)
    {
        help[i++] = (array[p1] <= array[p2]) ? array[p1++] : array[p2++];
    }
    while (p1 <= m)
    {
        help[i++] = array[p1++];
    }
    while (p2 <= r)
    {
        help[i++] = array[p2++];
    }
    for (int j = 0; j < help.size(); j++)
    {
        array[l + j] = help[j];
    }
}
