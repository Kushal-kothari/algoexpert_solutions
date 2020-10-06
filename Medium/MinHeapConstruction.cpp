#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap
{
public:
    vector<int> heap;

    MinHeap(vector<int> vector) { heap = buildHeap(vector); }

    vector<int> buildHeap(vector<int> &vector)
    {
        int firstParentIdx = (vector.size() - 2) / 2;
        for (int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--)
        {
            siftDown(currentIdx, vector.size() - 1, vector);
        }
        return vector;
    }

    void siftDown(int currentIdx, int endIdx, vector<int> &heap)
    {
        int childOneIdx = currentIdx * 2 + 1;
        while (childOneIdx <= endIdx)
        {
            int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
            int idxToSwap = (childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx]) ? childTwoIdx : childOneIdx;
            if (heap[idxToSwap] >= heap[currentIdx]) return;
            swap(heap[idxToSwap], heap[currentIdx]);
            currentIdx = idxToSwap;
            childOneIdx = currentIdx * 2 + 1;
        }
    }

    void siftUp(int currentIdx, vector<int> &heap)
    {
        int parentIdx = (currentIdx - 1) / 2;
        while (currentIdx > 0 && heap[currentIdx] < heap[parentIdx])
        {
            swap(heap[currentIdx], heap[parentIdx]);
            currentIdx = parentIdx;
            parentIdx = (currentIdx - 1) / 2;
        }
    }

    int peek()
    {
        return heap[0];
    }

    int remove()
    {
        swap(heap[0], heap[heap.size() - 1]);
        int valueToRemove = heap.back();
        heap.pop_back();
        siftDown(0, heap.size() - 1, heap);
        return valueToRemove;
    }

    void insert(int value)
    {
        heap.push_back(value);
        siftUp(heap.size() - 1, heap);
    }
};
