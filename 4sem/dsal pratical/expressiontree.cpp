#include<iostream>
#include<stack>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};
Node *s[10];
int top=-1;
void expression(string str){
    for (int i = str.length()-1;i>=0;i--){
        if(str[i]=='+'){
            Node *n1=s[top--];
            Node *n2=s[top--];
            Node *newNode=new Node();
            newNode->data=str[i];
            newNode->left=n1;
            newNode->right=n2;
            s[++top]=newNode;
            
            
        }
        else{
            Node *newNode =new Node();
            newNode->data=str[i];
            newNode->left=NULL;
            newNode->right=NULL;
            s[++top]=newNode;
        }
    }
}

void display(Node* root) {
    if (root == nullptr)
    {
        cout<<"Empty";
        return;
    }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
 int main(){
     expression("+ab");
     display(s[0]);
     
     
     return 0;
 }