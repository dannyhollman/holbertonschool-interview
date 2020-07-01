#include "slide_line.h"

/**
 * slide_right - slides the line right
 * @line: input line
 * @size: size of line
 */
void slide_right(int *line, size_t size)
{
	int i, j, save, moved = size - 1;

	for (i = size - 2; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			save = line[i];
			for (j = i + 1; j <= moved; j++)
			{
				if (line[j] == save)
				{
					line[j] += save;
					line[i] = 0;
					moved--;
					break;
				}
				else if (j == moved && line[j + 1] != 0 && line[j] == 0)
				{
					line[j] = save;
					line[i] = 0;
					break;
				}

			}
		}
	}
}

/**
 * slide_left - slides the line left
 * @line: input line
 * @size: size of line
 */
void slide_left(int *line, size_t size)
{
	int i, j, save, moved = 0;

	for (i = 1; i < (int) size; i++)
	{
		if (line[i] != 0)
		{
			save = line[i];
			for (j = i - 1; j >= moved; j--)
			{
				if (line[j] == save)
				{
					line[j] += save;
					line[i] = 0;
					moved++;
					break;
				}
				else if (j == moved && line[j - 1] != 0 && line[j] == 0)
				{
					line[j] = save;
					line[i] = 0;
					break;
				}

			}
		}
	}
}

/**
 * slide_line - slides line to left or right
 * @line: line input from user
 * @size: size of line
 * @direction: direction to move the line
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}

	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}

	return (0);
}
