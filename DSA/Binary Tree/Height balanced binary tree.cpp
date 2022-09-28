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
int replaceWithSum(struct node *temp){
    if(temp == NULL){
        return 0;
    }
    if(temp->left ==NULL and temp->right == NULL){
        return temp->data;
    }
   
    int ls = replaceWithSum(temp->left);
    int rs = replaceWithSum(temp->right);
    int temp1 = temp->data;
    temp->data = ls+rs;
    return ls+rs+temp1;
}
pair<int,bool> isHeightBalanced(node * temp){
    pair <int,bool> p,left,right;
    if(temp == NULL){
        p.first = 0;
        p.second = true;
        return p;
    }
    left = isHeightBalanced(temp->left);
    right = isHeightBalanced(temp->right);
    
    int height = max(left.first,right.first) +1;
    if(abs(left.first - right.first)<=1  and left.second and right.second){
        return make_pair(height,true);
    }
    return make_pair(height,false);
    
    
    
}
int main(){
    struct node *root = buildTree();
    // struct node *root = levelOrderBuild();
    // cout<<"PreOrder Traversal is : ";
    // preOrderTraversal(root);
    cout<<endl;
    cout<<"Level Order Traversal  is : "<<endl;
    levelOrderTraversal(root);
     cout<<endl;
    // replaceWithSum(root);
    // cout<<"Level Order Traversal  is : "<<endl;
    // levelOrderTraversal(root);
    pair<int,bool> p = isHeightBalanced(root);
    if(p.second == true){
        cout<<"Height is balanced ";
    }
    else{
        cout<<"Height is not balanced ...";
    }
    
    
}

