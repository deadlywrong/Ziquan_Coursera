/*
 * stats.c
 *
 *  Created on: 2018年4月1日
 *      Author: Ziquan
 */


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
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  sort_array(test, SIZE);

  return 1;
}

unsigned char find_mean(unsigned char *char_array, unsigned int size){
	unsigned char mean = 0;
	unsigned int sum = 0;

	for (int i = 0; i < 40 ; i++)
	{
		  sum = sum + char_array[i];
	}
	mean = sum/size;
	return mean;
}

void sort_array(unsigned char *char_array, unsigned int size){
	for (int i = size-1 ; i > 0; i--){
		for(int j = size-1; j > 0; j--){
			if (char_array[j-1] < char_array[j]){
				unsigned char temp = char_array[j];
				char_array[j] = char_array[j-1];
				char_array[j-1] = temp;
			}
		}
	}
}

int print_array(unsigned char *char_array, unsigned int size){
	for (int i = 0; i < size; i++){
		unsigned char output = char_array[i];
		if(i%4 == 3){
			printf(" %2d: (%3d)\n",i+1, output);
		}
		else {

			printf(" %2d: (%3d);",i+1, output);
		}
	}
	return 1;
}
/* Add other Implementation File Code Here */
unsigned char find_median(unsigned char *char_array, unsigned int size){
	sort_array(char_array, SIZE);
	unsigned char result;
	if (size%2 == 1){
		return char_array[size/2];
	}
	else
	{
		result = (char_array[size/2]+char_array[size/2+1])/2;
		return result;
	}
}

unsigned char find_maximum(unsigned char *char_array, unsigned int size){
	sort_array(char_array, SIZE);
	unsigned char result = char_array[0];
	return result;
}

unsigned char find_minimum(unsigned char *char_array, unsigned int size){
	sort_array(char_array, SIZE);
	unsigned char result = char_array[size-1];
	return result;

}

