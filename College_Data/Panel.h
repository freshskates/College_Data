#pragma once
#include "Data.h"
#include <algorithm>
#include <numeric>

class Panel {
public:

	Data& temp;

	Panel(Data& storage) :temp(storage) {}

	vector<HeaderData> display;

	vector<string> options = { "distinct", "reversed", "noun", "verb", "adverb", "adjective", "pronoun", "preposition", "conjunction", "interjection" };

	void help();

	void start();

	void option(string& check);

	void print();

	void sort_list();

	void removedup();

	void filter(string& pos);

	void reverse_list();
};