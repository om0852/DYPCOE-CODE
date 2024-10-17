#include <iostream>
#include <string>
using namespace std;
struct Stack{
    int data[50];
    int top=-1;
};

struct Stack s;
void check(){
    string str;
    cout<<"Enter String:";
    cin>>str;
    
  for(int i=0;i<str.length();i++){
      if(str[i]=='(' && str[i]=='{' && str[i]=='['){
          if(s.top==50){
              cout<<"Stack is overflow"<<endl;
          }
          else{
              s.top++;
              s.data[s.top]=str[i];
          }
          
      }
      cout<<s.top;
      else if((str[i]==')' && s.data[s.top]=='(') || (str[i]=='}' && s.data[s.top]=='{') || (str[i]==']' && s.data[s.top]=='[')){
          if(s.top==-1){
              cout<<"stack is overflow"<<endl;
          }
          else{
              s.top--;
          }
      }
      
  
  }  
  cout<<s.top;
}
int main(){
    
    check();
    return 0;
}