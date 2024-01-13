#include <iostream>

void print_array(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
}

void insertion_sort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			int temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;

			for (int j = i; j >= 1; --j)
			{
				if (arr[j - 1] > arr[j])
				{
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
				else
					break;
			}
		}
	}
}

int main()
{
	constexpr int ARRAY_SIZE = 8;
	int arr[ARRAY_SIZE] = { 6, 5, 3, 1, 8, 7, 2, 4 };
	print_array(arr, ARRAY_SIZE);
	std::cout << std::endl;
	insertion_sort(arr, ARRAY_SIZE);
	print_array(arr, ARRAY_SIZE);
	std::cout << std::endl;

	return 0;
}
