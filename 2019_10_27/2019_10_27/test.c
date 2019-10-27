#define _CRT_SECURE_NO_WARNINGS 1
int binary_search(int* arr, int key, int n)
{
	int low = 0;
	int mid;
	int high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < arr[mid])
		{
			high = mid - 1;
		}
		else if (key > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	if (1)
	{
		int it[] = { 0,1,2,3,4,5,6,7 };
		int index = binary_search(it, 7, 8);
		printf("index=%d\n", index); //index=7
	}

	return 0;
}