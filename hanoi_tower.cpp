#include "hanoi_tower.hpp"

void hanoi(int height, char from_rod, char to_rod, char aux_rod)
{
    if (height == 1)
    {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    hanoi(height - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << height << " from rod " << from_rod << " to rod " << to_rod << endl;
    hanoi(height - 1, aux_rod, to_rod, from_rod);
}