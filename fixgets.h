/* fixgets.h by Harry W. Brown, circa 1986 */

// header file - note the ABSENCE of a main function 
// intended to be utilized by other programs

/* The enclosed function (fixgets) fixes a problem with fgets() 
 * incorporation of a line feed character before the terminating
 * NULL.  Allows white space, prevents overwriting of adjacent memory.
 * To use it, you must #include it in your source code.
 */

#include <stdio.h>

/* Prototype */
int fixgets(char *, int , FILE *);


/* This routine fixes fgets incorporation of line feeds and other
 * ASCII values less than 32 into an input string.  Written by H. Brown.
 */
int fixgets(char input_array[], int length, FILE *file_name)
   {
   register int position=0;

   if (fgets(input_array,length,file_name) != NULL)
     {
     while(input_array[position] != 0)
	  {              if (input_array[position] < 32) input_array[position]=0;
	  else ++position;
	  }
     }
	/* Flush the input buffer */
	fflush(stdin);   

	/* The length of the string is returned. */
	return position;
   }
