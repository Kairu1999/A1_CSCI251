#ifndef MEMORYALLOCATION_H
#define MEMORYALLOCATION_H

int** Allocate2DArrayMemory_city(int xsize, int ysize, vector<cityStructure> vect);
int** Allocate2DArrayMemory_cp(int xsize, int ysize, vector<cloudyPressure> vect);
void DeAllocate2DArrayMemory(int** ptr, int x_size);


#endif;