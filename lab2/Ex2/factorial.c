#include "factorial.h"
#include <stdlib.h>
#include <stdio.h>

char* factorial(const int aNumber) {
	char* result_arr;
	int index = 0;
	int temp;
	char* a = (char*)malloc(1000000*sizeof(char));
	a[0] = 1;
	for(int i = aNumber; i >=2; i--) {
		temp = 0;
		for(int j = 0; j <= index; j++) {
			int temp1 = (i%10) * a[j] + temp;
			temp = (i/10) * a[j] + temp1/10;
			a[j] = temp1 % 10;
		}
		while(temp > 0) {
			a[++index] = temp%10;
			temp = temp/10;
		}
	}
	result_arr = (char*)malloc(index+2);
	for(int i = 0; i <= index; i++) {
		result_arr[i] = a[index - i]%10 + '0';
	}
	result_arr[index + 1] ='\0';
	return (char*)result_arr;
}
