#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node* createNode(int data){
    struct node *temp;
    temp = new node;
    temp->left = NULL;
    temp->data = data;
    temp->right = NULL;
    return temp;
    
}
struct node *buildTree(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
   
    struct node *temp = createNode(data);
    temp->left = buildTree();
    temp->right = buildTree();
    
    
    return temp;
    
    
}
void preOrderTraversal(struct node *temp){
    if(temp == NULL){
        return;
    }
    cout<<temp->data<<" ";
    preOrderTraversal(temp->left);
    preOrderTraversal(temp->right);
   
    
}
int main(){
    struct node *root = buildTree();
    preOrderTraversal(root);
}

