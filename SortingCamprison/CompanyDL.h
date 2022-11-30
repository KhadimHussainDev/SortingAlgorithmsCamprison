#pragma once
#include"Company.h"
#include<vector>
#include<queue>
#include<iostream>
#include<string>
#include<fstream>
class CompanyDL
{
public:
	vector<Company>companies;
	static string parse(string line, int index);
	static vector<Company> loadData(string fileName);
	static void addTovector(Company company);
	static vector<Company> bubbleSortWithEmployees(vector<Company> arr, int n);
	static vector<Company> bubbleSortWithIndex(vector<Company> arr, int n);
	static int findMinimumEmployee(vector<Company> arr, int start, int end);
	static int findMinimumIndex(vector<Company> arr, int start, int end);
	static vector<Company> selectionSortWithEmployees(vector<Company> arr, int n);
	static vector<Company> selectionSortWithIndex(vector<Company> arr, int n);
	static vector<Company> insertionSortWithEmployees(vector<Company> arr, int n);
	static vector<Company> insertionSortWithIndex(vector<Company> arr, int n);
	static vector<Company> mergeSortWithIndex(vector<Company> arr, int start, int end);
	static void mergeWithIndex(vector<Company> arr, int start, int mid, int end);
	static vector<Company> mergeSortWithEmployees(vector<Company> arr, int start, int end);
	static void mergeWithEmployees(vector<Company> arr, int start, int mid, int end);
	static bool compare(Company a, Company b);
	static vector<Company> quickSortWithEmployees(vector<Company> arr, int start, int end);
	static int partitionWithEmployees(vector<Company> arr, int start, int end, int pivot);
	static vector<Company> quickSortWithIndex(vector<Company> arr, int start, int end);
	static int partitionWithIndex(vector<Company> arr, int start, int end, int pivot);
	static int parentIndex(int i);
	static int leftChildIndex(int i);
	static int rightChildIndex(int i);
	static void swap( int &a,  int &b);
	static void heapifyWithIndex(vector<Company> arr, int size, int index);
	static vector<Company> heapSortWithIndex(vector<Company> arr, int size);
	static void heapifyWithEployees(vector<Company> arr, int size, int index);
	static vector<Company> heapSortWithEmployees(vector<Company> arr, int size);
	static vector<Company> countingSortWithEmployees(vector<Company> arr);
	static int findMaximumEmployee(vector<Company> vec);
	static vector<Company> countingSortWithIndex(vector<Company> arr);
	static int findMaximumIndex(vector<Company> vec);
	static vector<Company> radixSortWithEmployees(vector<Company> arr);
	static vector<Company> radixSortWithIndex(vector<Company> arr);
	static void countingSortWithEmployees( vector<Company> &arr, int place);
	static void countingSortWithIndex( vector<Company>& arr, int place);
	static vector<Company> bucketSortWithEmployyees(vector<Company> arr, int noOfBuckets);
	static vector<Company> bucketSortWithIndex(vector<Company> arr, int noOfBuckets);
	static void saveData(vector<Company>vec);
};