#include "CompanyDL.h"
 string CompanyDL::parse(string line, int index)
{
	int count = 0;
	string word = "";
	bool flag = true;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '"')
		{
			flag = !flag;
		}
		else if (line[i] == ',' && flag)
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
 void  CompanyDL::saveData(vector<Company>vec) {
	 ofstream myFile("SortedData.csv");
	 for (auto x : vec) {
		 myFile << x.index << "," << x.id << "," << x.name << "," << x.website << "," << x.country << "," << x.description << "," << x.foundedYear << ",";
		 myFile << x.industry << "," << x.noOfEmployees << endl;
	 }
	 myFile.flush();
	 myFile.close();
 }
 vector<Company>  CompanyDL::loadData(string fileName) {
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


 vector<Company> CompanyDL::bubbleSortWithEmployees(vector<Company> arr, int n)
{
	for (int x = 0; x < n - 1; x++)
	{
		bool isSwapped = false;
		for (int y = 0; y < n - x - 1; y++)
		{
			if (arr[y].noOfEmployees > arr[y + 1].noOfEmployees)
			{
				Company temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;

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
 vector<Company> CompanyDL::bubbleSortWithIndex(vector<Company> arr, int n)
{
	for (int x = 0; x < n - 1; x++)
	{
		bool isSwapped = false;
		for (int y = 0; y < n - x - 1; y++)
		{
			if (arr[y].index > arr[y + 1].index)
			{
				Company temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
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
 int  CompanyDL::findMinimumEmployee(vector<Company> arr, int start, int end)
{
	int min = arr[start].noOfEmployees;
	int minIndex = start;
	for (int x = start; x < end; x++)
	{
		if (min > arr[x].noOfEmployees)
		{
			min = arr[x].noOfEmployees;
			minIndex = x;
		}
	}
	return minIndex;
}
 int  CompanyDL::findMinimumIndex(vector<Company> arr, int start, int end)
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
 vector<Company>  CompanyDL::selectionSortWithEmployees(vector<Company> arr, int n)
{
	for (int x = 0; x < n - 1; x++)
	{
		int minIndex = findMinimumEmployee(arr, x, n);
		Company temp = arr[x];
		arr[x] = arr[minIndex];
		arr[minIndex] = temp;
	}
	return arr;
}
 vector<Company>  CompanyDL::selectionSortWithIndex(vector<Company> arr, int n)
{
	for (int x = 0; x < n - 1; x++)
	{
		int minIndex = findMinimumIndex(arr, x, n);
		Company temp = arr[x];
		arr[x] = arr[minIndex];
		arr[minIndex] = temp;

	}
	return arr;
}
 vector<Company>  CompanyDL::insertionSortWithEmployees(vector<Company> arr, int n)
{
	for (int x = 1; x < n; x++)
	{
		Company key = arr[x];
		int y = x - 1;
		while (y >= 0 && arr[y].noOfEmployees > key.noOfEmployees)
		{
			arr[y + 1] = arr[y];
			y--;
		}
		arr[y + 1] = key;
	}
	return arr;
}
 vector<Company>  CompanyDL::insertionSortWithIndex(vector<Company> arr, int n)
{
	for (int x = 1; x < n; x++)
	{
		Company key = arr[x];
		int y = x - 1;
		while (y >= 0 && arr[y].index > key.index)
		{
			arr[y + 1] = arr[y];
			y--;
		}
		arr[y + 1] = key;
	}
	return arr;
}
 vector<Company>  CompanyDL::mergeSortWithIndex(vector<Company> arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSortWithIndex(arr, start, mid);
		mergeSortWithIndex(arr, mid + 1, end);
		mergeWithIndex(arr, start, mid, end);
	}
	return arr;
}
 void CompanyDL::mergeWithIndex(vector<Company> arr, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	queue<Company> tempArr ;
	while (i <= mid && j <= end)
	{
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
	while (i <= mid)
	{
		tempArr.push(arr[i]);
		i++;
	}
	while (j <= end)
	{
		tempArr.push(arr[j]);
		j++;
	}
	for (int x = start; x <= end; x++)
	{
		arr[x] = tempArr.front();
		tempArr.pop();
	}
}
 vector<Company> CompanyDL::mergeSortWithEmployees(vector<Company> arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSortWithEmployees(arr, start, mid);
		mergeSortWithEmployees(arr, mid + 1, end);
		mergeWithEmployees(arr, start, mid, end);
	}
	return arr;
}
 void CompanyDL::mergeWithEmployees(vector<Company> arr, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	queue<Company> tempArr ;
	while (i <= mid && j <= end)
	{
		if (arr[i].noOfEmployees < arr[j].noOfEmployees)
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
	while (i <= mid)
	{
		tempArr.push(arr[i]);
		i++;
	}
	while (j <= end)
	{
		tempArr.push(arr[j]);
		j++;
	}
	for (int x = start; x <= end; x++)
	{
		arr[x] = tempArr.front();
		tempArr.pop();
	}
}
 bool CompanyDL::compare(Company a, Company b)
{
	return a.noOfEmployees < b.noOfEmployees;
}
 vector<Company> CompanyDL::quickSortWithEmployees(vector<Company> arr, int start, int end)
{
	if (start < end)
	{

		int pivot = start + rand() % (end - start + 1);
			
		Company temp1 = arr[start];
		arr[start] = arr[pivot];
		arr[pivot] = temp1;
		pivot = start;
		int mid = partitionWithEmployees(arr, start + 1, end, pivot);
		quickSortWithEmployees(arr, start, mid - 1);
		quickSortWithEmployees(arr, mid + 1, end);
	}
	return arr;
}
 int CompanyDL::partitionWithEmployees(vector<Company> arr, int start, int end, int pivot)
{
	int left = start;
	int right = end;
	while (left <= right)
	{
		while (left <= end && arr[left].noOfEmployees < arr[pivot].noOfEmployees)
		{
			left++;
		}
		while (right >= start && arr[right].noOfEmployees >= arr[pivot].noOfEmployees)
		{
			right--;
		}
		if (left < right)
		{
			Company temp1 = arr[left];
			arr[left] = arr[right];
			arr[right] = temp1;

		}

	}
	Company temp = arr[pivot];
	arr[pivot] = arr[right];
	arr[right] = temp;

	return right;
}
 vector<Company> CompanyDL::quickSortWithIndex(vector<Company> arr, int start, int end)
{
	if (start < end)
	{
		int pivot = start + rand() % (end - start + 1);
		Company temp1 = arr[start];
		arr[start] = arr[pivot];
		arr[pivot] = temp1;
		pivot = start;
		int mid = partitionWithIndex(arr, start + 1, end, pivot);
		quickSortWithIndex(arr, start, mid - 1);
		quickSortWithIndex(arr, mid + 1, end);
	}
	return arr;
}
 int  CompanyDL::partitionWithIndex(vector<Company> arr, int start, int end, int pivot)
{
	int left = start;
	int right = end;
	while (left <= right)
	{
		while (left <= end && arr[left].index < arr[pivot].index)
		{
			left++;
		}
		while (right >= start && arr[right].index >= arr[pivot].index)
		{
			right--;
		}
		if (left < right)
		{
			Company temp1 = arr[left];
			arr[left] = arr[right];
			arr[right] = temp1;

		}
	}
	Company temp = arr[pivot];
	arr[pivot] = arr[right];
	arr[right] = temp;

	return right;
}
 int CompanyDL::parentIndex(int i)
{
	return (i - 1) / 2;
}
 int  CompanyDL::leftChildIndex(int i)
{
	return (2 * i) + 1;
}
 int CompanyDL::rightChildIndex(int i)
{
	return (2 * i) + 2;
}
 void CompanyDL::swap( int &a,  int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
 void CompanyDL::heapifyWithIndex(vector<Company> arr, int size, int index)
{
	int maxIndex;
	while (true)
	{
		int lIdx = leftChildIndex(index);
		int rIdx = rightChildIndex(index);
		if (rIdx >= size)
		{
			if (lIdx >= size)
				return;
			else
			{
				maxIndex = lIdx;
			}
		}
		else
		{
			if (arr[lIdx].index >= arr[rIdx].index)
			{
				maxIndex = lIdx;
			}
			else
			{
				maxIndex = rIdx;
			}
		}
		if (arr[index].index < arr[maxIndex].index)
		{
			Company temp = arr[index];
			arr[index] = arr[maxIndex];
			arr[maxIndex] = temp;
			index = maxIndex;
		}
		else
			return;
	}
}
 vector<Company> CompanyDL::heapSortWithIndex(vector<Company> arr, int size)
{
	for (int x = (size / 2) - 1; x >= 0; x--)
	{
		heapifyWithIndex(arr, size, x);
	}
	for (int x = size - 1; x > 0; x--)
	{

		Company temp = arr[0];
		arr[0] = arr[x];
		arr[x] = temp;
		heapifyWithIndex(arr, x, 0);
	}
	return arr;
}
 void  CompanyDL::heapifyWithEployees(vector<Company> arr, int size, int index)
{
	int maxIndex;
	while (true)
	{
		int lIdx = leftChildIndex(index);
		int rIdx = rightChildIndex(index);
		if (rIdx >= size)
		{
			if (lIdx >= size)
				return;
			else
			{
				maxIndex = lIdx;
			}
		}
		else
		{
			if (arr[lIdx].noOfEmployees >= arr[rIdx].noOfEmployees)
			{
				maxIndex = lIdx;
			}
			else
			{
				maxIndex = rIdx;
			}
		}
		if (arr[index].noOfEmployees < arr[maxIndex].noOfEmployees)
		{

			Company temp = arr[index];
			arr[index] = arr[maxIndex];
			arr[maxIndex] = temp;
			index = maxIndex;
		}
		else
			return;
	}
}
 vector<Company>  CompanyDL::heapSortWithEmployees(vector<Company> arr, int size)
{
	for (int x = (size / 2) - 1; x >= 0; x--)
	{
		heapifyWithEployees(arr, size, x);
	}
	for (int x = size - 1; x > 0; x--)
	{
		Company temp = arr[0];
		arr[0] = arr[x];
		arr[x] = temp;
		heapifyWithEployees(arr, x, 0);
	}
	return arr;
}
 vector<Company> CompanyDL::countingSortWithEmployees(vector<Company> arr)
{

	int max = findMaximumEmployee(arr);
	vector<int> count (max + 1);
	vector<Company> output (arr.size());
	for (int x = 0; x < arr.size(); x++)
	{
		count[arr[x].noOfEmployees]++;
	}
	for (int x = 1; x < count.size(); x++)
	{
		count[x] = count[x - 1] + count[x];
	}
	for (int x = arr.size() - 1; x >= 0; x--)
	{
		int index = count[arr[x].noOfEmployees] - 1;
		count[arr[x].noOfEmployees]--;
		output[index] = arr[x];
	}
	return output;
}
 int  CompanyDL::findMaximumEmployee(vector<Company> vec)
{
	int max = vec[0].noOfEmployees;
	for(auto a : vec)
	{
		if (max < a.noOfEmployees)
		{
			max = a.noOfEmployees;
		}
	}
	return max;
}
 vector<Company> CompanyDL::countingSortWithIndex(vector<Company> arr)
{

	int max = findMaximumIndex(arr);
	vector<int> count (max + 1);
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
 int  CompanyDL::findMaximumIndex(vector<Company> vec)
{
	int max = vec[0].index;
	for(auto a : vec)
	{
		if (max < a.index)
		{
			max = a.index;
		}
	}
	return max;
}
 vector<Company>  CompanyDL::radixSortWithEmployees(vector<Company> arr)
{

	int max = findMaximumEmployee(arr);
	int place = 1;
	while ((max / place) > 0)
	{
		countingSortWithEmployees( arr, place);
		place = place * 10;
	}
	return arr;
}
 vector<Company> CompanyDL::radixSortWithIndex(vector<Company> arr)
{

	int max = findMaximumIndex(arr);
	int place = 1;
	while ((max / place) > 0)
	{
		countingSortWithIndex( arr, place);
		place = place * 10;
	}
	return arr;
}
 void  CompanyDL::countingSortWithEmployees( vector<Company>& arr, int place)
{
	vector<int> count (10);
	vector<Company> output(arr.size());
	for (int x = 0; x < arr.size(); x++)
	{
		count[(arr[x].noOfEmployees / place) % 10]++;
	}
	for (int x = 1; x < count.size(); x++)
	{
		count[x] = count[x - 1] + count[x];
	}
	for (int x = arr.size() - 1; x >= 0; x--)
	{
		int index = count[(arr[x].noOfEmployees / place) % 10] - 1;
		count[(arr[x].noOfEmployees / place) % 10]--;
		output[index] = arr[x];
	}
	arr = output;
}
 void CompanyDL::countingSortWithIndex( vector<Company> &arr, int place)
{
	vector<int> count(10);
	vector<Company> output(arr.size());
	for (int x = 0; x < arr.size(); x++)
	{
		count[(arr[x].index / place) % 10]++;
	}
	for (int x = 1; x < count.size(); x++)
	{
		count[x] = count[x - 1] + count[x];
	}
	for (int x = arr.size() - 1; x >= 0; x--)
	{
		int index = count[(arr[x].index / place) % 10] - 1;
		count[(arr[x].index / place) % 10]--;
		output[index] = arr[x];
	}
	arr = output;
}
 vector<Company> CompanyDL::bucketSortWithEmployyees(vector<Company> arr, int noOfBuckets)
{

	vector<vector<Company>> bucket (noOfBuckets);

	for (int x = 0; x < arr.size(); x++)
	{
		bucket[arr[x].noOfEmployees].push_back(arr[x]);
	}
	/*  for (int x = 0; x < bucket.size(); x++)
	  {
		  if (bucket[x].size()!=0)
		  bucket[x].Sort((a, b) => a.noOfEmployees.CompareTo(b.noOfEmployees));

	  }*/
	int index = 0;

	for (int x = 0; x < bucket.size(); x++)
	{
		for (int y = 0; y < bucket[x].size(); y++)
		{
			arr[index] = (bucket[x][y]);
			index++;
		}
	}
	return arr;
}
 vector<Company> CompanyDL::bucketSortWithIndex(vector<Company> arr, int noOfBuckets)
{
	int max = findMaximumIndex(arr);
	vector<vector<Company>> bucket(max + 1);
	
	for (int x = 0; x < arr.size(); x++)
	{
		bucket[arr[x].index].push_back(arr[x]);
	}
	/*  for (int x = 0; x < bucket.size(); x++)
	   {
			   bucket[x].Sort((a, b) => a.index.CompareTo(b.index));

	   }*/
	int index = 0;

	for (int x = 0; x < bucket.size(); x++)
	{
		for (int y = 0; y < bucket[x].size(); y++)
		{
			arr[index] = (bucket[x][y]);
			index++;
		}
	}
	return arr;
}


