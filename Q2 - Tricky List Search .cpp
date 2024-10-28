#include <iostream>
using namespace std;

class Node {
	public:
    const int data; //do not change this
    Node* next;
    Node* prev;

    Node(int d) : data(d)
	{
	    this->next = NULL;
	    this->prev = NULL;
    }
};

void insertionSort(Node *&head, Node *&tail)
{
	//funcation only called of the list is unsorted
}
int input(Node *&head, Node *&tail, int no_of_elements)
{
	//ask user for providing the number of items in the list. Then create n number of nodes
	return no_of_elements;
}
bool isSorted(Node *&head, Node *&tail)
{
	bool flag;
	//returns true if the list is sorted
	return flag;
}
bool binarySearch(Node *&head, Node *&tail, Node *&mid, int search_number)
{
	bool found;

	// add your code here
	//returms true of found

}

main()
{
	Node *head;
	Node *tail;
	Node *mid;
	int no_of_elements = 0;
	int search_number;
	//input
	//sort if required
	//input data for search
	//use binary search
	//print output
}
