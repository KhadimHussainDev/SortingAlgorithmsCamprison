#include <time.h>
#include"Menu.h"
#include<algorithm>
#include"CompanyDL.h"
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
			companies = CompanyDL::loadData(fileName100);
		}
		else if (option == 2) {
			companies = CompanyDL::loadData(fileName1000);
		}
		else if (option == 3) {
			companies = CompanyDL::loadData(fileName10000);
		}
		else if (option == 4) {
			companies = CompanyDL::loadData(fileName100000);
		}
		else if (option == 5) {
			companies = CompanyDL::loadData(fileName500000);
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
		clearScreen();
		int size = companies.size();
		vector<Company>sortedCompanies;
		while (true) {
			int option = sortingMenu();
			clock_t start, end;
			start = clock();
			if (option == 1) {
				sortedCompanies = CompanyDL::bubbleSortWithIndex(companies, size);
			}
			else if (option == 2) {
				sortedCompanies = CompanyDL::bubbleSortWithEmployees(companies, size);
			}
			else if (option == 3) {
				sortedCompanies = CompanyDL::selectionSortWithIndex(companies, size);
			}
			else if (option == 4) {
				sortedCompanies = CompanyDL::selectionSortWithEmployees(companies, size);

			}
			else if (option == 5) {
				sortedCompanies = CompanyDL::insertionSortWithIndex(companies, size);
			}
			else if (option == 6) {
				sortedCompanies = CompanyDL::insertionSortWithEmployees(companies, size);
			}
			else if (option == 7) {

				sortedCompanies = CompanyDL::mergeSortWithIndex(companies, 0, size - 1);

			}
			else if (option == 8) {

				sortedCompanies = CompanyDL::mergeSortWithEmployees(companies, 0, size - 1);

			}
			else if (option == 9) {

				sortedCompanies = CompanyDL::quickSortWithIndex(companies, 0, size - 1);

			}
			else if (option == 10) {

				sortedCompanies = CompanyDL::quickSortWithEmployees(companies, 0, size - 1);

			}
			else if (option == 11) {

				sortedCompanies = CompanyDL::heapSortWithIndex(companies, size - 1);

			}
			else if (option == 12) {

				sortedCompanies = CompanyDL::heapSortWithEmployees(companies, size - 1);

			}
			else if (option == 13) {

				sortedCompanies = CompanyDL::countingSortWithIndex(companies);

			}
			else if (option == 14) {

				sortedCompanies = CompanyDL::countingSortWithEmployees(companies);

			}
			else if (option == 15) {

				sortedCompanies = CompanyDL::radixSortWithIndex(companies);

			}
			else if (option == 16) {

				sortedCompanies = CompanyDL::radixSortWithEmployees(companies);

			}
			else if (option == 17) {
				sortedCompanies = CompanyDL::bucketSortWithIndex(companies, 5000000);
			}
			else if (option == 18) {
				sortedCompanies = CompanyDL::bucketSortWithEmployyees(companies, 10000);
			}
			else if (option == 19) {
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
			CompanyDL::saveData(sortedCompanies);
			cout << "Sorting Done....And Data has been saved." << endl;
			clearScreen();
		}
		clearScreen();
	}
}