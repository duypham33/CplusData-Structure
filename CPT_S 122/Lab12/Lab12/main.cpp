

#include "Queue.h"

int main(void)
{
	Queue<int>* pQ = new Queue<int>;
	pQ->printQueue();
	
	pQ->enqueue(5);
	pQ->printQueue();
	pQ->enqueue(7);
	pQ->enqueue(8);
	pQ->enqueue(4);
	pQ->printQueue();
	
	int data = 5;
	pQ->dequeue(data);
	pQ->printQueue();
	pQ->dequeue(data);
	pQ->printQueue();
	cout << "Removed data: " << data << endl;

	delete pQ;



	return 0;
}