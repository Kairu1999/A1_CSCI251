#ifndef MEMORYALLOCATION_H
#define MEMORYALLOCATION_H

void Allocate2DArrayMemory_city(int xsize, int ysize, int** ptr);
void PopulateCity2DArray(int xsize, int ysize, vector<cityStructure> vect, int** ptr);
void Allocate2DArrayMemory_cp(int xsize, int ysize, int** ptr);
void PopulateCloudyPressure2DArray(int xsize, int ysize, vector<cloudyPressure>vect, int** ptr);
void DeAllocate2DArrayMemory(int** ptr, int x_size);


#endif;