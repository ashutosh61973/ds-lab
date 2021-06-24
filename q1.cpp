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
void PrintLevel(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *x = q.front();
        q.pop();
        if (x == NULL)
        {
            cout << endl;
            if (!q.empty())
            {

                q.push(NULL);
            }
        }
        else
        {
            cout << x->data << " ";
            if (x->left)
            {
                q.push(x->left);
            }
            if (x->right)
            {
                q.push(x->right);
            }
        }
    }
}
void preOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << ",";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);

    cout << root->data << ",";

    inOrder(root->right);
}

void postOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);

    postOrder(root->right);

    cout << root->data << " ";
}

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
int main()
{
    node *root = BuildTreeLevel();
    PrintLevel(root);
    postOrder(root);
    inOrder(root);
    preOrder(root);
    return 0;
}