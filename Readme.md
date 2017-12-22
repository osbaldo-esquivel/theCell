# Game of Life

## This program is based on Conway's Game of Life. You will be
asked the height and width of a grid to generate a living map.
The map will consist of living and dead cells that will die or
regenerate according to the following rules:

	1. If an occupied cell has zero or one neighbor, it dies of
	   loneliness.
	2. If an occupied cell has more than three neighbors, it dies
	   of overcrowding
	3. If an empty cell has exactly three occupied neigbor cells,
	   there is a birth of a new cell to replace the empty cell.
	4. Births and deaths are instantaneous and occur at the changes
	   of generation.
