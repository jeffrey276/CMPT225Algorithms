// Header file for linked list class 
// For Implementation Version 2

class LL2{
public:
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/
	LL2(); //default construtor
	LL2(const LL2& lst); //copy constructor

	void add(int data);
	// A new node containing the given data is inserted at the front
	//      of the list

	void insertAt(int pos, int data);
	// A new node containing the given data is inserted at the given
	//      position in the list
	
	bool remove(int data );
	// The first incidence of the given data is removed from the list.
	//      Returns true if data is found (and removed), false otherwise
	
	void removeAll();
	// Empties the list.

	void printList();
	// Prints the contents of the list to the screen, in order
	
	int GetLargest();
	
	void removeDuplicates();
	
	bool isEmpty();

private:
	/* A struct contains data variables (which are accessed using dot
	 * notation and arrow notation in the same way that object methods 
         * or attributes are accessed).  Structs cannot have methods.
         * You can think of them as simple classes which have only data
         * memebers. */
	// List node
	struct Node {
		int data; //list data
		Node *next; //pointer to next item in the list
	};

	Node *head; //Pointer to the first node in the list
	int size; //Records the number of nodes in the list
};


