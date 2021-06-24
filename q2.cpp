#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d) : data(d), left(NULL), right(NULL) {}
};

node *BuildTreeLevel()
{
    node *root = NULL;
    int data;
    cout << "Enter root data ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *x = q.front();
        q.pop();

        cout << "Enter data of " << x->data << endl;
        int left_data, right_data;
        cin >> left_data >> right_data;
        if (left_data != -1)
        {
            x->left = new node(left_data);
            q.push(x->left);
        }
        if (right_data != -1)
        {
            x->right = new node(right_data);
            q.push(x->right);
        }
    }

    return root;
}
bool printPath(node *root, int sum)
{
    if (sum == 0)
    {
        return true;
    }

    if (root == nullptr)
    {
        return false;
    }
    bool left = printPath(root->left, sum - root->data);
    bool right = printPath(root->right, sum - root->data);
    if (left || right)
    {
        cout << root->data << " ";
    }

    return left || right;
}

int getRootToLeafSum(node *root)
{

    if (root == nullptr)
    {
        return 0;
    }
    int left = getRootToLeafSum(root->left);
    int right = getRootToLeafSum(root->right);

    return (left > right ? left : right) + root->data;
}

void findMaxSumPath(node *root)
{
    int sum = getRootToLeafSum(root);
    cout << "The Maximum sum is " << sum << endl;
    cout << "The Maximum sum path is ";

    printPath(root, sum);
}

int main()
{
    node *root = BuildTreeLevel();
    int sum = getRootToLeafSum(root);
    cout << "The Maximum sum is " << sum << endl;
    cout << "The Maximum sum path is ";

    printPath(root, sum);
    return 0;
}