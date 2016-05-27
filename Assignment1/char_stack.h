/* File: char_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();

  private:
    char * m_array; 
    static const int capacity = 1000*250;
    int A[capacity];
    int maxsize;
    int top_index;
    // fill this in.
};
