#include "Data.h"

using namespace std; 
int main()
{
	//string file = "salaries-by-college-type.csv";
	string file = "test.csv";
	Data data(file); 
	data.read();
}
