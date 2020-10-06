#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node *node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }
        insertBefore(head, node);
    }

    void setTail(Node *node)
    {
        if (tail == nullptr)
        {
            head = node;
            tail = node;
            return;
        }
        insertAfter(tail, node);
    }

    void insertBefore(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head && nodeToInsert == tail) return;
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        if (node->prev == nullptr)
        {
            head = nodeToInsert;
        }
        else
        {
            node->prev->next = nodeToInsert;
        }
        node->prev = nodeToInsert;
    }

    void insertAfter(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head && nodeToInsert == tail) return;
        remove(nodeToInsert);
        nodeToInsert->next = node->next;
        nodeToInsert->prev = node;
        if (node->next == nullptr)
        {
            tail = nodeToInsert;
        }
        else
        {
            node->next->prev = nodeToInsert;
        }
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node *nodeToInsert)
    {
        if (position == 1)
        {
            setHead(nodeToInsert);
            return;
        }
        Node* node = head;
        int currentPosition = 1;
        while (node != nullptr && currentPosition++ != position)
        {
            node = node->next;
        }
        if (node != nullptr)
        {
            insertBefore(node, nodeToInsert);
        }
        else
        {
            setTail(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value)
    {
        Node* node = head;
        while (node != nullptr)
        {
            Node* nodeToRemove = node;
            node = node->next;
            if (nodeToRemove->value == value)
            {
                remove(nodeToRemove);
            }
        }
    }

    void remove(Node *node)
    {
        if (node == head)
        {
            head = head->next;
        }
        if (node == tail)
        {
            tail = tail->prev;
        }
        removeNodeBindings(node);
    }

    void removeNodeBindings(Node* node)
    {
        if (node->prev != nullptr) node->prev->next = node->next;
        if (node->next != nullptr) node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr; 
    }

    bool containsNodeWithValue(int value)
    {
        Node* node = head;
        while (node != nullptr && node->value != value)
        {
            node = node->next;
        }
        return node != nullptr;
    }
};
