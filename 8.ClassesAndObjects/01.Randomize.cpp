/*	
	Welcome to SoftUni and have fun learning programming

	Output:
	learning
	Welcome
	SoftUni
	and
	fun
	programming
	have
	to
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class random_words //create class "random_words"
{
private:
	vector<string> all_words; //create field with vector "all_words" who contains words from the sentence

public:
	random_words(vector<string> words) //make constructor
	{
		this->all_words = words;
	}

	void getRandomized() //make method "getRandomized" which return all words from the vector mixed 
	{
		random_shuffle(all_words.begin(), all_words.end()); //mix the vector

		for (string word : all_words) //return words from the vector
		{
			cout << word << endl;
		}
		cout << endl;
	}
};

int main()
{
	string line;
	getline(cin, line); //read from  the console sentence
	cout << endl;

	vector<string> words; 
	string current_word = "";
	for (int symbol = 0; symbol < line.size(); symbol++) //crawn all sentence
	{
		if (line[symbol] == ' ') //if symbol is ' ' push in vector "words" with string "current_word"
		{
			words.push_back(current_word); 
			current_word = ""; //empty string "current_word" for the next word
			symbol++;
		}
		current_word += line[symbol]; //if symbol is not ' ' fill string "current_word" with current symbol
	}
	words.push_back(current_word); //this is for the last word

	random_words w(words); //create object "w" in class "random_words"
	w.getRandomized(); 
    return 0;
}

