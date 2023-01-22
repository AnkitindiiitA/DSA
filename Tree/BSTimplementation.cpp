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

Node* minVal(Node* root){
    Node* temp=root;
    
    while(temp->left != NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp=root;
    
    while(temp->right != NULL){
        temp=temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int key){
    //base case
    if(root==NULL){
        return root;
    }
    
    if(root->data == key){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
        //left child
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
        //right child
            Node* temp=root->right;
            delete root;
            return temp;
        }
        
        //2 child
        else{
            int mini = minVal(root->right) -> data;
            root -> data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
        
    }
    else{
        if(key>root->data){
            root->right = deleteFromBST(root->right, key);
            return root;
        }
        else{
            root->left = deleteFromBST(root->left, key);
            return root;
        }
    }
}

int main()
{
    Node* root=NULL;
    
    cout<<"enter data to create BST "<<"\n";
    takeInput(root);
    
    cout<<"printing inOrderTraversal of tree "<<"\n";
    inOrderTraversal(root);
    cout<<"\n";
    
    cout<<"min value of the tree is "<<minVal(root) -> data <<endl;
    cout<<"max value of the tree is "<<maxVal(root) -> data <<endl;
    
    //input for deleteing an node in the tree
    //10 20 30 50 70 90 110 -1
    root = deleteFromBST(root, 30);
    
    cout<<"printing inOrderTraversal of tree "<<"\n";
    inOrderTraversal(root);
    cout<<"\n";
    
    

    return 0;
}
