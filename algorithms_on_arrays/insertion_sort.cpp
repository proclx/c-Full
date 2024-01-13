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
