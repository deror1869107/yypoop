#include "p2.hpp"
#include <iostream>

namespace oop{

	Node* push(Node *top,int n){
       if(!top){
           top = new Node;
           top->num = n;
           top->next = NULL;
           return top;
       }
       Node *ptr = new Node;
       ptr->num = n;
       ptr->next = top;
       return ptr;
	}
    Node* pop(Node *top){
        if(top){
            Node *ptr = top->next;
            delete top;
            return ptr;
        } else {
            return top;
        }
	}
    void print(Node *top ){ 
     //Output specification: top->space->top->space->¡K¡K 
     //std::cout<<top<<" "; //show example
        if(!top){
            return;
        }
        Node *ptr;
        do {
            std::cout << top->num << " ";
            ptr = top;
            top = top->next;
            delete ptr;
        } while(top);
    } 
}
