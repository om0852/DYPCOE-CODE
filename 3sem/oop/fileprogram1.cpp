#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string data;
	ifstream f("simple.txt");
	if(!f.is_open()){
		cout<<"error while opening file";
		return 1;
	}
	while(!f.eof()){
		getline(f,data);
		cout<<data<<endl;
	}
	return 0;
}
