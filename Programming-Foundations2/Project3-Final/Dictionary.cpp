/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Dictionary.cpp
  * Author: riley
  *
  * Created on February 19, 2020, 1:05 PM
  */

#include "Dictionary.h"

Dictionary::Dictionary()
{
	// Initialize word array
	count = 0;
	for (int i = 0; i < NUM_WORDS; i++)
		words[i] = "";
}

Dictionary::~Dictionary()
{

}

void Dictionary::readFile(string filename)
{
	string str, fileName;
	fileName = filename;
	ifstream infile;
	int rank = 0;
	float val = 0;
	float temp = 0;
	float temp2 = 0;
	int wordCount = 0;
	int index = 0;

	infile.open("words.txt");
	if (infile.fail())
	{
		cout << "Cannot open file.";
		return;
	}
	infile >> rank >> str;
	words[index] = str;
	ranks[index] = rank;
	while (!infile.eof() && index < NUM_WORDS)
	{
		infile >> rank >> str;
		{
			words[index] = str;
			ranks[index] = rank;
			index++;
		}
	}
	infile.close();
	cout << "Words read in." << endl;
	
	str = "";
	wordCount = 1;
	infile.open(fileName.c_str());
	if (infile.fail())
	{
		cout << "Cannot open file.";
	}

	infile >> str;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if ((str[i] < 65 || str[i] > 122) && (str[i] != 39))
		{
			str.erase(str.begin() + i);
		}
		str[i] = tolower(str[i]);
	}
	while (!infile.eof())
	{
		for (int i = 0; i < (int)str.length(); i++)
		{
			if (str[i] < 65 || str[i] > 122)
			{
				str.erase(str.begin() + i);
			}
			str[i] = tolower(str[i]);
		}
		val = compareWords(str, 0, 999);
		temp2 = findRank(val);
		wordCount++;
		temp = temp + temp2;
		infile >> str;
	}
	infile.close();
	cout << "File read successfully.\n";
	float total = temp / wordCount;
	cout << "Reading difficulty of " << fileName << " is: " << total << ".\n";
}

int Dictionary::compareWords(string word, int low, int high)
{
	// Calculate midpoint index
	int mid = (low + high) / 2;

	// Check termination conditions
	if (low > high)
		return -1;
	else if (words[mid] == word)
		return mid;

	// Handle recursive cases
	else if (words[mid] > word)
		return compareWords(word, low, mid - 1);
	else
		return compareWords(word, mid + 1, high);
}

int Dictionary::findRank(int num)
{
	int rank = ranks[num];
	if (rank == 0)
		rank = 1001;
	return rank;
}