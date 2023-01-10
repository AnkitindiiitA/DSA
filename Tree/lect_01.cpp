
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node*right;
    
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
    
};

void inorderTraversal(node* root){
    if(root==NULL)return;
    
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root){
    if(root==NULL)return;
    
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root){
    if(root==NULL)return;
    
    postorderTraversal(root->left);
    preorderTraversal(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal1(node* root){
    queue<pair<node*,int>>q;
    if(root!=NULL){
        q.push({root,0});
    }
    int x=0;
    while(!q.empty()){
        node* temp=q.front().first;
        int val=temp->data;
        int par=q.front().second;
        
        q.pop();
        if(par>x){
            x++;
            cout<<"\n";
        }
        cout<<val<<" ";
        
        if(temp->left!=NULL){
            q.push({temp->left,par+1});
        }
        if(temp->right!=NULL){
            q.push({temp->right,par+1});
        }
        
    }
    cout<<"\n";
    
}

void levelOrderTraversal2(node* root){
    queue<node*>q;
    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    
}

node* buildTree(node* root){
    cout<<"\n";
    cout<<"Enter data ";
    int d;
    cin>>d;
    
    
    
    if(d==-1)return NULL;
    root=new node(d);
    
    cout<<"Enter data left to "<<d<<" ";
    root->left=buildTree(root->left);
    cout<<"Enter data right to "<<d<<" ";
    root->right=buildTree(root->right);
    return root;
}

void buildFromLevelOrder(node* &root){
    cout<<"Enter root data ";
    int d;
    cin>>d;
    root=new node(d);
    queue<node*>q;
    q.push(root);
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        cout<<"Enter data for left child of "<<temp->data<<":";
        int leftNode;
        cin>>leftNode;
        if(leftNode!=-1){
            temp->left=new node(leftNode);
            q.push(temp->left);
        }
        
        cout<<"Enter data for right child of "<<temp->data<<":";
        int rightNode;
        cin>>rightNode;
        if(rightNode!=-1){
            temp->right=new node(rightNode);
            q.push(temp->right);
        }
    }
    
}

int main()
{
    node* root=NULL;
    // root=buildTree(root);
    buildFromLevelOrder(root);
    
    cout<<"\n"<<"levelOrderTraversal"<<'\n';
    levelOrderTraversal1(root);
    cout<<"\n";
    
    cout<<"levelOrderTraversal"<<'\n';
    levelOrderTraversal2(root);
    cout<<"\n";
    
    cout<<"inorderTraversal"<<'\n';
    inorderTraversal(root);
    cout<<"\n\n";
    
    cout<<"preorderTraversal"<<'\n';
    preorderTraversal(root);
    cout<<"\n\n";
    
    cout<<"postorderTraversal"<<'\n';
    postorderTraversal(root);
    cout<<"\n\n";
    
    

    return 0;
}
