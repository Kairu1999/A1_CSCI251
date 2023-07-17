#ifndef MEMORYALLOCATION_H
#define MEMORYALLOCATION_H

int** Allocate2DArrayMemory(int xsize, int ysize);
void DeAllocate2DArrayMemory(int** ptr, int x_size);


#endif;