//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------

#include "StudentNode.h"

//----------------------------------------------
int main()
{
    
    string name;
   string address;
   float gpa;
   StudentNode *head = NULL;
   for (int i=0; i<5; i++)
   {
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter address: ";
      cin >> address;
      cout << "Enter GPA: ";
      cin >> gpa;

      // ADD HERE
      StudentNode *ptr1 = new StudentNode(name, address, gpa);
      ptr1->setNext(head);
      head = ptr1;
   }
   head->print();
}