#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;
int main(){
	
	fstream f,f1;
	f.open("simple.txt",ios::out);
	//1 technics
	if(!f.is_open()){
		cout<<"errror while opening the file";
	}
	f<<"om salunke";
	if(f.bad()){
		cout<<"Error occur while performing operation";
	}
	try{
		f1.open("sample.txt",ios::in);
		
	}catch(const runtime_error& e){
		cout<<"error occur";
	}
	
	return 0;
}
