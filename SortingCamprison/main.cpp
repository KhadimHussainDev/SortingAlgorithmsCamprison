#include <time.h>
#include"Menu.h"
#include<algorithm>
#include"CompanyDL.h"
int main()
{
CompanyDL company;
string fileName100 = "organizations-100.csv";
string fileName1000 = "organizations-1000.csv";
string fileName10000 = "organizations-10000.csv";
string fileName100000 = "organizations-100000.csv";
string fileName500000 = "organizations-500000.csv";
while (true) {
	int option = UI::loadDataMenu();
	if (option == 1) {
		company.companies = CompanyDL::loadData(fileName100);
	}
	else if (option == 2) {
		company.companies = CompanyDL::loadData(fileName1000);
	}
	else if (option == 3) {
		company.companies = CompanyDL::loadData(fileName10000);
	}
	else if (option == 4) {
		company.companies = CompanyDL::loadData(fileName100000);
	}
	else if (option == 5) {
		company.companies = CompanyDL::loadData(fileName500000);
	}
	else if (option == 6) {
		break;
	}
	else {
		cout << "Invalid Option." << endl;
		cout << "Try Again" << endl;
		continue;
	}

	cout << "Data Loaded...." << endl;
	UI::clearScreen();
	int size = company.companies.size();
	vector<Company>sortedcompany;
	while (true) {
		int option = UI::sortingMenu();
		clock_t start, end;
		start = clock();
		if (option == 1) {
			sortedcompany = CompanyDL::bubbleSortWithIndex(company.companies, size);
		}
		else if (option == 2) {
			sortedcompany = CompanyDL::bubbleSortWithEmployees(company.companies, size);
		}
		else if (option == 3) {
			sortedcompany = CompanyDL::selectionSortWithIndex(company.companies, size);
		}
		else if (option == 4) {
			sortedcompany = CompanyDL::selectionSortWithEmployees(company.companies, size);

		}
		else if (option == 5) {
			sortedcompany = CompanyDL::insertionSortWithIndex(company.companies, size);
		}
		else if (option == 6) {
			sortedcompany = CompanyDL::insertionSortWithEmployees(company.companies, size);
		}
		else if (option == 7) {

			sortedcompany = CompanyDL::mergeSortWithIndex(company.companies, 0, size - 1);

		}
		else if (option == 8) {

			sortedcompany = CompanyDL::mergeSortWithEmployees(company.companies, 0, size - 1);

		}
		else if (option == 9) {

			sortedcompany = CompanyDL::quickSortWithIndex(company.companies, 0, size - 1);

		}
		else if (option == 10) {

			sortedcompany = CompanyDL::quickSortWithEmployees(company.companies, 0, size - 1);

		}
		else if (option == 11) {

			sortedcompany = CompanyDL::heapSortWithIndex(company.companies, size - 1);

		}
		else if (option == 12) {

			sortedcompany = CompanyDL::heapSortWithEmployees(company.companies, size - 1);

		}
		else if (option == 13) {

			sortedcompany = CompanyDL::countingSortWithIndex(company.companies);

		}
		else if (option == 14) {

			sortedcompany = CompanyDL::countingSortWithEmployees(company.companies);

		}
		else if (option == 15) {

			sortedcompany = CompanyDL::radixSortWithIndex(company.companies);

		}
		else if (option == 16) {

			sortedcompany = CompanyDL::radixSortWithEmployees(company.companies);

		}
		else if (option == 17) {
			sortedcompany = CompanyDL::bucketSortWithIndex(company.companies, 5000000);
		}
		else if (option == 18) {
			sortedcompany = CompanyDL::bucketSortWithEmployyees(company.companies, 10000);
		}
		else if (option == 19) {
			break;
		}
		else {
			cout << "Invalid Option." << endl;
			cout << "Try Again" << endl;
			UI::clearScreen();
			continue;
		}
		end = clock();
		double time = double(end - start) / double(CLOCKS_PER_SEC);
		cout << time << " sec Taken." << endl;
		CompanyDL::saveData(sortedcompany);
		cout << "Sorting Done....And Data has been saved." << endl;
		UI::clearScreen();
	}
	UI::clearScreen();
}
}