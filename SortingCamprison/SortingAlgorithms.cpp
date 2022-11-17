#include"SortingAlgorithms.h"
#include <algorithm>
vector<Company> bubbleSort(vector<Company>arr, int n)
{
	for (int x = 0; x < n - 1; x++)
	{
		bool isSwapped = false;
		for (int y = 0; y < n - x - 1; y++)
		{
			if (arr[y].noOfEmplployees > arr[y + 1].noOfEmplployees)
			{
				swap(arr[y], arr[y + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped)
		{
			break;
		}
	}
	return arr;
}
vector<Company> bubbleSortWithIndex(vector<Company>arr, int n)
{
	for (int x = 0; x < n - 1; x++)
	{
		bool isSwapped = false;
		for (int y = 0; y < n - x - 1; y++)
		{
			if (arr[y].index > arr[y + 1].index)
			{
				swap(arr[y], arr[y + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped)
		{
			break;
		}
	}
	return arr;
}
int findMinimum(vector<Company>arr, int start, int end)
{
	int min = arr[start].noOfEmplployees;
	int minIndex = start;
	for (int x = start; x < end; x++)
	{
		if (min > arr[x].noOfEmplployees)
		{
			min = arr[x].noOfEmplployees;
			minIndex = x;
		}
	}
	return minIndex;
}
int findMinimumIndex(vector<Company> arr, int start, int end)
{
	int min = arr[start].index;
	int minIndex = start;
	for (int x = start; x < end; x++)
	{
		if (min > arr[x].index)
		{
			min = arr[x].index;
			minIndex = x;
		}
	}
	return minIndex;
}
vector<Company> selectionSort(vector<Company>arr, int n) {
	for (int x = 0; x < n - 1; x++)
	{
		int minIndex = findMinimum(arr, x, n);
		swap(arr[x], arr[minIndex]);
	}
	return arr;
}
vector<Company> selectionSortWithIndex(vector<Company>arr, int n) {
	for (int x = 0; x < n - 1; x++)
	{
		int minIndex = findMinimumIndex(arr, x, n);
		swap(arr[x], arr[minIndex]);
	}
	return arr;
}
vector<Company> insertionSort(vector<Company>arr, int n)
{
	for (int x = 1; x < n; x++)
	{
		int key = arr[x].noOfEmplployees;
		int y = x - 1;
		while (y >= 0 && arr[y].noOfEmplployees > key)
		{
			arr[y + 1] = arr[y];
			y--;
		}
		arr[y + 1].noOfEmplployees = key;
	}
	return arr;
}
vector<Company> insertionSortWithIndex(vector<Company>arr, int n)
{
	for (int x = 1; x < n; x++)
	{
		int key = arr[x].index;
		int y = x - 1;
		while (y >= 0 && arr[y].index > key)
		{
			arr[y + 1] = arr[y];
			y--;
		}
		arr[y + 1].index = key;
	}
	return arr;
}
vector<Company> mergeSortWithIndex(vector<Company>& arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSortWithIndex(arr, start, mid);
		mergeSortWithIndex(arr, mid + 1, end);
		mergeWithIndex(arr, start, mid, end);
	}
	//sort(arr.begin(), arr.end(),compare);
	return arr;
}
bool compare(Company a, Company b) {
	return a.index < b.index;
}
void mergeWithIndex(vector<Company>& arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	queue<Company> tempArr;
	while (i <= mid && j <= end) {
		if (arr[i].index < arr[j].index)
		{
			tempArr.push(arr[i]);
			i++;
		}
		else
		{
			tempArr.push(arr[j]);
			j++;
		}
	}
	while (i <= mid) {
		tempArr.push(arr[i]);
		i++;
	}
	while (j <= end) {
		tempArr.push(arr[j]);
		j++;
	}
	for (int x = start; x <= end; x++) {
		arr[x] = tempArr.front();
		tempArr.pop();
	}
}
vector<Company> mergeSort(vector<Company>& arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
	return arr;
}
void merge(vector<Company>& arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	queue<Company> tempArr;
	while (i <= mid && j <= end) {
		if (arr[i].noOfEmplployees < arr[j].noOfEmplployees)
		{
			tempArr.push(arr[i]);
			i++;
		}
		else
		{
			tempArr.push(arr[j]);
			j++;
		}
	}
	while (i <= mid) {
		tempArr.push(arr[i]);
		i++;
	}
	while (j <= end) {
		tempArr.push(arr[j]);
		j++;
	}
	for (int x = start; x <= end; x++) {
		arr[x] = tempArr.front();
		tempArr.pop();
	}
}
