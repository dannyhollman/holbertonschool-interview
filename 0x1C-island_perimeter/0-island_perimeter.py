#!/usr/bin/python3
""" Calculates perimeter of and island """


def island_perimeter(grid):
    """ Calculates island perimeter """
    perim = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                if row > 0 and grid[row - 1][col] == 0:
                    perim += 1
                if col > 0 and grid[row][col - 1] == 0:
                    perim += 1
                if row < len(grid) and grid[row + 1][col] == 0:
                    perim += 1
                if col < len(grid[row]) and grid[row][col + 1] == 0:
                    perim += 1
    return perim
