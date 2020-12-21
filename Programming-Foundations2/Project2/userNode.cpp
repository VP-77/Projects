#include "userNode.h"

//---------------------------
userNode::userNode()
{
	Next = NULL;
	FirstName = "";
	LastName = "";
	UserHandle = "";
	UserPhoneNumber = "";
	UserMessageCount = 0;
}

//---------------------------
userNode::userNode(string firstName, string lastName, string userHandle, string phoneNumber, int messageCount)
{
	Next = NULL;
	FirstName = firstName;
	LastName = lastName;
	UserHandle = userHandle;
	UserPhoneNumber = phoneNumber;
	UserMessageCount = messageCount;
}

//--------------------------
userNode::userNode(const userNode& user)
{
	FirstName = user.FirstName;
	LastName = user.LastName;
	UserHandle = user.UserHandle;
	UserPhoneNumber = user.UserPhoneNumber;
	UserMessageCount = user.UserMessageCount;
}

//---------------------------
userNode::~userNode()
{
	
}

//---------------------------
void userNode::setFirstName(string firstName)
{
	FirstName = firstName;
}

//---------------------------
void userNode::setLastName(string lastName)
{
	LastName = lastName;
}

//---------------------------
void userNode::setUserHandle(string userHandle)
{
	UserHandle = userHandle;
}

//---------------------------
void userNode::setUserPhoneNumber(string phoneNumber)
{
	UserPhoneNumber = phoneNumber;
}

//---------------------------
void userNode::setUserMessageCount(int messageCount)
{
	UserMessageCount = messageCount;
}

//--------------------------
void userNode::setNext(userNode *next)
{
    Next = next;
}

//---------------------------
string userNode::getFirstName() const
{
	return FirstName;
}

//---------------------------
string userNode::getLastName() const
{
	return LastName;
}

//---------------------------
string userNode::getUserHandle() const
{
	return UserHandle;
}

//---------------------------
string userNode::getUserPhoneNumber() const
{
	return UserPhoneNumber;
}

//---------------------------
int userNode::getUserMessageCount() const
{
	return UserMessageCount;
}

//--------------------------
userNode *userNode::getNext() const
{
    return Next;
}

//---------------------------
void userNode::printNode() const
{
    cout << "Name: " << FirstName << " " << LastName << "\n"
      << "User: " << UserHandle << "\n" << "Phone Number: " << UserPhoneNumber << "\n"
      << "Message Count: " << UserMessageCount << "\n\n";
}