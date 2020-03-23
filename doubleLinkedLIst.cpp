#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node *prev;
};

class DoubleLinkedList{
	private:
		Node *head {NULL};
		Node *tail {NULL};
		
	public:
		Node *getHead(){
			return head;
		}
		
		// **** function to create a new node at the end : Start 
		void createNodeEnd(int _data){
			
			Node *newNode {NULL};
			newNode = new Node();
			
			newNode ->  data = _data;
			newNode -> next = NULL;
			newNode -> prev = NULL;
			
			if(head == NULL ){
				head = newNode;
				tail = newNode;
			}else{
				newNode -> prev = tail;
				tail -> next = newNode;
				tail = newNode;
				
			}
		}
		// **** function to create a new node at the end : End
		
		
		// **** function to create a new node at the start : Start
		void createNodeStart(int _data){
			
			Node *newNode {NULL};
			newNode = new Node();
			
			newNode ->  data = _data;
			newNode -> next = NULL;
			newNode -> prev = NULL;
			
			
			if(head == NULL ){
				head = newNode;
				tail = newNode;
			}else{
			newNode -> next = head;
			head -> prev = newNode;
			
			head = newNode;	
			}
	
		}
		// **** function to create a new node at the start :  End
		
		
		// **** function to create node after a given node : Start
		void createNodeAfter(int _data , int _nodeNumber){
			
			Node *current {NULL};
			current = head;
			
			for (int i = 1; i < _nodeNumber; ++i){
				current = current -> next;
			}
			
			Node *nextNode = current -> next;
			
			Node *newNode{NULL};
			newNode = new Node();
			
			newNode -> data = _data;
			
			newNode -> prev = current;
			newNode -> next = nextNode;
			
			nextNode -> prev = newNode;
			current -> next = newNode ;
			 
		}
		// **** function to create node after a given node :  End
		
		
		// **** function to print the list from the start : Start
		void printListFromStart(){
			
			Node *current{NULL};
			current = head;
			
			cout << "the list contains : " << endl;
			while (current != NULL){
				cout << current -> data << endl;
				current = current -> next;
			}
		}
		// **** function to print the list from the start : End


		// **** function to print the list fromt he end :  Start 
		void printListFromEnd(){
			Node *current {NULL};
			current =  tail;
			
			cout << "the list from the end contains : " << endl;
			
			while(current != NULL){
				cout << current -> data << endl;
				current = current -> prev;
			}
			
		}
		// **** function to print the list fromt he end :  End

		
		// **** function to print data of a given node : Start
		void printGivenNode(int _nodeNumber){
			
			Node *current {NULL};
			current = head;
			
			for (int i = 1; i < _nodeNumber; ++i){
				current = current -> next;
			}
			
			cout <<"data at the " << _nodeNumber << "rd node is : " <<  current -> data << endl;
		} 
		// **** function to print data of a given node :  End

		void printListRecursive(Node *current ){
			
			if (current == NULL)
				return;
				
			cout << current -> data << endl;
			printListRecursive(current->next);
		}

		// **** function to delete a given node :  Start 
		void deleteNode(int _nodeNumber){
			Node *current{NULL};
			current = head;
			
			for (int i = 1; i < _nodeNumber; ++i){
				current =  current -> next;
			}
			
			if (current == head ){
				head =  current -> next;
			}else{
				Node *previousNode {NULL};
				Node *nextNode {NULL};
				
				previousNode = current -> prev;
				nextNode = current -> next;
				
				previousNode -> next = nextNode;
				nextNode -> prev = previousNode;
			}

			
			
		}
		// **** function to delete a given node : End
		
		
};

int main(){
	
	DoubleLinkedList l1;
	
	l1.createNodeEnd(1);
	l1.createNodeEnd(2);
	l1.createNodeEnd(3);
	l1.createNodeEnd(4);
	l1.createNodeStart(0);
	l1.createNodeStart(-1);
	
	l1.createNodeAfter(10,1);
	
	

	l1.printListFromStart();
	l1.printListFromEnd();
	l1.printGivenNode(3);
	
	l1.deleteNode(2);
	l1.deleteNode(3);
	cout << "after deleting a node " << endl;
	l1.printListFromStart();
	cout<< "-------------------------"<< endl;
	l1.printListRecursive(l1.getHead());

	
	
	return 0;
}
