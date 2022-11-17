#pragma once
#include"Company.h"
#include<vector>
#include<queue>
vector<Company> bubbleSort(vector<Company>arr, int n);
vector<Company> bubbleSortWithIndex(vector<Company>arr, int n);
int findMinimum(vector<Company>arr, int start, int end);
int findMinimumIndex(vector<Company> arr, int start, int end);
vector<Company> selectionSort(vector<Company>arr, int n);
vector<Company> selectionSortWithIndex(vector<Company>arr, int n);
vector<Company> insertionSort(vector<Company>arr, int n);
vector<Company> insertionSortWithIndex(vector<Company>arr, int n);
vector<Company> mergeSortWithIndex(vector<Company>& arr, int start, int end);
void mergeWithIndex(vector<Company>& arr, int start, int mid, int end);
vector<Company> mergeSort(vector<Company>& arr, int start, int end);
void merge(vector<Company>& arr, int start, int mid, int end);
bool compare(Company a, Company b);