#include <stdio.h>
#include <string.h>
#include "readline.h"

int read_line(char* str) {
	int isInt = 1;
	for(int i = 0; i <strlen(str); i++) {
		if(str[i] < 48 || str[i] >57) {
			isInt = 0; 
			break;
		}
	}
	return isInt;
}
