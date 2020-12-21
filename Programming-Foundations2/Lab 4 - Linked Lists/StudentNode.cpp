//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------

#include "StudentNode.h"

//----------------------------------------------
StudentNode::StudentNode()
{
    Next = NULL;
   Name = "";
   Address = "";
   GPA = 0;
}

//----------------------------------------------
StudentNode::StudentNode(string name, string address, float gpa)
{
    Next = NULL;
   Name = name;
   Address = address;
   GPA = gpa;
}

//----------------------------------------------
StudentNode::StudentNode(const StudentNode & student)
{
    Next = NULL;
   Name = student.Name;
   Address = student.Address;
   GPA = student.GPA;
}

//----------------------------------------------
StudentNode::~StudentNode()
{
}

//----------------------------------------------
string StudentNode::getName() const
{
   return Name;
}

//----------------------------------------------
string StudentNode::getAddress() const
{
   return Address;
}

//----------------------------------------------
float StudentNode::getGPA() const
{
   return GPA;
}

//----------------------------------------------
StudentNode* StudentNode::getNext() const
{
    return Next;
}

//----------------------------------------------
void StudentNode::setName(string name)
{
   Name = name;
}

//----------------------------------------------
void StudentNode::setAddress(string address)
{
   Address = address;
}

//----------------------------------------------
void StudentNode::setGPA(float gpa)
{
   GPA = gpa;
}

//---------------------------------------------
StudentNode* StudentNode::setNext(StudentNode *next)
{
    Next = next;
}

//----------------------------------------------
void StudentNode::print() const
{
   cout << "Name: " << Name << "\n"
      << "Address: " << Address << "\n" << "GPA: " << GPA << "\n";
   if (Next != NULL)
      Next->print();
}
