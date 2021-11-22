#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <assert.h>
using namespace std;

template < class StackElementType >
class Stack
{
    public:
        Stack();
           void push(StackElementType& e);
           void pop(StackElementType& e);
           bool top(StackElementType& e);
           bool isEmpty();
           int num_of_elem();
           ~Stack();

    protected:

    private:
      struct Node;
      typedef Node * Link;
      struct Node {
       StackElementType data;
       Link next;
   };
   Link head;
   int number_of_elements;

};

template < class StackElementType >
Stack<StackElementType>::Stack()
{
    head=NULL;
    number_of_elements=0;
}

template < class StackElementType >
Stack <StackElementType>::~Stack()
{
    //dtor
}

template < class StackElementType >
void Stack < StackElementType >:: push(StackElementType& e)
{
   Link addedNode = new Node;
   assert(addedNode!=NULL);
   addedNode->data = e;
   addedNode->next = head;
   head = addedNode;
   number_of_elements++;

}

template < class StackElementType >
void Stack < StackElementType >::pop(StackElementType& e)
{
   Link temp;
   e=head->data;
   temp=head;
   head=head->next;
   delete temp;
   number_of_elements--;
}

template < class StackElementType >
 bool Stack < StackElementType >:: top(StackElementType& e)
{
   if (head==NULL)
        return false;
   else {e=head->data; return true;}
}

template < class StackElementType >
bool Stack < StackElementType >::isEmpty()
{
   return (head==NULL);
}
template < class StackElementType >
int Stack < StackElementType >::num_of_elem()
{
    return number_of_elements;
}

#endif // STACK_H
