/* 
 * File:   main.cpp
 * Author: Riley Nadwodny
 * Created on February 12, 2020, 11:50 AM
 */

#include "userList.h"
using namespace std;

int main()
{
    string user, firstName, lastName, userName, phoneNumber;
    int messageCount;
    userList list;
    char command;
    
    cout << "Welcome to the GroupMe user list!\n";
    
    while (command != 'e')
    {
        cout << "Please select a command:\n"
                << "    a - Add user\n"
                << "    b - Update user message count\n"
                << "    c - Find user with the largest message count\n"
                << "    d - Print user list\n"
                << "    e - Exit program\n";
        
        cout << "Please select your command now: ";
        cin >> command;
        
        if (command == 'a')
        {
            cout << "First name: ";
            cin >> firstName;
            cout << "Last name: ";
            cin >> lastName;
            cout << "Username: ";
            cin >> userName;
            cout << "Phone number: ";
            cin >> phoneNumber;
            cout << "User message count: ";
            cin >> messageCount;
            list.add(firstName, lastName, userName, phoneNumber, messageCount);
        }
        else if (command == 'b')
        {
            cout << "Username to update: ";
            cin >> user;
            list.update(user);
        }
        else if (command == 'c')
        {
            list.find();
        }
        else if (command == 'd')
        {
            list.print();
        }
        else if (command == 'e')
        {
            cout << "Thank you for using this program! Exiting program now.";
            return 0;
        }
    }
}




