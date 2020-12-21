#pragma once
#include <iostream>
using namespace std;

class userNode
{

public:
	userNode();
	userNode(string firstName, string lastName, string userHandle, string phoneNumber, int messageCount);
	userNode(const userNode& user);
	~userNode();

	//setters
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setUserHandle(string userHandle);
	void setUserPhoneNumber(string phoneNumber);
	void setUserMessageCount(int messageCount);
	void setNext(userNode* next);

	//getters
	string getFirstName() const;
	string getLastName() const;
	string getUserHandle() const;
	string getUserPhoneNumber() const;
	int getUserMessageCount() const;
	userNode* getNext() const;

	//print
	void printNode() const;

private:
	userNode* Next;
	string FirstName = "";
	string LastName = "";
	string UserHandle = "";
	string UserPhoneNumber = "";
	int UserMessageCount = 0;
};

