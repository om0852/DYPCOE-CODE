#include<iostream>
using namespace std;
struct Node{
int data;
Node *left;
Node *right;
};

class BT{
	public:
Node *root;

BT(){
root=NULL;
}
void create(int data){
	Node *n=new Node();
	if(root==NULL){	
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	root=n;
}
else{
	cout<<"Root already exist"<<endl;
}
}
void insert(Node *root,int data){
if(root==NULL){
		create(data);
}
else{
    Node *n = new Node();
    n->data=data;
    n->left;
    n->right;
if(root->data>data){
	if(root->left==NULL){
		root->left=n;
	}else{
		insert(root->left,data);
	}
}
else{
	if(root->right==NULL){
		root->right=n;
	}else{
		insert(root->right,data);
	}
}
}
}
void display(Node *root){
    if(root!=NULL){
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
    }
}
// void display2(Node *root){
    
//     if(root!=NULL){
//         Node *leftSide=root->left;
//         Node *rightSide=root->right();
//         while(root->left!=NULL){
//               cout<<leftSide->data;
//               leftSide=leftSide->left;
//               cout<<" "
//         }
//         while(root->right!=NULL){
            
//         }
//     }
    
// }
};





int main(){
BT b;
b.create(40);
b.insert(b.root,20);
b.insert(b.root,90);
b.insert(b.root,30);
b.insert(b.root,70);
b.display(b.root);
return 0;
}
