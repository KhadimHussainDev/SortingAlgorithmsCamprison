#include "Company.h"
Company::Company(int index, string id, string name, string website, string country, string description, int foundedYear, string industry, int noOfEmployees) {
	this->index = index;
	this->id = id;
	this->name = name;
	this->website = website;
	this->country = country;
	this->description = description;
	this->foundedYear = foundedYear;
	this->industry = industry;
	this->noOfEmplployees = noOfEmployees;
}