#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*pre;
	
};
class linklist{
public:
	node*tail;
	node*head;

	
	linklist(){
		head=NULL;
		tail=NULL;
	}
	
	// forward traverse
	void forward_print(){
		node*temp;
		temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	
}

// reverse print
void reverse_print(){
		node*temp;
		temp=tail;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->pre;
		}
	
}
// delete last node
void deletelastnode(){
if(head!=NULL){
	
	if(head->next==NULL){
		head==NULL;
	}
	else{
		
		node* second_last = head;
    while (second_last->next->next != NULL) {
    	second_last = second_last->next;
	}
        
 
    // Delete last node
    delete (second_last->next);
 
    // Change next of second last
    second_last->next = NULL;
    
 
	}
}



}

// delete head node
void delteathead(){
	if(head==NULL){
		head=NULL;
	}
	else{	
   node*temp=head;
   head=head->next;
   delete temp;
   return;
}

}


// delete at specific position

void deleteatspecific(int position){
	node* temp=head;

	if(position < 1) {
    cout<<"\nposition should be >= 1.";
  } 
  else if (position == 1 && head != NULL) {
    head = head->next;
    free(temp);
    }
    if(position!=1){
    
    for(int i=1;i<position-1;i++){
    		if(temp!=NULL){
    			temp= temp->next;
			}
		}
		
		
		if(temp!=NULL && temp->next!=NULL){
		node* deletenode=temp->next;
		temp->next=temp->next->next;
		free(deletenode);
	}
	else{
		cout<<"the node is already null"<<endl;
	}
	
    	
	}
    
    
}

// insert at head

void insertathead(int element){
	node* athead_node =new node();
	athead_node->data=element;
	athead_node->next=NULL;
	athead_node->pre=NULL;
	if(head==NULL){
		head=athead_node;
	}
	
	else{
		head->pre=athead_node;
		athead_node->next=head;
		head=athead_node;
		
		
	}
	
	
}

// insert at end

void insert_end(int element){
	node* insert_end= new node();
	insert_end->data=element;
	insert_end->next=NULL;
	insert_end->pre=NULL;
	if(head==NULL){
		head=insert_end;
		
	}
	else{
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
			
		}
		insert_end->pre=temp;
		temp->next=insert_end;
	}
}

// insert at specific position
void insert_specific(int element,int position){
	node* specificnode= new node();
	specificnode->data=element;
	specificnode->next=NULL;
	specificnode->pre=NULL;
	
	if(position<1){
		cout<<"position should be >=1"<<endl;
	}
	else if(position==1){
		specificnode->next=head;
		head->pre=specificnode;
		head=specificnode;
	}
	else{
		node* temp=head;
		for(int i=1;i<position-1;i++){
			if(temp!=NULL){
				temp=temp->next;
				
			}
		}
		
		if(temp!=NULL){
			specificnode->next=temp->next;
			specificnode->pre=temp;
			temp->next=specificnode;
			
			
		}
		if(specificnode->next!=NULL){
			specificnode->next->pre=specificnode;
		}
		else{
			cout<<"previous node is null"<<endl;
		}
		
		
	}
	
}


	
};

int main(){
	linklist mylist;
	
	node*newnode= new node();
	newnode->data=5;
	newnode->next=NULL;
	newnode->pre=NULL;
	mylist.head=newnode;
	mylist.tail=newnode;
	
	// 2nd node creat
	newnode= new node();
	newnode->data=10;
	newnode->next=NULL;
	newnode->pre=mylist.tail;
	mylist.tail->next=newnode;
	mylist.tail=newnode;
	
	// 3rd node creat
	
	
	newnode=new node();
	newnode->data=15;
	newnode->next=NULL;
	newnode->pre=mylist.tail;
	mylist.tail->next=newnode;
	mylist.tail=newnode;
	
	while(true){
    cout<<"1) print node "<<endl;
	cout<<"2) print reverse node "<<endl;
	cout<<"3) delete first node "<<endl;
	cout<<"4) delete last node "<<endl;
	cout<<"5) delete specific node "<<endl;
	cout<<"6) insert at head "<<endl;
	cout<<"7) insert at tail node "<<endl;
	cout<<"8) insert at specific position "<<endl;
	cout<<"0) exit "<<endl;
	int user;
	cin>>user;
	
	switch(user){
		case 1:
			mylist.forward_print();
			cout<<endl;
			cout<<"----------"<<endl;
			break;
			case 2:
				mylist.reverse_print();
				cout<<endl;
			cout<<"----------"<<endl;
				break;
				case 3:
					mylist.delteathead();
					mylist.forward_print();
					cout<<endl;
			cout<<"----------"<<endl;
					break;
					case 4:
						mylist.deletelastnode();
						mylist.forward_print();
						cout<<endl;
			cout<<"----------"<<endl;
						break;
						case 5:
								cout<<"enter position to delete node"<<endl;
								int n;
								cin>>n;
							mylist.deleteatspecific(n);
							cout<<endl;
							mylist.forward_print();
			cout<<"----------"<<endl;
			break;
			case 6:
				
				cout<<"enter the data"<<endl;
				cin>>n;
				mylist.insertathead(n);
				mylist.forward_print();
				break;
				case 7:
					cout<<"enter the data"<<endl;
				cin>>n;
				mylist.insert_end(n);
				mylist.forward_print();
				break;
				case 8:
					cout<<"enter position to insert node"<<endl;
					int pos;
					cin>>pos;
					cout<<"enter the data element"<<endl;
					cin>>n;
					mylist.insert_specific(n,pos);
					mylist.forward_print();
					break;
					
				
							case 0:
								return 0;
			
	}
		
	}
	
}
