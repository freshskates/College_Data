#include "Data.h"
#include <iostream>
void Data::read() {
	string line;
	ifstream fin;
	fin.open(this->file.c_str());
	while (getline(fin, line)) 
		map_words(line);
		//cout << line << endl;
	fin.close();
}

vector<string> Data::split(string& s, string&& delimiter, bool&& grab_word) {
	vector<string> list;
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		list.emplace_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
		if (grab_word) break;
	}
	list.emplace_back(s);
	return list;
}

string Data::trim(string& s, bool&& flag)
{
	size_t pos = flag ? s.find_first_not_of(" ") : s.find_last_not_of(" ");
	if (flag)
		return pos == string::npos ? "" : s.substr(pos);
	return pos == string::npos ? "" : s.substr(0, pos + 1);
}

void Data::map_words(string& line) {
	//string word{ split(line, ",", true)[0] };
	vector<string> definition = split(line, ",");

	//HeaderData word_info(definition.size());
	for (int i = 0; i < definition.size(); i++) {
		//if (temp.size() != 2) continue;
		//word_info.list.emplace_back(trim(temp[0], false), trim(temp[1], true));
		cout << definition[i] << " | ";
		//temp.clear(), definitions++;
	}
	
	cout << endl << definition.size() << endl;
	//mapped_words.insert({ word, word_info });
}
