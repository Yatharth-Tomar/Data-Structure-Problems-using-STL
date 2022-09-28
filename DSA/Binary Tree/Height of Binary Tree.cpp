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

struct node * levelOrderBuild(){
    
    int data;
    cin>>data;
    queue<node *> q;
    
    
    
    node *root = createNode(data);
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            temp->left = createNode(c1);
            q.push(temp->left);
        }
        if(c2!=-1){
            temp->right = createNode(c2);
            q.push(temp->right);
        }
        
    }
    return root;
        
        
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
int heightBinaryTree(node *temp){
    if(temp == NULL){
        return 0;
    }
    int  hl = heightBinaryTree(temp->left);
    int  hr = heightBinaryTree(temp->right);
    int ans = max(hl,hr);
    return ans+1;
}
int main(){
    struct node *root = buildTree();
    // struct node *root = levelOrderBuild();
    cout<<endl;
    cout<<"Level Order Traversal  is : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<heightBinaryTree(root);
}

