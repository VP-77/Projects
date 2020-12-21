/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Dictionary.h
  * Author: riley
  *
  * Created on February 19, 2020, 1:05 PM
  */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#endif /* DICTIONARY_H */

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int NUM_WORDS = 1000;

class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	void readFile(string filename);
	int compareWords(string value, int low, int high);
	int findRank(int num);

private:
	int count;
	string words[NUM_WORDS];
	int ranks[NUM_WORDS];
};