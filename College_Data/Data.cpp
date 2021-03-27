#include "Data.h"
#include <iostream>

void Data::read() {
	string line;
	ifstream fin;
	fin.open(this->file.c_str());
	while (getline(fin, line)) {
		schools++;
		map_words(line);
	}
	fin.close();
}

static void cleanup(string& line) {
	bool check = false;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '\"') line.erase(i, 1), check = !check;
		if (line[i] == ',' && check) line.erase(i, 1);
	}
}

vector<string> Data::split(string& s, string&& delimiter, bool&& grab_word) {
	cleanup(s);
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

void Data::map_words(string& line) {
	vector<string> definition = split(line, ",");
	if (definition.size() != 8 || schools == 1) return;
	mapped_data.insert({ definition[0], {definition[0], definition[1], definition[2], definition[3], definition[4], definition[5], definition[6], definition[7]} });
}

void Data::print(HeaderData& val) {
	cout << "School Name: " << val.school_name << endl;
	cout << "School Type: " << val.school_type << endl;
	cout << "Starting Median Salary: " << val.starting_mean << endl;
	cout << "Career Median Salary: " << val.career_median << endl;
	cout << "Career 10th Percentile Salary: " << val.career_percentile_10 << endl;
	cout << "Career 25th Percentile Salary: " << val.career_percentile_25 << endl;
	cout << "Career 75th Percentile Salary: " << val.career_percentile_75 << endl;
	cout << "Career 90th Percentile Salary: " << val.career_percentile_90 << endl;
	cout << "--------------------------------------------- " << endl << endl;
}

void Data::all() {
	for (auto& [key, val] : this->mapped_data)
		print(val);
}
