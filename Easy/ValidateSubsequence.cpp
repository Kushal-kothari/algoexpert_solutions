#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    int seqIdx = 0;
    int arrIdx = 0;
    while (seqIdx < sequence.size() && arrIdx < array.size())
    {
        if (array[arrIdx] == sequence[seqIdx])
            seqIdx++;
        arrIdx++;
    }
    return seqIdx == sequence.size();
}
