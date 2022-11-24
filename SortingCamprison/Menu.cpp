#include "Menu.h"
void clearScreen() {
	system("pause");
	system("cls");
}
int sortingMenu() {
	int option;
	cout << "1.Bubbles Sort with Index" << endl;
	cout << "2.Bubbles Sort with No of Employee" << endl;
	cout << "3.Selection Sort with Index" << endl;
	cout << "4.Selection Sort with No of Employee" << endl;
	cout << "5.Insertion Sort with Index" << endl;
	cout << "6.Insertion Sort with No of Employee" << endl;
	cout << "7.Merge Sort with Index" << endl;
	cout << "8.Merge Sort with No of Employee" << endl;
	cout << "9.Quick Sort with No of Employee" << endl;
	cout << "10.Heap Sort with No of Employee" << endl;
	cout << "11.Countinng Sort with Index" << endl;
	cout << "12.Countinng Sort with No of Employee" << endl;
	cout << "13.Radix Sort with No of Employee" << endl;
	cout << "14.Bucket Sort with No of Employee" << endl;
	cout << "15.Exit" << endl;

	cout << "Your Option : ";
	cin >> option;
	return option;
}
int loadDataMenu() {
	int option;
	cout << "1.Load 100 Records" << endl;
	cout << "2.Load 1000 Records" << endl;
	cout << "3.Load 10000 Records" << endl;
	cout << "4.Load 100000 Records" << endl;
	cout << "5.Load 500000 Records" << endl;
	cout << "6.Exit" << endl;

	cout << "Your Option : ";
	cin >> option;
	return option;
}