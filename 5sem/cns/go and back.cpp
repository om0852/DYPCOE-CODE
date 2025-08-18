//go back

#include<iostream>

using namespace std;


int main(){
    
    int sender[10]={1,2,3,4,5,6,7,8,9,10};
    
    int receiver[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    int corrupt=5;
    int i=0;
    int n=10;
    while(i<n){
        if(i==7){
            if(corrupt!=-1){
                i=corrupt-1;
                cout<<"packet "<<corrupt<<" is lost .... "<<endl;
                cout<<"resending from packet 5 again ..."<<endl;
                corrupt=-1;
            }
        }
        cout<<"sending packet"<<(i+1)<<"....."<<endl;
        
        i++;
    }
    return 0;
}