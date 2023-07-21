#ifndef MEMORYALLOCATION_H
#define MEMORYALLOCATION_H

int** Allocate2DArrayMemory_city(int xsize, int ysize, vector<cityStructure> vect);
int** Allocate2DArrayMemory_cp(int xsize, int ysize, vector<cloudyPressure> vect);
int Update2DArrayValues(int value);
int Update2DArrayValuesLMH(int value);
void Update2DArray(int** ptr, int xsize, int ysize, int mode);
void DeAllocate2DArrayMemory(int** ptr, int x_size);


#endif;