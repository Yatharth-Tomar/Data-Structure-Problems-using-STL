#include<bits/stdc++.h>
using namespace std;

int ans = 0;
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
    cout<<"Enter left child : ";
    temp->left = buildTree();
    cout<<"Enter Right child : ";
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

int diameterBinaryTree(node *temp){
    if(temp == NULL){
        return 0;
    }
    
    int  hl = diameterBinaryTree(temp->left);
    int  hr = diameterBinaryTree(temp->right);
    ans = max(ans,hl+hr);
    
    return 1+max(hl,hr);
}
int main(){
    struct node *root = buildTree();
    // struct node *root = levelOrderBuild();
    cout<<endl;
    cout<<"Level Order Traversal  is : "<<endl;
    levelOrderTraversal(root);
    diameterBinaryTree(root);
    cout<<"Diameter of BInary Tree is : "<<ans;
}

