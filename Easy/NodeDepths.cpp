#include <vector>
using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

int traversal(BinaryTree *node, int node_depth);
int nodeDepths(BinaryTree *root)
{
    return traversal(root, 0);
}

int traversal(BinaryTree *node, int node_depth)
{
    if (!node)
        return 0;
    int left_sum = traversal(node->left, node_depth + 1);
    int right_sum = traversal(node->right, node_depth + 1);
    return left_sum + right_sum + node_depth;
}