#include"DataManagement.h"
#include <time.h>
#include"Menu.h"
#include<algorithm>

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
				vector <Company>temp = companies;
				sortedCompanies = quickSort(companies, 0, size - 1);
				companies = temp;
			}
			else if (option == 10) {
				vector <Company>temp = companies;
				sortedCompanies = heapSort(companies, size - 1);
				companies = temp;
			}
			else if (option == 11) {
				vector <Company>temp = companies;
				sortedCompanies = countingSortWithIndex(companies);
				companies = temp;
			}
			else if (option == 12) {
				vector <Company>temp = companies;
				sortedCompanies = countingSort(companies);
				companies = temp;
			}
			else if (option == 13) {
				vector <Company>temp = companies;
				//	sortedCompanies = countingSort(companies);   Radix Sort
				companies = temp;
			}
			else if (option == 14) {
				vector <Company>temp = companies;
				//	sortedCompanies = countingSort(companies);  Bucket Sort
				companies = temp;
			}
			else if (option == 15) {
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
		clearScreen();
	}
}

