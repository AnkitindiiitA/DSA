/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;
  
  Node(int d){
      this->data=d;
      this->left=NULL;
      this->right=NULL;
  }
  
};

Node* insertIntoBST(Node* &root, int d){
    //base case
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    
    if(d < root ->  data){
        //left part me insert karna hai
        root->left=insertIntoBST(root->left, d);
    }
    else{
        //right part me insert karna hai
        root->right=insertIntoBST(root->right, d);
    }
    return root;
}

void takeInput(Node* &root){
    
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root, data);
        cin>>data;
    }
}

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int main()
{
    Node* root=NULL;
    
    cout<<"enter data to create BST "<<"\n";
    takeInput(root);
    
    cout<<"printing inOrderTraversal of tree "<<"\n";
    inOrderTraversal(root);

    return 0;
}
