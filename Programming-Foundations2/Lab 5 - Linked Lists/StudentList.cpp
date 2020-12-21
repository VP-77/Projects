//----------------------------------------------
// Purpose: Implement student linked list 
// Author:  John Gauch
//----------------------------------------------

#include "StudentList.h"
#include <time.h>

//----------------------------------------------
StudentList::StudentList()
{
   Head = NULL;
}

//----------------------------------------------
StudentList::StudentList(const StudentList & list)
{
   // Create first node
   StudentNode *copy = new StudentNode();
   Head = copy;

   // Walk list to copy nodes
   StudentNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->setNext(new StudentNode());
      copy = copy->getNext();
      copy->setName(ptr->getName());
      copy->setAddress(ptr->getAddress());
      copy->setGPA(ptr->getGPA());
      copy->setNext(NULL);
      ptr = ptr->getNext();
   }

   // Tidy first node
   copy = Head;
   Head = copy->getNext();
   delete copy;
}

//----------------------------------------------
StudentList::~StudentList()
{
}

//----------------------------------------------
void StudentList::insertHead(string name, string address, float gpa)
{
    // Insert new node
   StudentNode *ptr = new StudentNode(name, address, gpa);
   ptr->setNext(Head);
   Head = ptr;
}

//----------------------------------------------
void StudentList::insertTail(string name, string address, float gpa)
{
   // Find tail node
   StudentNode *ptr = Head;
   while ((ptr != NULL) && (ptr->getNext() != NULL))
      ptr = ptr->getNext();

   
    if (ptr != NULL)
        ptr->setNext(new StudentNode(name, address, gpa));
    else
        Head = new StudentNode(name, address, gpa);

}

//----------------------------------------------
void StudentList::print() const
{
   StudentNode *ptr = Head;
   while (ptr != NULL)
   {
      ptr->print();
      ptr = ptr->getNext();
   }
}

//----------------------------------------------
StudentNode *StudentList::searchName(string name)
{
   // Walk list to find node
   StudentNode *ptr = Head;
   while ((ptr != NULL) && (ptr->getName() != name))
      ptr = ptr->getNext();
   if (ptr != NULL)
        return ptr;
   else
        return NULL;
}

//----------------------------------------------
StudentNode *StudentList::searchGPA(float gpa)
{
    // Walk list to find node
   StudentNode *ptr = Head;
   while ((ptr != NULL) && (ptr->getGPA() <= gpa))
      ptr = ptr->getNext();
   if (ptr != NULL)
       return ptr;
   else
       return NULL;
}