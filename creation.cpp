#include<iostream>
#include<queue>
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
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root)
{
    cout<<"Enter The Data: "<< endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for insertion in left of : "<< data << endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for insertion in right of : "<< data << endl;
    root->right = buildTree(root->right);

    return root;
}

//Inorder
void inorder(Node* root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preOrder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    cout<<endl; 
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);//line change ke liye ise use kar rhe hain...
    //NULL is a separator....

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            //purana level complete traverse ho chuka hain...
            if(!q.empty())//queue still has some nodes..
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
               q.push(temp->left);
            }
            if(temp->right)
            {
               q.push(temp->right);
            }
        }
    }
}

void buildTreeFromLevelOrderTraversal(Node* &root)
{
    queue<Node*> q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<< temp->data << endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<< temp->data << endl;
        int rightData;
        cin>>rightData;
        
        if(rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node* root = NULL;

    //yeh sirf line 1 hi hain...fromLevelOrderTraversalWalekeliye...
    //baaki comment se hata dena...
    buildTreeFromLevelOrderTraversal(root);

    // //creating tree...
    // root = buildTree(root);

    // //levelOrderTraversal
    // cout<<"Printing Level Order Traversal output: "<<endl;
    // levelOrderTraversal(root);
    return 0;
}