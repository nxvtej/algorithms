#include <iostream>
#include <vector>
using namespace std;

class MergeSort
{
public:
	void mergesort3way(vector<int> &array, int size)
	{
		if (size == 0)
			return;
		vector<int> fArray;
		for (auto it : array)
			fArray.push_back(it);

		mergeSort3wayRecursion(fArray, 0, size, array);

		for (int i = 0; i < size; i++)
		{
			array[i] = fArray[i];
		}
	}

private:
	void mergeSort3wayRecursion(vector<int> &fArray, int start,
								int end, vector<int> &destinationArray)
	{

		if (high - low < 2)
			return;

		int mid1 = low + ((high - low) / 3);
		int mid2 = low + 2 * ((high - low) / 3) + 1;

		mergeSort3wayRecursion(destinationArray, low, mid1, fArray);
		mergeSort3wayRecursion(destinationArray, mid1, mid2, fArray);
		mergeSort3wayRecursion(destinationArray, mid2, high, fArray);

		merge(destinationArray, low, mid1, mid2, high, fArray);
	}

private:
	void merge() {}
};
int main()
{
	vector<int> array = {45, -2, -45, 78, 30,
						 -42, 10, 19, 73, 93};
	MergeSort mergeObject;

	mergeObject.mergesort3way(array, 10);
}