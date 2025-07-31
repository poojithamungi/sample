#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val):data(val),left(nullptr),right(nullptr){};
};
node* binarytree(){
    node* root=new node(5);
    root->left=new node(2);
    root->right=new node(6);
    root->left->left=new node(1);
    root->right->right=new node(7);
    return root;
}
void inorder(node* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void preorder(node* root){
    if(!root)return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
bool search(node* root,int val)
{
    if(!root)return false;
    if(root->data==val)return true;
    return search(root->left,val)||search(root->right,val);
}
int main(){
    node* root= binarytree();
    cout<<"inorder traversal:";
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal:";
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal:";
    postorder(root);
    cout<<endl;
    int target=10;
    if (search(root,target)){
        cout<<"search element is found";
    }
    else{
    cout<<"search element is not found!";}
    return 0;
    
}