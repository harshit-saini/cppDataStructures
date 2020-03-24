#include <iostream>

using namespace std;

class StackByArray{
	private:
		int length;
		int array[1000] {0};
		int head = -1 ;
		
	public:
		

		
		void push(int _data){
			array[++head] = _data;
		}
		
		void printArray(){
			
			if(head == -1){
				cout << "stack is empty" << endl;
				return;				
			}

			
			for (int i = 0; i <= head; ++i){
				cout << array[i] << endl;
			}
		}
		
		
		void peekTop(){
			if(head!= -1){
				cout << array[head] << endl;
				return;
			}
			
			cout<< "the stack is empty" << endl;
		}
		
		void pop(){
			if(head != -1){
				cout << "the element " << array[head--] << " is poped from the stack" << endl;
				return;
			}
			
			cout << "the stack is empty"<< endl;
		}
		
};



class StackNode{
	public:
		int data;
		StackNode *prev;
};

class StackByLinkedList{
	private:
		StackNode *head;
	public:
		StackByLinkedList(){
			head = NULL;
		}	
		
		void push(int _data){
			
			StackNode *newNode{NULL};
			newNode = new StackNode();
			newNode -> data = _data;
			newNode -> prev = head;
			head = newNode;
		}
		
		void printStack(){
			
			StackNode *current = head;
			while(current != NULL){
				cout << current -> data << endl;
				current = current -> prev;
			}
		}
	
	
		void pop(){
			
			if(head != NULL){
				head =  head -> prev;
				return;
			}
			
			cout << "the stack is already empty" << endl; 

		}
};






int main(){
//	StackByArray s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//	s1.push(4);
//	s1.printArray();
//	s1.peekTop();
//	s1.pop();
//	s1.printArray();

	StackByLinkedList s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	s2.printStack();
	s2.pop();
	s2.printStack();

}
