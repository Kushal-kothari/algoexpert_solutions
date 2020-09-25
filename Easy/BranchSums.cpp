#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
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

void traversal(BinaryTree *node, int pre_sum, vector<int> &res);

vector<int> branchSums(BinaryTree *root)
{
    vector<int> res;
    traversal(root, 0, res);
    return res;
}

void traversal(BinaryTree *node, int pre_sum, vector<int> &res)
{
    if (!node)
        return;
    pre_sum += node->value;
    if (node->left)
        traversal(node->left, pre_sum, res);
    if (node->right)
        traversal(node->right, pre_sum, res);
    if (!node->left && !node->right)
        res.push_back(pre_sum);
}
