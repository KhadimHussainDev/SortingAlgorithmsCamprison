#include"SortingAlgorithms.h"
#include<fstream>
#include<string>
#include <time.h>
#include"Menu.h"
using namespace std;
											//Function Declarations
string parse(string line, int index);
vector<Company> loadData(string fileName);
void saveData(vector<Company>vec);
											//Function Implementations
int main()
{
	vector<Company>companies;
	string fileName100 = "organizations-100.csv";
	string fileName1000 = "organizations-1000.csv";
	string fileName10000 = "organizations-10000.csv";
	string fileName100000 = "organizations-100000.csv";
	string fileName500000 = "organizations-500000.csv";

	while (true) {
		int option = loadDataMenu();
		if (option == 1) {
			companies = loadData(fileName100);
		}
		else if (option == 2) {
			companies = loadData(fileName1000);
		}
		else if (option == 3) {
			companies = loadData(fileName10000);
		}
		else if (option == 4) {
			companies = loadData(fileName100000);
		}
		else if (option == 5) {
			companies = loadData(fileName500000);
		}
		else if (option == 6) {
			break;
		}
		else {
			cout << "Invalid Option." << endl;
			cout << "Try Again" << endl;
			continue;
		}
		break;
	}
	cout << "Data Loaded...." << endl;
	clearScreen();
	int size = companies.size();
	vector<Company>sortedCompanies;
	while (true) {
		int option = sortingMenu();
		clock_t start, end;
		start = clock();
		if (option == 1) {
			sortedCompanies = bubbleSortWithIndex(companies, size);
		}
		else if (option == 2) {
			sortedCompanies = bubbleSort(companies, size);
		}
		else if (option == 3) {
			sortedCompanies = selectionSortWithIndex(companies, size);
		}
		else if (option == 4) {
			sortedCompanies = selectionSort(companies, size);

		}
		else if (option == 5) {
			sortedCompanies = insertionSortWithIndex(companies, size);
		}
		else if (option == 6) {
			sortedCompanies = insertionSort(companies, size);
		}
		else if (option == 7) {
			vector <Company>temp = companies;
			sortedCompanies = mergeSortWithIndex(companies, 0, size - 1);
			companies = temp;
		}
		else if (option == 8) {
			vector <Company>temp = companies;
			sortedCompanies = mergeSort(companies, 0, size - 1);
			companies = temp;
		}
		else if (option == 9) {
			break;
		}
		else {
			cout << "Invalid Option." << endl;
			cout << "Try Again" << endl;
			clearScreen();
			continue;
		}
		end = clock();
		double time = double(end - start) / double(CLOCKS_PER_SEC);
		cout << time << " sec Taken." << endl;
		saveData(sortedCompanies);
		cout << "Sorting Done....And Data has been saved." << endl;
		clearScreen();
	}
}
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