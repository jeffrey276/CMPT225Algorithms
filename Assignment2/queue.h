/* File: queue.h       

  Header file for a very basic linked-list based dynamic Queue class.

*/

class Queue
{
  public:

    Queue(); // Constructs a new empty queue.
    Queue( const Queue& q );// Copy constructor.
    ~Queue();// Destructor.
    
    void enqueue( int item ); // Enqueues <item>.
    int dequeue();  // Dequeues the front item.
    int front();  // Returns the front item without dequeuing it.
    bool empty();  // Returns true iff the queue contains no items.
    int size();  // Returns the current number of items in the queue.
    int makeUnique(int item); // If <item> occurs in the queue more 
      // than once, remove all occurrences of <item> except the first. 
      // Return the number of elements removed.

  private:
    class node  // node type for the linked list 
    {
       public:
           node(int new_data, node * next_node ){
              data = new_data ;
              next = next_node ;
           }
           int data ;
           node * next ;
    };

    node * front_p ; // pointer to the (node containing the) next item 
              //  which to be dequeud, or NULL if the queue is empty.

    node * back_p ; // pointer to the (node containing the) last item 
              // which was enqueued, or NULL if the queue is empty.

    int current_size ; // current number of elements in the queue.
};