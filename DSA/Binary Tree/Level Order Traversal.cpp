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

void levelOrderTraversal(struct node *temp){
    queue<node *> q;
    q.push(temp);
    q.push(NULL);
    while(!q.empty()){
    node *temp = q.front();
    if(temp== NULL){
        cout<<endl;
        q.pop();
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
        q.pop();
        cout<<temp->data<<" ";
        
        if(temp->left !=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        
    }
        
    }
    return;
    
}
int main(){
    struct node *root = buildTree();
    cout<<"PreOrder Traversal is : ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"Level Order Traversal  is : "<<endl;
    levelOrderTraversal(root);
}

