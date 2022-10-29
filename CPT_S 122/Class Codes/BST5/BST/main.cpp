// We are building a Binary Search Tree (BST) in this example.

// History: 3/22 - Implemented class templates for BST and Node.
//                 Made some changes to names of members to better
//                 suit our generic class templates. We applied our
//                 template to integers, std::strings, and Rational objects!!!
//          3/19 - Implemented private and public postorderTraversal ().
//                 started working with class templates.
//          3/15 - Implemented private recursive version of insert ().
//                 Implemented both public and private versions of inorderTraversal ().
//          3/12 - Implemented BST () constructor, Node () constructor,
//                 public version of insert () into a BST, and started
//                 implementing the recursive private version of insert into
//                 a BST. We'll finish the private version of insert ()
//                 on Monday, 3/15.

#include "Node.h"
#include "BST.h"
#include "Rational.h"

int main(void)
{
	//BST tree1;

	BST<int> tree1;
	BST<std::string> tree2;
	BST<Rational> tree3;

	//int n = 50;
	tree1.insert(50);
	tree1.insert(10);
	tree1.insert(25);
	tree1.insert(30);
	tree1.insert(75);

	tree1.inorderTraversal();
	tree1.postorderTraversal();

	tree2.insert("cat");
	tree2.insert("dog");
	tree2.insert("giraffe");
	
	tree2.inorderTraversal();

	Rational r1(4, 5), r2(10, 3), r3(5, 3);
	tree3.insert(r1);
	tree3.insert(r2);
	tree3.insert(r3);

	tree3.inorderTraversal();




	return 0;
}