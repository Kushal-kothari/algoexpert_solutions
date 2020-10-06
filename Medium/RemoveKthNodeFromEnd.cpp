#include <vector>
using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k)
{
    LinkedList* firstPtr = head;
    LinkedList* secondPtr = head;
    int counter = 1;
    while (counter <= k)
    {
        secondPtr = secondPtr->next;
        counter++;
    }

    // if the node to remove is head node
    if (secondPtr == nullptr)
    {
        head->value = head->next->value;
        head->next = head->next->next;
        return;
    }

    while (secondPtr->next != nullptr)
    {
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }
    firstPtr->next = firstPtr->next->next;
}
