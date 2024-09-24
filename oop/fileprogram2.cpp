//.WAP using C++ file input and output class with open() ,get(),put(),close() methods for opening ,reading from and writing to a file.Use append mode while opening the file for writing.


#include <iostream>
#include <fstream>
using namespace std;
int main(){
	
	ofstream f1;
	f1.open("sammple.txt");
	if(!f1.is_open()){
		cout<<"file not found";
		return 1;
		
	}
	string data  = "Zala ka abhays";
	while(sizeof(data)){
		f1.put(data[0])
	}
	f1.close();
	ifstream f("sammple.txt");
	char p;
	while(f.get(p)){
		cout<<p;
	}
	
	f.close();	
	return 0;
}
