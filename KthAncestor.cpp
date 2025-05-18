#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
bool kthAncestor(Node* root, int &k, Node* p)
{
    //base case
    if(root == NULL)
    {
        return false;
    }

    if(root->data == p->data)
    {
        return true;
    }

    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);

    //waps aare honge...
    //check left ya right me answer mila ya nahi...
    if(leftAns || rightAns)
    {
        k--;
    }
    if(k == 0)
    {
        cout<<"Answer: "<<root->data<<endl;//phir wah kabhi 0 nhi hoga...
        k = -1;
    }

    return leftAns || rightAns;
}
int main()
{
    return 0;
}
