#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factorial.h"
#include "readline.h"

int main(int argc, char* argv[]) {
	char input[50];
	char *result;
	while(1) {
		printf("Input:");
		scanf("%s", input);
		if(read_line(input) == 1) {
			result = factorial(atoi(input));
			printf("%s\n", result);
		} else {
			printf("-1");
			break;
		}	
	}
	return 1;
}
