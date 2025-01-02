#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
	cout<<argc;
	for (int i=0;i<argc;i++){
		cout<<argv[i];
	}
	return 0;
}
