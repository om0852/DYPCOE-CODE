#include <iostream>
#include <string>
using namespace std;
struct Stack{
    int data[50];
    int top=-1;
};

bool check(struct Stack s){
    string str;
    cout<<"Enter String:";
    cin>>str;
    
  for(int i=0;i<str.length();i++){
      if(str[i]=='(' || str[i]=='{' || str[i]=='['){
          if(s.top==50){
              cout<<"Stack is overflow"<<endl;
          }
          else{
              s.top++;
              s.data[s.top]=str[i];
          }

      }
      else if((str[i]==')' && s.data[s.top]=='(') || (str[i]=='}' && s.data[s.top]=='{') || (str[i]==']' && s.data[s.top]=='[')){
          if(s.top==-1){
          }
          else{
              s.top--;
          }
      }
      
  
  }  
  return s.top==-1;
}
int main(){
    struct Stack s;

if(    check(s)){
    cout<<"Well parenthesized ";
}
else{
    cout<<"Not well parenthesized ";
}
    return 0;
}