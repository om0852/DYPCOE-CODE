#include<iostream>
using namespace std;

struct Node{

char data;
Node *left;
Node *right;

};

struct Stack{

Node *data[50];
int top; 

};

Stack s;
bool isFull(){
if(s.top==49){
return true;
}
else{
return false;
}

}

bool isEmpty(){
if(s.top==-1){
return true;
}
return false;
}


void push(Node *n){
s.data[++s.top]=n;
}

auto pop(){
return s.data[s.top--];
}

void expression(string str){
Node *t1=NULL;
Node *t2=NULL;
 for(int i=str.length()-1;i>=0;i--){
  if(str[i]=='+' || str[i]=='-'|| str[i]=='*' || str[i]=='/' || str[i]=='^' ){
       t1=pop();
       t2=pop();
       Node *temp =  new Node();
       temp->data=str[i];
       temp->left=t1;
       temp->right=t2;
       push(temp);
       
  }
  else{
  Node *temp=new Node();
  temp->data=str[i];
  temp->left=NULL;
  temp->right=NULL;
  push(temp);
  }
 }
}

void display(Node *n){

if(n==NULL){
cout<<"Empty";
return;
}
else{
cout<<n->data;
if(n->left!=NULL){
display(n->left);
}
if(n->right!=NULL){

display(n->right);
}
}




}
void display_post(Node *n){

if(n==NULL){
cout<<"Empty";
return;
}
else{
if(n->left!=NULL){
display(n->left);
}
if(n->right!=NULL){

display(n->right);
}
cout<<n->data;

}




}
int main(){
s.top=-1;
string str="+--a*bc/def";

expression(str);

cout<<"preorder traversal";
display(s.data[0]);
cout<<"\npostorder traversal";
display_post(s.data[s.top]);
return 0;
}
