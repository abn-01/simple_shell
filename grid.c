#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees the memory allocated for a 2D grid.
 * @grid: The 2D grid to be freed.
 * @height: The number of rows in the grid.
 *
 * Return: void
 */
void free_grid(char **grid, int height)
{
	for (int i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
