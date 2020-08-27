/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Himanshu Sahu
 * @date <15/08/20>
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void main() {

  int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    print_array(test);
	sort_array(test);
	printf("\nThe Sorted array is :\n");
	print_array(test);
	printf("\nPrinting the statistics  :\n");
	print_statistics(test);
}

/* Add other Implementation File Code Here */

void print_statistics(int test[])
{
	int avg,median,mode,max,min;
	avg =  find_mean(test);
	median = find_median(test);
	mode =  find_mode(test);
	max =   find_maximum(test);
	min =   find_minimum(test);
	
	printf("\nThe value of mean is :%d\nThe value of median is%d\nThe value of mode is:%d",avg,median,mode);
	printf("\nThe Maximum value in the array: %d\nThe Maximum value in the array: %d",max,min);
	
}

void print_array(int test[])
{
	int i;
	printf("Printing the values of Arrays::\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d\t",test[i]);
	}
}
int find_median( int test[])
{

 int median;
 median = test[SIZE/2];
 return median;	
}

int find_mode( int test[])
{
  int i,j,Num = 0, maxCount = 0;

   for (i = 0; i < SIZE; ++i) 
   {
      int count = 0;
      
      for (j = 0; j < SIZE; ++j) 
	  {
         if (test[j] == test[i])
		    ++count;			
		 
      }
      
      if (count > maxCount) {
         maxCount = count;
         Num = test[i];
      }
   }

return Num;

}
	
float find_mean( int test[])
{
  int sum=0,i;
  for(i=0;i<SIZE;i++)
  {
      sum = sum + test[i];
  }
  return sum/SIZE;

	return 0;
	
}
int find_maximum(int test[])
{
	return test[SIZE-1];
}
int find_minimum(int test[])
{
	return test[0];
}

void sort_array(int test[])
{
	int i, key, j;  
    for (i = 1; i < SIZE; i++) 
    {  
        key = test[i];  
        j = i - 1;  
        while (j >= 0 && test[j] > key) 
        {  
            test[j + 1] = test[j];  
            j = j - 1;  
        }  
        test[j + 1] = key;  
    }  
	
	
}


