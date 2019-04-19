/*
	In SoftUni you can study Java C# PHP and JavaScript JAVA and c# developers graduate in 2-3 years Go in

	2-3, and, c#, can, go, in, java, php, you
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void print_short_words(string text)
{
	set<string>  words;
	string current_word = "";
	for (int symbol = 0; symbol < text.size(); symbol++)  //crawls all text
	{
		if (text[symbol] != ' ')
		{
			text[symbol] = tolower(text[symbol]);   //make all symbols in text lower
			current_word += text[symbol];           //make string with current word
		}
		else
		{
			words.insert(current_word);  //if symbol is ' ' insert in the set "words" current word
			current_word = "";           // empty the string for the next word
		}
	}
	words.insert(current_word);  //this is for the last one word


	string short_words = "";
	for(auto short_word_pos = words.begin(); short_word_pos != words.end(); short_word_pos++)
	{	
		string word = *short_word_pos;
		if (word.size() < 5)               //crawls all set and push all words that have less than 5 letters
		{								   //in string "short_words" with comma and spase 
			short_words += word + ", ";
		}
	}

	for (int letter = 0; letter < short_words.size() - 2; letter++)
	{
		cout << short_words[letter];   //print all string "short_words" without last comma and space
	}
	cout << endl;
}

int main()
{
	string text;
	getline(cin, text); //read text from the console
	cout << endl;

	print_short_words(text);
	return 0;
}

