// Implementation of the LinkedList class
// Version 2: Copy constructor does a deep copy.

#include "LL2.h"
#include <string>
#include <iostream>

using namespace std; 

// Default constructor
LL2::LL2(){
	head = NULL;
	size = 0;
}

// Copy constructor.
// Makes a copy of a given LL2 instance.
/* This version of the copy constructor only creates a SHALLOW COPY.
  * it copies the size and head variables, but this does not create 
  * a new list.  It creates a new instance of the LL2 class,
  * in which head points to the first node of the LL2 instance 
  * it is supposed to be a copy of. Thus, there are two LL2 instances, 
  * one actual linked list of nodes! */
LL2::LL2(const LL2& lst){
        if ( lst.head == NULL){
            head = NULL;
            size = 0;
        }
        else{
            head = new Node;
            head -> data = lst.head -> data;
            Node *newNode = head;
            Node *oldNode = lst.head -> next;
            while (oldNode != NULL){
                newNode -> next = new Node;
                newNode = newNode -> next;
                newNode -> data = oldNode -> data;
                oldNode = oldNode -> next;
            }
            newNode -> next = NULL;
            size = lst.size;
            
        }
}

/**************************************************************************/
// Operations

// Adds a node to the start of the list, making it the new head
void LL2::add(int x){
	Node *p = new Node; //temporary node
	// Assign appropriate values to the new node
	p -> data = x;
	p -> next = head;
	// Make the head point to the new node
	head = p;	
	size++;
}

// Inserts a new node at the given position (or index) in the list
void LL2::insertAt(int pos, int x){
        Node *p;
        Node *newNode;

        // Check that pos is a valid index
        if (pos <= size){
                newNode = new Node; //new node
                newNode->data = x;

                // Deal with case when item is to be inserted at the head of the list
                if (pos == 0){
                        newNode->next = head;
                        head = newNode;
                }// if(pos == 0)
                else{
                        p = head;
                        // Move to position BEFORE insertion point
                        for(int i = 0; i < pos-1; i++){
                                // Check that p points to a node
                                // Note using exception handling should throw an exception here
                                if(p == NULL){
                                        return;
                                }
                                p = p->next;
                        }//for
                        // Insert node
                        newNode->next = p->next;
                        p->next = newNode;
                }//else (pos != 0)
                size++;
        }//else (pos >= size) do nothing
}


// Removes the first node containing the given data, returns true
// iff data is found (and deleted).
bool LL2::remove(int x){
	Node *p = head;
	Node *temp;
	// Check to see if the list exists
	if (head == NULL){
		return false;
	}
	// Check to see if target is at the head of the list
	else if (head->data == x){
		head = head->next;
		delete p; //currently assigned head
		size--;
		return true;
	}
	// Otherwise iterate through list
	else{
		while(p->next != NULL){
			// Check next node for target
			if(p->next->data == x){
				temp = p->next;
				p->next = p->next->next;
				delete temp;
				return true;
			}
			p = p->next;
		}
	}
	return false;
}

// Empties the list by deleting each node, starting at the head
void LL2::removeAll(){
	head = NULL;
	size = 0;
}

// Prints the entire list (head first) to the screen.
/* Note that there is some debate about whether or not this type of
 * method belongs in a class.  The argument (briefly) is that a class
 * shouldn't be responsible for its own display as it cannot foresee
 * how it is to be displayed. */
void LL2::printList(){
	Node *p = head;
	cout << "["; //Nice format!
	// Traverse the list
	while (p != NULL){
		cout << p -> data; // Print data
		p = p -> next; // Go to next node
		if (p != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "]"; // Don't print a newline - it might not be wanted
}

void LL2::removeDuplicates() //taken from http://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
{
  Node *ptr1, *ptr2, *dup;
  ptr1 = head;
 
  /* Pick elements one by one */
  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;
 
     /* Compare the picked element with rest of the elements */
     while(ptr2->next != NULL)
     {
       /* If duplicate then delete it */
       if(ptr1->data == ptr2->next->data)
       {
          /* sequence of steps is important here */
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          delete dup;
          size++;
       }
       else /* This is tricky */
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}
int LL2::GetLargest() // taken from http://www.bitsbyta.com/2011/03/how-to-find-largest-element-in-singly.html
{
       Node*tptr=head;
       int largest=head->data;

              while ( tptr != NULL )
              {
                     if ( tptr->data > largest )
                           largest = tptr->data;
                     tptr = tptr->next;
              }
       return largest;
}

bool LL2::isEmpty()// checks if empty list
 {
     Node *p = head;
    if (p == 0){
        return 1;}
        else{
            return 0;
        }

    
 }
