/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   main.cpp
  * Author: riley
  *
  * Created on February 19, 2020, 1:02 PM
  */

#include "Dictionary.h"
using namespace std;

int main()
{
	Dictionary words;
	string file = "";

	cout << "File to read in: ";
	cin >> file;
	words.readFile(file);

	return 0;
}