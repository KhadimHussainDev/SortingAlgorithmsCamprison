#pragma once
#include <iostream>
using namespace std;
class Company {
public:
	int index;
	string id;
	string name;
	string website;
	string country;
	string description;
	int foundedYear;
	string industry;
	int noOfEmplployees;
	Company(int index, string id, string name, string website, string country, string description, int foundedYear, string industry, int noOfEmployees);

};