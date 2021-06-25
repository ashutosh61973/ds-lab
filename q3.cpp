#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

bool prime[100000]; //primes under 10^5
//////////////////////////////////seive for prime/////////////////////////////
/*
void primes() 
{ 
  int n=100000;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
        // Print all prime numbers 
           // for (int p=2; p<=n; p++) 
        // if (prime[p]) 
         // cout << p << " "; 
} 
*/
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////NCR////////////////////////////////////////
/*const int N=5000;
 
#define NCR
#define PRIME	M
inti pw(inti a,inti p=M-2,inti MOD=M){
    inti result = 1;
    while (p > 0) {
        if (p & 1)
            result = a * result % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return result;
}
inti fact[N],invfact[N];
void init(){
    inti p=PRIME;
    fact[0]=1;
    inti i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}
inti ncr(inti n,inti r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}*/
///////////////////////////////////////////////////////////////////////////////

////\\//////\\/////////\\///////////\\\////////\\/////////////\\\/////
/*
ll power(ll a, ll b) //time complexity is  o(log(b));
{
  if (a == 0)
    return 0;
  ll ans = 1;
  a = a % mod;
  while (b > 0)
  {
    if ((b & 1) == 1)
      ans = (ans * a) % mod;
    b = b >> 1;
    a = (a * a) % mod;
  }
  return ans;
}*/
//\\////\\//////\\//////\//////\\///////\\//////////\\/////\\///
/*bool isPrime(int n) {
 
  if (n == 1) {
    return false;
  }
 
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
 
  return true;
}*/
//////////////\\\\\\\\////////\\\\\\\\\\//////////\\\\////

///////////////////////////////////////////////////////////////////////

/*
//sort string by there length ==>

sort(v.begin(), v.end(), [&] (const string &s, const string &t) {
        return s.size() < t.size();
    });
*/

///////////////////////////////////////////////////////////////////////

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *InsertNode(Node *&head, int data)
{

    if (head == NULL)
    {
        head = CreateNode(data);
        return head;
    }

    queue<Node *> q;
    q.push(head);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = CreateNode(data);
            return head;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = CreateNode(data);
            return head;
        }
    }
}

/* travese and print binary tree level order recurrsive */
int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void printCurrentLevel(Node *head, int level)
{
    if (head == NULL)
        return;
    if (level == 1)
        cout << head->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(head->left, level - 1);
        printCurrentLevel(head->right, level - 1);
    }
}

void LevelOrder(Node *head)
{
    int h = height(head);
    for (int i = 1; i <= h; i++)
        printCurrentLevel(head, i);
}

// traverse and print binary tree level order(non recursive)
void printLevelOrder(Node *head)
{

    if (head == NULL)
        return;

    queue<Node *> q;
    q.push(head);

    while (q.empty() == false)
    {

        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);
    }
}

// spiral order traversal of binary tree recursively
void printcurrentlevel(Node *head, int level, int ch)
{
    if (head == NULL)
        return;
    if (level == 1)
        cout << head->data << " ";

    else if (level > 1)
    {
        if (ch)
        {
            printcurrentlevel(head->left, level - 1, ch);
            printcurrentlevel(head->right, level - 1, ch);
        }
        else
        {
            printcurrentlevel(head->right, level - 1, ch);
            printcurrentlevel(head->left, level - 1, ch);
        }
    }
}

void printSpiral(Node *head)
{
    int h = height(head);
    int i;

    bool ch = false;
    for (i = 1; i <= h; i++)
    {
        printcurrentlevel(head, i, ch);
        ch = !ch;
    }
}

// spiral order non recurrsive
void printSpiral1(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {

        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}
int main()
{
    Node *head = NULL;
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    int n = sizeof(arr) / sizeof(char);
    for (int i = 0; i < n; i++)
    {
        InsertNode(head, arr[i]);
    }

    cout << "Level Order : ";
    LevelOrder(head);
    cout << endl;

    cout << "Non Recurrsive level order : ";
    printLevelOrder(head);
    cout << endl;

    cout << "spiral Order : ";
    printSpiral(head);
    cout << endl;

    cout << "Non Recurrsive spiral order : ";
    printSpiral1(head);
}
