#include "tree.h"

int main()
{
    cout << "When you would like to exit the program, please type 'QUIT' as your name to search!\n";
    
    // Create tree
    BinaryTree Tree;
    string name = "";

    Tree.ReadData();
   
    while (name != "QUIT")
    {
        cout << "Please enter a name to search for: ";
        cin >> name;
      
        if (name == "QUIT")
        {
            Tree.Print();
            cout << "Exiting.\n";
            return 0;
        }
      
        if (Tree.Search(name))
        {
	   cout << name << " found\n";
        }
        else
            cout << name << " not found\n";
      
   }
}
