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
			int child_left = (2 * (i - 1)) + 1;
			int child_right = (2 * (i - 1)) + 2;
			if (child_left < size)
			{
				printf("\n%d left(%d) %d", i, arr[i - 1], arr[child_left]);
			}
			else
			{
				break;
			}
			if (child_right < size)
			{
				printf("\n%d right(%d) %d", i, arr[i - 1], arr[child_right]);
			}
			else
			{
				break;
			}
		}
	}
}

enum class directions
{
	up,
	left,
	right,
	def
};


void travel(int* arr, int size, std::string direction, int* level, int* parent_index, int* child_index)
{
	printf("Ок\n");
	directions swich = directions::def;
	if (direction == "up")
	{
		swich = directions::up;
	}
	if (direction == "left")
	{
		swich = directions::left;
	}
	if (direction == "right")
	{
		swich = directions::right;
	}


	switch (swich)
	{
	case directions::up:
		(*level)--;
		if (*level == 0)
		{
			printf("Вы находитесь здесь: 0 root %d", arr[0]);
			*level = 0;
			*parent_index = 0;
			*child_index = 0;
			return;
		}
		if (*level < 0)
		{
				printf("Ошибка!Отсутствует родитель");
				printf("\nВы находитесь здесь: 0 root %d", arr[0]);
				*level = 0;
				*parent_index = 0;
				*child_index = 0;
				return;
		}
	
		(*child_index) = (*parent_index);
		if ((*parent_index) % 2 != 0)
		{
			direction = "left";
			(*parent_index) = ((*child_index) - 1) / 2;
		}
		else
		{
			direction = "right";
			(*parent_index) = ((*child_index) - 2) / 2;
		}
		break;
	case directions::left:
		(*parent_index) = (*child_index);
		if ((2 * (*parent_index)) + 1 < size)
		{
			(*level)++;
			(*child_index) = (2 * (*parent_index)) + 1;
		}
		else
		{
			printf("Ошибка! Отсутствует левый потомок");
			return;
		}
		break;
	case directions::right:
		(*parent_index) = (*child_index);
		if ((2 * (*parent_index)) + 2 < size)
		{
			(*level)++;
			(*child_index) = (2 * (*parent_index)) + 2;
		}
		else
		{
			printf("Ошибка! Отсутствует правый потомок");
			return;
		}
		break;
	default:
		printf("Не корректный ввод");
		return;
		
	}

	printf("Вы находитесь здесь: %d %s(%d) %d", *level, direction.c_str(), arr[*parent_index], arr[*child_index]);
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");


	int arr[]{1, 3, 6, 5, 9, 8, 11};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Исходный массив: ");
	for (int i = 0; i < size; i++)
	{
		printf(std::to_string(arr[i]).c_str());
		printf(" ");
	}

	printf("\nПирамида: \n");
	print_pyramid(arr, size);

	printf("\nВы находитесь здесь: 0 root %d", arr[0]);
	std::string direction = "";
	int level = 0;
	int parent_index = 0;
	int child_index = 0;
	while (true)
	{
		printf("\nВведите команду: ");
		std::cin >> direction;
		if (direction == "exit")
		{
			break;
		}
		travel(arr, size, direction, &level, &parent_index, &child_index);
	}
	return 0;
}