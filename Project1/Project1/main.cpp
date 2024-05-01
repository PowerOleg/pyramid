#include <iostream>
#include <string>

void print_pyramid(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			printf("%d root ", i);
			if (i < size)
			{
				printf(std::to_string(arr[i]).c_str());
			}

		}
		else
	{
			//if (i % 2 != 0)
			//{
			if (i < size)
			{
				int child_left = (2 * (i - 1)) + 1;
				int child_right = (2 * (i - 1)) + 2;
				if (child_left < size)
				{
					printf("\n%d left(%d) %d", i, arr[i - 1], arr[child_left]);
				}
				if (child_right < size)
				{
					printf("\n%d right(%d) %d", i, arr[i - 1], arr[child_right]);
				}
			}
	}
		//}
		//if (i != 0 && i % 2 == 0)
		//{
			/*if (i < size)
			{
				int child_left = (2 * (i - 1)) + 1;
				int child_right = (2 * (i - 1)) + 2;
				if (child_left < size)
				{
					printf("\n%d left(%d) %d", i, arr[i - 1], arr[child_left]);
				}
				if (child_right < size)
				{
					printf("\n%d right(%d) %d", i, arr[i - 1], arr[child_right]);
				}
			}*/
		//}

	}

}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	int size = 6;

	int arr[]{1, 3, 6, 5, 9, 8};
	printf("Исходный массив: ");
	for (int i = 0; i < size; i++)
	{
		printf(std::to_string(arr[i]).c_str());
		printf(" ");
	}

	printf("\nПирамида: \n");
	print_pyramid(arr, size);
	
	return 0;
}