#include <iostream>

using namespace std;

struct Node {
    int seat;
    bool isBooked;
    Node* prev;
    Node* next;
};

Node* head[10];

void create() {
    for (int i = 0; i < 10; i++) {
        head[i] = NULL;
        Node* current = NULL;
        for (int j = 0; j < 7; j++) {
            Node* newNode = new Node();
            newNode->seat = j + 1;
            newNode->isBooked = false;
            newNode->next = NULL;
            newNode->prev = NULL;

            if (head[i] == NULL) {
                head[i] = newNode;
                current = newNode;
            } else {
                newNode->prev = current;
                current->next = newNode;
                current = newNode;
            }
        }
    }
}

void display_rem() {
    for (int i = 0; i < 10; i++) {
        Node* current = head[i];
        cout << "Row " << i + 1 << ": ";
        while (current != NULL) {
//        	cout<<current->isBooked<<endl;
            if (!current->isBooked) {
                cout << "Seat " << current->seat << " (Available) ";
            } else {
                cout << "Seat " << current->seat << " (Booked) ";
            }
            current = current->next;
        }
        cout << endl;
    }
}

void book(){
	int seat,row;
	cout<<"Enter Row No:";
	cin>>seat;
	cout<<"Enter Seat No:";
	cin>>row;
	
	Node* current = head[row-1];
	for(int i=0;i<seat-1;i++){
	 current=current->next;
	}
//	cout<<current->isBooked;
	if(current->isBooked){
		cout<<"Seat is already booked"<<endl;
	}
	else{
		current->isBooked=true;
		cout<<"Seat booked successfully"<<endl;
	}
}

void cancel(){
		int seat,row;
	cout<<"Enter Row No:";
	cin>>seat;
	cout<<"Enter Seat No:";
	cin>>row;
	
	Node* current = head[row];
	for(int i=0;i<seat;i++){
	 current=current->next;
	}
	if(!current->isBooked){
		cout<<"Seat is not booked"<<endl;
	}
	else{
		current->isBooked=false;
		cout<<"Seat cancel successfully"<<endl;
	}
}

int main() {
	int ch;
	 create();
   
	do{
		cout<<"\n\n\nMenu\n 1.The list of available seats is to be displayed\n 2.The seats are to be booked \n 3.The booking can be cancelled \n 4.Exit";
		cin>>ch;
		
		if(ch==1){
			    display_rem();

		}
		else if(ch==2){
			    	book();

		}
		else if(ch==3){
			cancel();
		}
		else if(ch==4){
			break;
		}
		else{
			cout<<"Invalid input";
		}
	}while(ch!=4);
   
    return 0;
}
