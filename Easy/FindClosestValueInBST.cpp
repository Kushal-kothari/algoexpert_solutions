#include <vector>
using namespace std;

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

void inorderTraversal(BST *node, vector<int> &res)
{
    if (!node)
        return;
    inorderTraversal(node->left, res);
    res.push_back(node->value);
    inorderTraversal(node->right, res);
}

int findClosestValueInBst(BST *tree, int target)
{
    vector<int> num;
    inorderTraversal(tree, num);
    if (!num.empty())
    {
        int res = num[0];
        for (auto i : num)
        {
            if (abs(target - i) < abs(target - res))
            {
                res = i;
            }
        }
        return res;
    }
    return -1;
}
