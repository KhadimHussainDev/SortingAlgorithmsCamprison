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


vector<Company> quickSort(vector<Company>& arr, int start, int end)
{
	if (start < end)
	{
		int pivot = start;
		int mid = partition(arr, start + 1, end, pivot);
		quickSort(arr, start, mid - 1);
		quickSort(arr, mid + 1, end);
	}
	return arr;
}
int partition(vector<Company>& arr, int start, int end, int pivot)
{
	int left = start;
	int right = end;
	while (left <= right)
	{
		while (left <= end && arr[left].noOfEmplployees < arr[pivot].noOfEmplployees)
			left++;
		while (right >= start && arr[right].noOfEmplployees >= arr[pivot].noOfEmplployees)
			right--;
		if (left < right)
			swap(arr[left], arr[right]);
	}
	swap(arr[right], arr[pivot]);
	return right;
}


int parentIndex(int i)
{
	return (i - 1) / 2;
}
int leftChildIndex(int i)
{
	return (2 * i) + 1;
}
int rightChildIndex(int i)
{
	return (2 * i) + 2;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void heapify(vector<Company>& arr, int size, int index) {
	int maxIndex;
	while (true) {
		int lIdx = leftChildIndex(index);
		int rIdx = rightChildIndex(index);
		if (rIdx >= size) {
			if (lIdx >= size)
				return;
			else
				maxIndex = lIdx;
		}
		else {
			if (arr[lIdx].noOfEmplployees >= arr[rIdx].noOfEmplployees)
				maxIndex = lIdx;
			else
				maxIndex = rIdx;
		}
		if (arr[index].noOfEmplployees < arr[maxIndex].noOfEmplployees) {
			swap(arr[index], arr[maxIndex]);
			index = maxIndex;
		}
		else
			return;
	}
}
vector<Company> heapSort(vector<Company>& arr, int size)
{
	for (int x = (size / 2) - 1; x >= 0; x--)
	{
		heapify(arr, size, x);
	}
	for (int x = size - 1; x > 0; x--)
	{
		swap(arr[0], arr[x]);
		heapify(arr, x, 0);
	}
	return arr;
}


vector<Company> countingSort(vector<Company> arr)
{
	int max = findMaximumEmployee(arr);
	vector<int> count(max + 1);
	vector<Company> output(arr.size());
	for (int x = 0; x < arr.size(); x++)
	{
		count[arr[x].noOfEmplployees]++;
	}
	for (int x = 1; x < count.size(); x++)
	{
		count[x] = count[x - 1] + count[x];
	}
	for (int x = arr.size() - 1; x >= 0; x--)
	{
		int index = count[arr[x].noOfEmplployees] - 1;
		count[arr[x].noOfEmplployees]--;
		output[index] = arr[x];
	}
	return output;
}
int findMaximumEmployee(vector<Company>vec) {
	int max = vec[0].noOfEmplployees;
	for (auto a : vec) {
		if (max < a.noOfEmplployees) {
			max = a.noOfEmplployees;
		}
	}
	return max;
}
vector<Company> countingSortWithIndex(vector<Company> arr)
{
	int max = findMaximumIndex(arr);
	vector<int> count(max + 1);
	vector<Company> output(arr.size());
	for (int x = 0; x < arr.size(); x++)
	{
		count[arr[x].index]++;
	}
	for (int x = 1; x < count.size(); x++)
	{
		count[x] = count[x - 1] + count[x];
	}
	for (int x = arr.size() - 1; x >= 0; x--)
	{
		int index = count[arr[x].index] - 1;
		count[arr[x].index]--;
		output[index] = arr[x];
	}
	return output;
}
int findMaximumIndex(vector<Company>vec) {
	int max = vec[0].index;
	for (auto a : vec) {
		if (max < a.index) {
			max = a.index;
		}
	}
	return max;
}

