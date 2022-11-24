#include "DataManagement.h"
#include <fstream>
#include <string>
void saveData(vector<Company>vec) {
	ofstream myFile("SortedData.csv");
	for (auto x : vec) {
		myFile << x.index << "," << x.id << "," << x.name << "," << x.website << "," << x.country << "," << x.description << "," << x.foundedYear << ",";
		myFile << x.industry << "," << x.noOfEmplployees << endl;
	}
	myFile.flush();
	myFile.close();
}
vector<Company> loadData(string fileName) {
	vector<Company>companies;
	fstream myFile(fileName);
	string line;
	int index, noOfEmployees, foundedYear;
	string id, name, website, country, description, industry;
	getline(myFile, line);
	while (getline(myFile, line)) {
		index = stoi(parse(line, 0));
		id = parse(line, 1);
		name = parse(line, 2);
		website = parse(line, 3);
		country = parse(line, 4);
		description = parse(line, 5);
		foundedYear = stoi(parse(line, 6));
		industry = parse(line, 7);
		noOfEmployees = stoi(parse(line, 8));
		Company company = Company(index, id, name, website, country, description, foundedYear, industry, noOfEmployees);
		companies.push_back(company);
	}
	return companies;
}
string parse(string line, int index)
{
	int count = 0;
	string word;
	bool flag = true;
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '"') {
			flag = !flag;
		}
		if (line[i] == ',' && flag)
		{
			count++;
		}
		else if (count == index)
		{
			word += line[i];
		}
	}
	return word;
}

