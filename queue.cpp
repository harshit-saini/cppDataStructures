#include <iostream>

using namespace std;

class Queue{
	public:
		int front;
		int rear;
		size_t size;
		size_t capacity;
		int *array;
	
};

Queue *makeQueue(size_t _capacity){
	cout << "making a new queue" << endl;
	Queue *newQueue;
	newQueue = new Queue();
	newQueue -> capacity = _capacity;
	newQueue -> size = 0;
	newQueue -> front = 0;
	newQueue -> rear = _capacity -1;
	newQueue -> array = new int[(_capacity * sizeof(int))];
	cout << "size : " << newQueue -> size << endl;
	cout << "capacity : " << newQueue -> capacity << endl;
	cout << "front : " << newQueue -> front << endl;
	cout << "rear : " << newQueue -> rear << endl;
	return newQueue;
}

void enqueue(Queue *queue, int _data){
	cout << "-----------------" <<endl;
	if(queue -> size == queue -> capacity) {
		cout << "the queue is full" << endl;
		return;
	};
	
	queue -> rear = (queue -> rear + 1) % queue -> capacity ;
	// the above line is an important expression
	queue -> array[queue -> rear] = _data;
	queue -> size += 1;
	cout << _data << " added to the queue" << endl;
	
}


void printQueue(Queue *queue){
	cout << "--------------------" << endl;
	cout << "printing from front to rear" << endl;
	int current  = queue -> front ;
	for (int i = 1; i <= queue -> size ; ++i){
		cout << queue-> array[current] << endl;
	 	current =  (current + 1) % queue -> capacity;
	 }
	 
}


void dequeue(Queue *queue){
	queue -> front  = (queue -> front + 1) % queue -> capacity;
	queue -> size -= 1;
}

int main(){
	Queue *q1 = makeQueue(10);
	enqueue(q1, 1);
	enqueue(q1, 2);
	enqueue(q1, 3);
	enqueue(q1, 4);
	printQueue(q1);
	dequeue(q1);
	cout << "after removing 1 element :" << endl;
	printQueue(q1);
	cout << "adding more elements : " << endl;
	enqueue(q1, 5);
	enqueue(q1, 6);
	enqueue(q1, 7);
	enqueue(q1, 8);
	enqueue(q1, 9);
	enqueue(q1, 10);
	enqueue(q1, 11);
	enqueue(q1, 12);
	cout << "removing one element so that i can fit 12 in the queue" << endl;
	dequeue(q1);
	cout << "after removing 1 element :" << endl;
	enqueue(q1, 12);

	cout << "--------------------" << endl;
	cout << "--------------------" << endl;

	cout << "finally printing the queue" << endl;	
	printQueue(q1);
	


}
