#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include <string.h>
using namespace std;

struct Node{
		string Name,CNIC;
		int Seat_no;
		Node *next;
};

void sort(Node * x, int size)
{
	//x : head pointer of the list to sort
	//size : count of total Nodes in the list to sort
	Node* tempi = x;
	for(int i = 0; i < size-1; i++)
	{
		Node* minNode = tempi; //address of the minimum value Node
		Node* tempj = tempi->next;
		for(int j = i+1; j < size; j++)
		{
			if(tempj->Seat_no < minNode->Seat_no)
			{
				minNode = tempj;
			}
			tempj= tempj->next;
		}
		//swapping data of tempi with data of minNode
		int tempSeat = tempi->Seat_no;  
		string tempName = tempi->Name;
		string tempCNIC = tempi->CNIC;
		tempi->Seat_no = minNode->Seat_no;
		tempi->Name = minNode->Name;
		tempi->CNIC = minNode->CNIC;
		minNode->Seat_no = tempSeat;
		minNode->Name = tempName;
		minNode->CNIC; tempCNIC;
		tempi= tempi->next;
	}
}

Node *head=NULL,*tail=NULL;
Node *head2=NULL,*tail2=NULL;
Node *head3=NULL,*tail3=NULL;
int size1=0,size2=0,size3=0;
class Red_Line{

	public:
		int countNode(Node *ptr){
			int count=0;
			while(ptr!=NULL){
				ptr=ptr->next;
				count++;
			}
			return (count);
		}
		
		void swapNodes(Node** head_r){
			int x,y;
			cout<<"Enter Your Seat Number: ";
			cin>>x;
			cout<<"Enter the Seat Number you want to change with: ";
			cin>>y;
		    if (x == y){
		        return;
		    }
		    Node *prevX = NULL, *currX = *head_r;
		    while (currX && currX->Seat_no != x) {
		        prevX = currX;
		        currX = currX->next;
		    }
		    Node *prevY = NULL, *currY = *head_r;
		    while (currY && currY->Seat_no != y) {
		        prevY = currY;
		        currY = currY->next;
		    }
		    if (currX == NULL || currY == NULL){
		        return;
		    }
		    if (prevX != NULL){
		        prevX->next = currY;
		    }
		    else{
		        *head_r = currY;
		    }
		    if (prevY != NULL){
		        prevY->next = currX;
		    }
		    else{
		        *head_r = currX;
		    }
		    Node* temp = currY->next;
		    currY->next = currX->next;
		    currX->next = temp;
		    cout<<"\nYour Seat Has Been Swaped Successfully :) \n";
		}
		
		void Adisplay1(){
			if(head==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=head;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != head);
			}
		}
		void Adisplay2(){
			if(head2==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=head2;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != head2);
			}
		}
		void Adisplay3() {
			if(head3==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=head3;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != head3);
			}
		}
		
		void insertatmid1(){
		    int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			aa:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;
			if(seatno<=10){
			    if(head == NULL){
			        head = newNode;  
			        tail = newNode;  
			        newNode->next = head;
			        cout<<"\nElement Inserted: \n";
			    }
			    else{  
			        Node *temp=NULL, *current = NULL;
			        
			        temp = head;
			        for(i = 0; i < size1; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   		cout<<"\nElement Inserted: \n";
			   	}
		    	size1++;
		    	sort(head, size1);
			}
			else{
				cout<<"We have Only 10 Seats. Enter the Suitable Seat no in Range of 1-10 !\n";
				goto aa;
			}
		}
		
		void display1(){
			Node *temp=head->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != head);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		
		void display2(){
			Node *temp=head2->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != head2);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		void display3(){
			Node *temp=head3->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != head3);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		
		void search_delete1(){
			int data;
			cout<<"\nEnter Seat Number to Delete Element : ";
			cin>>data;
			int flag=0;
			Node *temp=head;
			Node *prev;
			if(temp->Seat_no==data){
				head=temp->next;
				free(temp);
				flag=1;
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
//				break;
			}
			else{
				while(temp->next != head){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						prev->next=temp->next;
						free(temp);
						flag=1;
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
		
		void insertatmid2(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			bb:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;
			if(seatno<=10){
			    if(head2 == NULL){
			        head2 = newNode;  
			        tail2 = newNode;  
			        newNode->next = head2;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (size2 % 2 == 0) ? (size2/2) : ((size2+1)/2);
			        temp = head2;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    size2++;
			    sort(head2, size2);
			}
			else{
				cout<<"We have Only 10 Seats. Enter the Suitable Seat no in Range of 1-10 !\n";
				goto bb;
			}
		}
		void search_delete2(){
			int data;
			cout<<"\nEnter Seat Number To Delete : ";
			cin>>data;
			int flag=0;
			Node *temp=head2;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
				head2=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != head2){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
		void insertatmid3(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			cc:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;
			if(seatno<=10){
			    if(head3 == NULL){
			        head3 = newNode;  
			        tail3 = newNode;  
			        newNode->next = head3;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (size3 % 2 == 0) ? (size3/2) : ((size3+1)/2);
			        temp = head3;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    size3++;
			    sort(head3, size3);
			}
			else{
				cout<<"We have Only 10 Seats. Enter the Suitable Seat no in Range of 1-10 !\n";
				goto cc;
			}
		}
		void search_delete3(){
			int data;
			cout<<"\nENTER Seat Number TO DELETE : ";
			cin>>data;
			int flag=0;
			Node *temp=head3;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
				head3=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != head3){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
};

Node *ghead=NULL,*gtail=NULL;
Node *ghead2=NULL,*gtail2=NULL;
Node *ghead3=NULL,*gtail3=NULL;
int gsize=0,gsize2=0,gsize3=0;
class Green_Line{

	public:
		
		int countNode(Node *ptr){
			int count=0;
			while(ptr!=NULL){
				ptr=ptr->next;
				count++;
			}
			return (count);
		}
		
		void insertatmid1(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			ab:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;  
			if(seatno<=15){
			    if(ghead == NULL){
			        ghead = newNode;  
			        gtail = newNode;  
			        newNode->next = ghead;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (gsize % 2 == 0) ? (gsize/2) : ((gsize+1)/2);
			        temp = ghead;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    gsize++;
			    sort(ghead, gsize);
			}
			else{
				cout<<"We have Only 15 Seats. Enter the Suitable Seat no in Range of 1-10 !\n";
				goto ab;
			}
		}
		
		void Adisplay1(){
			if(ghead==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=ghead;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != ghead);
			}
		}
		void Adisplay2() {
			if(ghead2==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=ghead2;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != ghead2);
			}
		}
		void Adisplay3() {
			if(ghead3==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=ghead3;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != ghead3);
			}
		}
		
		void swapNodes(Node** head_r){
			int x,y;
			cout<<"Enter Your Seat Number: ";
			cin>>x;
			cout<<"Enter the Seat Number you want to change with: ";
			cin>>y;
		    if (x == y){
		        return;
		    }
		    Node *prevX = NULL, *currX = *head_r;
		    while (currX && currX->Seat_no != x) {
		        prevX = currX;
		        currX = currX->next;
		    }
		    Node *prevY = NULL, *currY = *head_r;
		    while (currY && currY->Seat_no != y) {
		        prevY = currY;
		        currY = currY->next;
		    }
		    if (currX == NULL || currY == NULL){
		        return;
		    }
		    if (prevX != NULL){
		        prevX->next = currY;
		    }
		    else{
		        *head_r = currY;
		    }
		    if (prevY != NULL){
		        prevY->next = currX;
		    }
		    else{
		        *head_r = currX;
		    }
		    Node* temp = currY->next;
		    currY->next = currX->next;
		    currX->next = temp;
		    cout<<"\nYour Seat Has Been Swaped Successfully :) \n";
		}
		
		void display1(){
			Node *temp=ghead->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != ghead);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		void display2(){
			Node *temp=ghead2->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != ghead2);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		void display3(){
			Node *temp=ghead3->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != ghead3);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		
		void search_delete(){
			int data;
			cout<<"\nEnter Seat Number to Delete Element : ";
			cin>>data;
			int flag=0;
			Node *temp=ghead;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
				ghead=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != ghead){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
		void insertatmid2(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			ac:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;
			if(seatno<=15){
			    if(ghead2 == NULL){
			        ghead2 = newNode;  
			        gtail2 = newNode;  
			        newNode->next = ghead2;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (gsize2 % 2 == 0) ? (gsize2/2) : ((gsize2+1)/2);
			        temp = ghead2;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    gsize2++;
			    sort(ghead2, gsize2);
			}
			else{
				cout<<"We have Only 15 Seats. Enter the Suitable Seat no in Range of 1-10 !\n";
				goto ac;
			}
		}
		void search_delete2(){
			int data;
			cout<<"\nEnter Seat Number To Delete : ";
			cin>>data;
			int flag=0;
			Node *temp=ghead2;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
				ghead2=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != ghead2){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
		void insertatmid3(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			ad:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;
			if(seatno<=15){
			    if(ghead3 == NULL){
			        ghead3 = newNode;  
			        gtail3 = newNode;  
			        newNode->next = ghead3;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (gsize3 % 2 == 0) ? (gsize3/2) : ((gsize3+1)/2);
			        temp = ghead3;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    gsize3++;
			    sort(ghead3, gsize3);
		    }
			else{
				cout<<"We have Only 15 Seats. Enter the Suitable Seat no in Range of 1-15 !\n";
				goto ad;
			}
		}
		void search_delete3(){
			int data;
			cout<<"\nENTER Seat Number TO DELETE : ";
			cin>>data;
			int flag=0;
			Node *temp=ghead3;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
				ghead3=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != ghead3){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
};

Node *lhead=NULL,*ltail=NULL;
Node *lhead2=NULL,*ltail2=NULL;
Node *lhead3=NULL,*ltail3=NULL;
int lsize=0,lsize2=0,lsize3=0;
class local_bus{

	public:
		
		int countNode(Node *ptr){
			int count=0;
			while(ptr!=NULL){
				ptr=ptr->next;
				count++;
			}
			return (count);
		}
		
		void insertatmid1(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			ba:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;
			if(seatno<=20){
			    if(lhead == NULL){
			        lhead = newNode;  
			        ltail = newNode;  
			        newNode->next = lhead;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (lsize % 2 == 0) ? (lsize/2) : ((lsize+1)/2);
			        temp = lhead;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    lsize++;
			    sort(lhead, lsize);
			}
			else{
				cout<<"We have Only 20 Seats. Enter the Suitable Seat no in Range of 1-20 !\n";
				goto ba;
			}
		}
		
		void Adisplay1() {
			if(lhead==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=lhead;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != lhead);
			}
		}
		void Adisplay2() {
			if(lhead2==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=lhead2;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != lhead2);
			}
		}
		void Adisplay3() {
			if(lhead3==NULL){
				cout<<"The Bus is Empty ! No Reserved Seats :(";
			}
			else{
				Node* ptr=lhead3;
				cout<<"Seat No:\tCNIC:\t\tName:"<<endl;
				do {
					cout<<ptr->Seat_no<<"\t\t"<<ptr->CNIC<<"\t\t"<<ptr->Name<<endl;
					ptr = ptr->next;
					}while(ptr != lhead3);
			}
		}
		
		void swapNodes(Node** head_r){
			int x,y;
			cout<<"Enter Your Seat Number: ";
			cin>>x;
			cout<<"Enter the Seat Number you want to change with: ";
			cin>>y;
		    if (x == y){
		        return;
		    }
		    Node *prevX = NULL, *currX = *head_r;
		    while (currX && currX->Seat_no != x) {
		        prevX = currX;
		        currX = currX->next;
		    }
		    Node *prevY = NULL, *currY = *head_r;
		    while (currY && currY->Seat_no != y) {
		        prevY = currY;
		        currY = currY->next;
		    }
		    if (currX == NULL || currY == NULL){
		        return;
		    }
		    if (prevX != NULL){
		        prevX->next = currY;
		    }
		    else{
		        *head_r = currY;
		    }
		    if (prevY != NULL){
		        prevY->next = currX;
		    }
		    else{
		        *head_r = currX;
		    }
		    Node* temp = currY->next;
		    currY->next = currX->next;
		    currX->next = temp;
		    cout<<"\nYour Seat Has Been Swaped Successfully :) \n";
		}
		void display1(){
			Node *temp=lhead->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != lhead);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		void display2(){
			Node *temp=lhead2->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != lhead2);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		void display3(){
			Node *temp=lhead3->next;
		    do {
		        temp = temp->next;
		    } while (temp->next != lhead3);
			cout<<"\t\t <=========== BILL RECIPT ===========>\n";
			cout<<"\t\t Name : "<<temp->Name<<endl;
			cout<<"\t\t CNIC : "<<temp->CNIC<<endl;
			cout<<"\t\t SEAT NO : "<<temp->Seat_no<<endl;
			cout<<"\t\t =====================================\n";
			cout<<"\t\t BILL : 50"<<endl;
			cout<<"\t\t =====================================\n";
		}
		
		void search_delete(){
			int data;
			cout<<"\nEnter Seat Number to Delete Element : ";
			cin>>data;
			int flag=0;
			Node *temp=lhead;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
				lhead=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != lhead){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
		
		void insertatmid2(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			bc:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno; 
			if(seatno<=20){
			    if(lhead == NULL){
			        lhead2 = newNode;  
			        ltail2 = newNode;  
			        newNode->next = lhead2;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (lsize2 % 2 == 0) ? (lsize2/2) : ((lsize2+1)/2);
			        temp = lhead2;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    lsize2++;
			    sort(lhead2, lsize2);
			}
			else{
				cout<<"We have Only 20 Seats. Enter the Suitable Seat no in Range of 1-10 !\n";
				goto bc;
			}
		}
		void search_delete2(){
			int data;
			cout<<"\nEnter Seat Number To Delete : ";
			cin>>data;
			int flag=0;
			Node *temp=lhead2;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n\n";
				lhead2=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != lhead2){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
		
		void insertatmid3(){
			int i,seatno; 
		    string name,cnic;
		    Node *newNode=new Node;
		    cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter your CNIC: ";
			cin>>cnic;
			bd:
			cout<<"Enter Seat Number: ";
			cin>>seatno;
		    newNode->Name = name;
			newNode->CNIC=cnic;
			newNode->Seat_no=seatno;
			if(seatno<=20){
			    if(lhead == NULL){
			        lhead3 = newNode;  
			        ltail3 = newNode;  
			        newNode->next = lhead3;  
			    }  
			    else{  
			        Node *temp=NULL, *current = NULL;
			        int count = (lsize3 % 2 == 0) ? (lsize3/2) : ((lsize3+1)/2);
			        temp = lhead3;
			        for(i = 0; i < count; i++){
			            current = temp; 
			            temp = temp->next;  
			        }
			        current->next = newNode;
			        newNode->next = temp;  
			   	}  
			    lsize3++;
			    sort(lhead3, lsize3);
			}
			else{
				cout<<"We have Only 20 Seats. Enter the Suitable Seat no in Range of 1-10 !\n";
				goto bd;
			}
		}
		void search_delete3(){
			int data;
			cout<<"\nENTER Seat Number TO DELETE : ";
			cin>>data;
			int flag=0;
			Node *temp=lhead3;
			Node *prev;
			if(temp->Seat_no==data){
				cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
				lhead3=temp->next;
				free(temp);
				flag=1;
//				break;
			}
			else{
				while(temp->next != lhead3){
			        prev=temp;
					temp=temp->next;
					if(temp->Seat_no==data){
						cout<<"\nTHE SEAT NUMBER "<<temp->Seat_no<<" FOUND AND DELETED SUCCESSFULLY\n";
						prev->next=temp->next;
						free(temp);
						flag=1;
						break;
					}	
				}
			}
			if(flag!=1){		
				cout<<"ELEMENT NOT FOUND.... ";
			}
		}
};

int no_Redline=3,no_greenline=3,no_local=3;
int seat_Redline=10,seat_greenline=15,seat_local=20;

class Bus_Reservation{
	private:
		string Admin_pin="111",Admin_name="admin";
	public:
		void Intro(){
			cout<<"\n\n\n\t\t\t\t<============  Welcome To:  ============>\n";
			cout<<"\t\t\t\t<------- Bus Reservation System -------->\n\n";
			cout<<"\t\t\t\t<-------- Group Members Name/ID -------->\n";
			cout<<"\t\t\t\tSyed Muhammad Baqir Shah (FA21-BSSE-0053)\n";
			cout<<"\t\t\t\tSyed Sarim Ali\t\t (FA21-BSSE-0059)\n\n";
			cout<<"\t\t\t\t<------------- Submitted To ------------>\n";
			cout<<"\t\t\t\t\t     Miss Anam Javed\n";
			system("pause");
			system("cls");
			Menu1();
		}
		void bus_available(){
			cc:
			cout<<"\t\t\t\t<=========  Busses Classes:  =========>\n";
			cout<<"\t\t1. Red Line Bus.\n";
			cout<<"\t\t2. Green Line Bus.\n";
			cout<<"\t\t3. Local Bus.\n";
			cout<<"\t\t4. Main Menu.\n";
			int n;
			cout<<"\t\t Enter Option : ";cin>> n;
			switch(n){
				case 1:
					cout<<"No of Red Busses:"<<no_Redline<<endl;
					cout<<"No of seats per Red Bus: "<<seat_Redline<<endl;
					cout<<"Route 1: Johar to Saddar"<<endl;
					cout<<"Route 2: Defence to Saddar"<<endl;
					cout<<"Route 3: Malir to Saddar"<<endl;
					goto cc;
					break;
				case 2:
					cout<<"No of Green Busses:"<<no_greenline<<endl;
					cout<<"No of seats per Green Bus: "<<seat_greenline<<endl;
					cout<<"Route 1: Nazimabad to Saddar"<<endl;
					cout<<"Route 2: Garden to Saddar"<<endl;
					cout<<"Route 3: Saddar to Hadeed"<<endl;
					goto cc;
					break;
				case 3:
					cout<<"No of Local Busses:"<<no_local<<endl;
					cout<<"No of seats per Local Bus: "<<seat_local<<endl;
					cout<<"Route 1: Nazimabad to Lyari"<<endl;
					cout<<"Route 2: Hadeed to Johar"<<endl;
					cout<<"Route 3: Saddar to Gulshan"<<endl;
					goto cc;
					break;
				default:
					break;
			}
		}
		
		int Booking_Seats(){
			system("pause");
			system("cls");
			dd:
			cout<<"\t\t<======== Seats Booking ========>\n";
			cout<<"\t\t1. Red Buss Line.\n ";
			cout<<"\t\t2. Green Buss Line.\n";
			cout<<"\t\t3. Local Buss Service.\n";
			cout<<"\t\t4. Back to Main Menu.\n";
			cout<<"What Type of Buss Do you Want: ";
			int type;
			cin>>type;
			while(1){
				switch(type){
					case 1:
						cout<<"\t\t<======= Red Line Bus Service: =======>\n";
						Red_Line rl;
						int bus_no;
						ad:
						cout<<"Enter The Number Of Bus According to Route: ";
						cin>>bus_no;
						switch(bus_no){
							case 1:
								cout<<"\t\tBus 1:\n";
								rl.insertatmid1();
								rl.display1();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
								break;
							case 2:
								cout<<"\t\tBus 2:\n";
								rl.insertatmid2();
								rl.display2();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
								break;
							case 3:
								cout<<"\t\tBus 3:\n";
								rl.insertatmid3();
								rl.display3();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
								break;
							default:
								cout<<"\n\nYou Have Entered the Wrong Bus Number \n\n:";
								goto ad;
							break;
						}
					break;
					case 2:
						cout<<"\t\t<======= Green Line Bus Service: =======>\n";
						Green_Line Gl;
						int bus_no1;
						ac:
						cout<<"Enter The Number Of Bus According to Route: ";
						cin>>bus_no1;
						switch(bus_no1){
							case 1:
								cout<<"\t\tBus 1:\n";
								Gl.insertatmid1();
								Gl.display1();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
								break;
							case 2:
								cout<<"\t\tBus 2:\n";
								Gl.insertatmid2();
								Gl.display2();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
								break;
							case 3:
								cout<<"\t\tBus 3:\n";
								Gl.insertatmid3();
								Gl.display3();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
							break;
							default:
								cout<<"\n\nYou Have Entered the Wrong Bus Number \n\n:";
								goto ac;
							break;
						}
					break;
					case 3:
						cout<<"\t\t<======= Local Bus Service: =======>\n";
						local_bus l;
						int bus_no2;
						ab:
						cout<<"Enter The Number Of Bus According to Route: ";
						cin>>bus_no2;
						switch(bus_no2){
							case 1:
								cout<<"\t\tBus 1:\n";
								l.insertatmid1();
								l.display1();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
							break;
							case 2:
								cout<<"\t\tBus 2:\n";
								l.insertatmid2();
								l.display2();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
							break;
							case 3:
								l.insertatmid3();
								l.display3();
								cout<<"\n\nThankYou For Using Our Buss Reservation System You'r Seat Have Been Booked!\n\n";
								system("pause");
								system("cls");
								goto dd;
							break;
							default:
								cout<<"\n\nYou Have Entered the Wrong Bus Number \n\n:";
								goto ab;
							break;
						}
					break;
					default:
						system("cls");
						Menu1();
						break;
					break;
				}
			}
			
		}
		
		void Menu1(){
	   		time_t  now= time(0);
	 	  	string dt = ctime(&now);
	 	  	aa:
			cout << "\t\t\t\tTHE LOGIN DATE & TIME IS :" << dt << endl;
			cout<<"\t\t\t\t<=========  Menu:  =========>\n";
			cout<<"\t\t1. Buses Available.\n";
			cout<<"\t\t2. Seats Booking.\n";
			cout<<"\t\t3. Admin Login.\n";
			cout<<"\t\t4. Exit.\n";
			int n;
			cout<<"Enter the Option: ";
			cin>>n;
			switch(n){
				case 1:
					bus_available();
					system("pause");
					system("cls");
					goto aa;
					break;
				case 2:
					Booking_Seats();
					system("pause");
					system("cls");
					goto aa;
					break;
				case 3:
					Admin_login();
					goto aa;
					break;
				default:
					cout<<"Thank You For Using Our Buss Reservation System  :) ";
					break;
			}
		
		}
		
		void Admin_login(){
			string username,pin;
			sb:
			cout<<"Enter The Username:";
			cin>>username;
			if(username==Admin_name){
				as:
				cout<<"Enter The Pin: ";
				cin>>pin;
				if(Admin_pin==pin){
					bb:
					system("cls");
					cout<<"\t\t\t\t<=========  Admin Menu:  =========>\n";
					cout<<"\t\t1. Cancel Seat.\n";
					cout<<"\t\t2. Change Seat.\n";
					cout<<"\t\t3. Check Seats Details.\n";
					cout<<"\t\t4. Add Seat Reservation.\n";
					cout<<"\t\t5. Back.\n";
					int n;
					cout<<"Enter the Option Number: "<<endl;
					cin>>n;
					switch(n){
						case 1:
							wa:
							cout<<"\n\t\t<========= Seat Cancellation: =========>"<<endl;
							int sys,bs_no;;
							cout<<"\t\t1. Red Buss Line.\n ";
							cout<<"\t\t2. Green Buss Line.\n";
							cout<<"\t\t3. Local Buss Service.\n";
							cout<<"\t\t4. Back to Admin Menu.\n";
							cout<<"Enter the Bus Reservation System: "<<endl;
							cin>>sys;
							switch(sys){
								case 1:
									Red_Line rl;
									cout<<"<======== Red Bus Seat Cancellation: =======>";
									rr:
									cout<<"\nEnter the Bus Number: ";
									cin>>bs_no;
									switch(bs_no){
										case 1:
											rl.search_delete1();
											goto wa;
										break;
										case 2:
											rl.search_delete2();
											goto wa;
										break;
										case 3:
											rl.search_delete3();
											goto wa;
										break;
										default:
											goto rr;
										break;
									}
								break;
								case 2:
									Green_Line gl;
									cout<<"<======== Green Bus Seat Cancellation: =======>";
									gg:
									cout<<"\nEnter the Bus Number: ";
									cin>>bs_no;
									switch(bs_no){
										case 1:
											gl.search_delete();
											goto wa;
										break;
										case 2:
											gl.search_delete2();
											goto wa;
										break;
										case 3:
											gl.search_delete3();
											goto wa;
										break;
										default:
											goto gg;
										break;
									}
								break;
								case 3:
									local_bus l;
									cout<<"<======== Local Bus Seat Cancellation: =======>";
									ll:
									cout<<"\nEnter the Correct Bus Number: ";
									cin>>bs_no;
									switch(bs_no){
										case 1:
											l.search_delete();
											goto wa;
										break;
										case 2:
											l.search_delete2();
											goto wa;
										break;
										case 3:
											l.search_delete3();
											goto wa;
										break;
										default:
											goto ll;
										break;
									}
								break;
								default:
									Admin_login();
								break;
							}
							system("pause");
							system("cls");
							
							goto bb;
							break;
						case 2:
							wb:
							cout<<"\n\t\t<========= Change Seats: =========>"<<endl;
							int sys2,bs_no2;
							cout<<"\t\t1. Red Buss Line.\n ";
							cout<<"\t\t2. Green Buss Line.\n";
							cout<<"\t\t3. Local Buss Service.\n";
							cout<<"\t\t4. Back to Admin Menu.\n";
							cout<<"Enter the Bus Reservation System: "<<endl;
							cin>>sys2;
							switch(sys2){
								case 1:
									Red_Line rl;
									cout<<"<======== Red Bus Seat change: =======>";
									r2:
									cout<<"\nEnter the Bus Number: ";
									cin>>bs_no2;
									switch(bs_no2){
										case 1:
											rl.swapNodes(&head);
											goto wb;
										break;
										case 2:
											rl.swapNodes(&head2);
											goto wb;
										break;
										case 3:
											rl.swapNodes(&head3);
											goto wb;
										break;
										default:
											goto r2;
										break;
									}
								break;
								case 2:
									Green_Line gl;
									cout<<"<======== Green Bus Seat Change: =======>";
									g2:
									cout<<"\nEnter the Bus Number: ";
									cin>>bs_no2;
									switch(bs_no2){
										case 1:
											gl.swapNodes(&ghead);
											goto wb;
										break;
										case 2:
											gl.swapNodes(&ghead2);
											goto wb;
										break;
										case 3:
											gl.swapNodes(&ghead3);
											goto wb;
										break;
										default:
											goto g2;
										break;
									}
								break;
								case 3:
									local_bus l;
									cout<<"<======== Local Bus Seat Change: =======>";
									l2:
									cout<<"\nEnter the Correct Bus Number: ";
									cin>>bs_no2;
									switch(bs_no2){
										case 1:
											l.swapNodes(&lhead);
											goto wb;
										break;
										case 2:
											l.swapNodes(&lhead2);
											goto wb;
										break;
										case 3:
											l.swapNodes(&lhead3);
											goto wb;
										break;
										default:
											goto l2;
										break;
									}
								break;
								default:
									Admin_login();
								break;
							}
							system("pause");
							system("cls");
							
							goto bb;
							break;
						case 3:
							wt:
							cout<<"\n\t\t<========== Seats Details ==========>"<<endl;
							int sys4,bs_no4;
							cout<<"\t\t1. Red Buss Line.\n ";
							cout<<"\t\t2. Green Buss Line.\n";
							cout<<"\t\t3. Local Buss Service.\n";
							cout<<"\t\t4. Back to Admin Menu.\n";
							cout<<"Enter the Bus Reservation System: "<<endl;
							cin>>sys4;
							switch(sys4){
								case 1:
									Red_Line rl;
									cout<<"<======== Red Bus Seat Details: =======>";
									dr:
									cout<<"\nEnter the Bus Number: ";
									cin>>bs_no2;
									switch(bs_no2){
										case 1:
											rl.Adisplay1();
											goto wt;
										break;
										case 2:
											rl.Adisplay2();
											goto wt;
										break;
										case 3:
											rl.Adisplay3();
											goto wt;
										break;
										default:
											goto dr;
										break;
									}
								break;
								case 2:
									Green_Line gl;
									cout<<"<======== Green Bus Seat Details: =======>";
									dg:
									cout<<"\nEnter the Bus Number: ";
									cin>>bs_no2;
									switch(bs_no2){
										case 1:
											gl.Adisplay1();
											goto wt;
										break;
										case 2:
											gl.Adisplay2();
											goto wt;
										break;
										case 3:
											gl.Adisplay3();
											goto wt;
										break;
										default:
											goto dg;
										break;
									}
								break;
								case 3:
									local_bus l;
									cout<<"<======== Local Bus Seat Details: =======>";
									dl:
									cout<<"\nEnter the Correct Bus Number: ";
									cin>>bs_no2;
									switch(bs_no2){
										case 1:
											l.Adisplay1();
											goto wt;
										break;
										case 2:
											l.Adisplay2();
											goto wt;
										break;
										case 3:
											l.Adisplay3();
											goto wt;
										break;
										default:
											goto dl;
										break;
									}
								break;
								default:
									Admin_login();
								break;
							}
							system("pause");
							system("cls");
							
							goto bb;
							break;
							system("pause");
							system("cls");
							goto bb;
							break;
						case 4:
							Booking_Seats();
							system("pause");
							system("cls");
							goto bb;
							break;
						default:
							system("cls");
							Menu1();
							break;
					}
				}
				else{
					cout<<"Enter the Pin Correctly :(\n\n";
					cout<<"Correctly ";
					goto as;
				}
			}
			else{
				cout<<"Enter the User Name Correctly :(\n\n";
				cout<<"Correctly ";
				goto sb;
			}
		}
		
};

int main(){
	Bus_Reservation bs;
	bs.Intro();
	
	
	return 0;
}
