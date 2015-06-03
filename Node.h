//Christopher Cano CS455 PA5

/*
----------Node-------------
+ data: Movie
+ *next: Node
---------------------------

---------HeadNode----------
+ count: int
+ *headPtr: Node
---------------------------
 */
#ifndef NODE_H
#define	NODE_H
#include "Movie.h"
using namespace std ;

struct Node {
	Movie data;
	Node *next;
};

struct HeadNode
{
	int count;
	Node *headPtr;
};


#endif	/* NODE_H */
