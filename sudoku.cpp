#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "sudoku.hpp"

using namespace std;
#define UNASSIGNED 0
 
bool find_unassigned_location(int grid[N][N], int &row, int &col);
bool is_safe(int grid[N][N], int row, int col, int num);
 
bool solve_sudoku(int grid[N][N])
{
    int row, col;
    if (!find_unassigned_location(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (is_safe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solve_sudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
 
bool find_unassigned_location(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
bool used_in_row(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool used_in_col(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool used_in_box(int grid[N][N], int box_start_row, int box_start_col, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+box_start_row][col+box_start_col] == num)
                return true;
    return false;
}
 

bool is_safe(int grid[N][N], int row, int col, int num)
{
    return !used_in_row(grid, row, num) && !used_in_col(grid, col, num) &&
           !used_in_box(grid, row - row % 3 , col - col % 3, num);
}

void print_grid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout<<grid[row][col]<<"  ";
        cout<<endl;
    }
}