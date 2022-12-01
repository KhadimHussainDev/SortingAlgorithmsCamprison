#include "Menu.h"
void UI:: clearScreen() {
	system("pause");
	system("cls");
}
int UI::sortingMenu() {
	int option;
	cout << "1.Bubbles Sort with Index" << endl;
	cout << "2.Bubbles Sort with No of Employee" << endl;
	cout << "3.Selection Sort with Index" << endl;
	cout << "4.Selection Sort with No of Employee" << endl;
	cout << "5.Insertion Sort with Index" << endl;
	cout << "6.Insertion Sort with No of Employee" << endl;
	cout << "7.Merge Sort with Index" << endl;
	cout << "8.Merge Sort with No of Employee" << endl;
	cout << "9.Quick Sort with No of Index" << endl;
	cout << "10.Quick Sort with No of Employee" << endl;
	cout << "11.Heap Sort with No of Index" << endl;
	cout << "12.Heap Sort with No of Employee" << endl;
	cout << "13.Countinng Sort with Index" << endl;
	cout << "14.Countinng Sort with No of Employee" << endl;
	cout << "15.Radix Sort with No of Index" << endl;
	cout << "16.Radix Sort with No of Employee" << endl;
	cout << "17.Bucket Sort with No of Index" << endl;
	cout << "18.Bucket Sort with No of Employee" << endl;
	cout << "19.Exit" << endl;

	cout << "Your Option : ";
	cin >> option;
	return option;
}
int UI::loadDataMenu() {
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