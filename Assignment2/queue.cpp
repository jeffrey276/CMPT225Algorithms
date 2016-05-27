#include "queue.h"// contains the declarations of the variables and functions.
#include <iostream>
#include <cstring>
using namespace std;

Queue::Queue(){
    front_p = NULL;
    back_p = NULL;
    current_size = 0;
}
Queue::Queue(const Queue& q){
    if (q.front_p == NULL && q.back_p == NULL){
        front_p = NULL;
        back_p = NULL;
        current_size = 0;
    }
    else{
        node * temp = q.front_p;
        while(temp != NULL){
            enqueue(temp -> data);
            temp = temp -> next;
            
        }
        
    }
}
Queue::~Queue(){
    node * h = front_p;
    node * temp;
    while (h != NULL){
        temp = h -> next;
        delete h;
        h = temp;
    }

}
void Queue::enqueue(int x){
    node * temp = new node(x, NULL);
    if(front_p==NULL && back_p==NULL){
        front_p=back_p=temp;
        current_size++;
        return;
    }
    else{
        back_p->next=temp;
        back_p=temp;
        current_size++;
    }

}
int Queue::dequeue(){
    int x;
    if (!front_p){

        return 0;
    }
    current_size--;
    node *popped = front_p;
    front_p=front_p->next;
    if(!front_p){
        back_p=NULL;
    }
    x = popped->data;
    delete popped;
    return x;
}

int Queue::makeUnique(int item){
	node *ptrA;
	node *ptrB;
	node *dupe;
     	ptrA = front_p;
     	if(ptrA == NULL){
        	return 0;
     	}
     	int count =0;
	while(ptrA != NULL && ptrA->next != NULL){
		ptrB=ptrA;
		while(ptrB->next != NULL){
 			if(ptrA->data == item && ptrB->next->data == item){
                    		dupe = ptrB->next;
                    		ptrB->next = ptrB->next->next;
                    		delete dupe;
				count++;
                    		current_size--;
                	}
                	else{
                    		ptrB = ptrB->next;
                	}
            	}
            ptrA=ptrA->next;
     	}
     	return count;
}

int Queue::size(){
    return current_size;
}
int Queue::front(){
    return front_p -> data;
}
bool Queue::empty(){
    return (current_size ==0);
}



