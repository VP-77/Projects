#pragma once
#include "userNode.h"
#include <iostream>
using namespace std;

class userList
{
public:

    //New Nodes
    userList();
    userList(const userList & list);
    ~userList();
    
    //Methods
    void add(string firstName, string lastName, string userHandle, string phoneNumber, int messageCount);
    void update(string userHandle);
    void find();
        
    //print method
    void print();

private:

	userNode *Head;
	int numOfUsers = 0;
	int groupMessages = 0;
};

