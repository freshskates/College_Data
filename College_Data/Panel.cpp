#include <iostream>
using namespace std; 
#include "Panel.h"


void Panel::create_display() {
	for (auto& [key, val] : temp.mapped_data)
		display.emplace_back(val);
}

Panel::Panel(Data& storage) :temp(storage) {
	create_display();
	sort(display.begin(), display.end(), [](HeaderData& a, HeaderData& b) -> bool {return a.school_name < b.school_name; });
	for (auto& x : display)
		cout << x.school_name << endl; 
}

void Panel::help() {
	cout << "Schools: " << temp.mapped_data.size() << "\nSchools: " << temp.schools - 1 << endl;
	cout << "Menu" << endl;
	cout << "<school> || <school_type> <ASC or DESC>" << endl;
	cout << "Enter Statement: ";
}

void Panel::start() {
	while (true) {
		help();
		string line;
		getline(cin, line);
		//vector<string> user_input = Data::split(line, " ");
		//if (!line.size() || line.size() > 4 || line == "!q")
			//break;
		/*if (!user_input.size() || user_input.size() > 4 || user_input[0] == "!q")
			break;*/
		if (temp.mapped_data.count(line)) {
			temp.print(temp.mapped_data.at(line));
			//sort_list();
			//for (int i = 1; i < user_input.size(); i++) option(user_input[i]);
			//print();     
		}
	}
}

void Panel::option(string& check) {
	if (check == options[0]) removedup();
	else if (check == options[1]) reverse_list();
	for (int i = 2; i < options.size(); i++) if (check == options[i]) filter(options[i]);
}

void Panel::print() {
	cout << endl;
	//for_each(display.begin(), display.end(), [](HeaderData& a) -> void { cout << "[" << a.school_type << "] " << a.meaning << endl; });
	cout << endl;
}
void Panel::sort_list() {
	//sort(display.begin(), display.end(), [](HeaderData& a, HeaderData& b) -> bool {return a.meaning < b.meaning; });
}
void Panel::removedup() {
	//display.erase(unique(display.begin(), display.end(), [](HeaderData& a, HeaderData& b) -> bool { return a.meaning == b.meaning; }), display.end());
}
void Panel::filter(string& pos) {
	//display.erase(remove_if(display.begin(), display.end(), [&pos](HeaderData& a) -> bool { return a.POS != pos; }), display.end());
}
void Panel::reverse_list() {
	reverse(display.begin(), display.end());
}

