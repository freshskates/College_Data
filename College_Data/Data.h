#pragma once
#include <map>
#include <string>
#include <fstream>
#include <vector>
/**
  * Thought process
  * <storage> string string string 
  * school name, <storage> 
  * School Name, School Type, Starting Median Salary, Mid - Career Median Salary, Mid - Career 10th Percentile Salary, Mid - Career 25th Percentile Salary, Mid - Career 75th Percentile Salary, Mid - Career 90th Percentile Salary
  * Massachusetts Institute of Technology(MIT), Engineering, "$72,200.00", "$126,000.00", "$76,800.00", "$99,200.00", "$168,000.00", "$220,000.00"
  */
using namespace std; 
class HeaderData {
public: 
	string school_name;
	string school_type;
	string starting_mean;
	string career_median;
	string career_percentile_10;
	string career_percentile_25;
	string career_percentile_75;
	string career_percentile_90;
};

class Data {
public:
	map<string, Data> mapped_data;

	int definitions = 0;

	Data() {};

	Data(string& file) : file(file) {}

	void read();

	static vector<string> split(string& s, string&& delimiter, bool&& grab_word = false);

private:
	string file;
	
	string trim(string& s, bool&& flag);

	void map_words(string& line);
};