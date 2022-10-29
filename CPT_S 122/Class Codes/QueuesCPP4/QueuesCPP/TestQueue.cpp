#include "TestQueue.h"

void Tests::TestQueue::testEnqueueOnEmpty()
{
	Queue q; // empty queue

	bool success = q.enqueue("pj1");

	if (success)
	{
		if (!q.isEmpty())
		{
			if (q.getHeadPtr()->getData() == "pj1")
			{

			}
		}
	}
}