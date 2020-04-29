#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED
////////////////////////////////////////////////////////////////

char dialogue[1000];

void removeNewLine(char *dest, char *source) {
	int i;
	for (i=0; i<strlen(source); i++) {
		if (source[i] == '\n') {
			break;
		}
		dest[i] = source[i];
	}
	if (i == strlen(source) - 1) {
		dest[i] = '\0';
	}
	else {
		dest[i+1] = '\0';
	}
}

void pullNumber(char *dest, char *source) {
	int i, j = 0;
	for (i=0; i<strlen(source); i++) {
		if (source[i] == ':') {
			j = i;
			continue;
		}
		else if (j == 0) continue;

		if (source[i] == '\n') break;
		dest[i-j-1] = source[i];
	}
	dest[i-j-1] = '\0';
}

void print(char *string) {
	for (int i = 0; i<strlen(string); i++) {
		usleep(15000);
		printf("%c", string[i]);
		fflush(stdout);
	}
	printf("\n");
}

void randomIndices(int array[4]) {
	array[0] = rand() % 4;
	do {
		array[1] = rand() % 4;
	} while (array[1] == array[0]);
	do {
		array[2] = rand() % 4;
	} while (array[2] == array[1] || array[2] == array[0]);
	do {
		array[3] = rand() % 4;
	} while (array[3] == array[2] || array[3] == array[1] || array[3] == array[0]);
}

int dodgeAssert(int dodge) {
	int probability;
	if (dodge >= 10) probability = 8;
	else probability = dodge;
	if (rand()%10+1 <= probability) return 1;
	return 0;
	
}

void color(char val) {
	if (val == 'r') printf("\033[0;31m");
	if (val == 'R') printf("\033[1;31m");
	if (val == 'g') printf("\033[0;32m");
	if (val == 'G') printf("\033[1;32m");
	if (val == 'y') printf("\033[0;33m");
	if (val == 'Y') printf("\033[1;33m");
	if (val == 'b') printf("\033[0;34m");
	if (val == 'B') printf("\033[1;34m");
	if (val == 'm') printf("\033[0;35m");
	if (val == 'M') printf("\033[1;35m");
	if (val == 'c') printf("\033[0;36m");
	if (val == 'C') printf("\033[1;36m");
}

void reset () {
  printf("\033[0m");
}

void printColorSpeed(char *string, char val, char speed) {
	int tempo;
	if (speed == 'F') tempo = 2000; //5000 //Fast
	if (speed == 'S') tempo = 70000; //Slow
	if (speed == 'N') tempo  = 15000;  //Normal
	if (speed == 'R') tempo  = 45000; //Reading
	if (speed == 'Q') tempo  = 10000; //Quick



	for (int i = 0; i<strlen(string); i++) {
		usleep(tempo);
		color(val);
		printf("%c", string[i]);
		fflush(stdout);
	}
	printf("\n");
	reset();
}

void askName(char *name) {
	char decision[20], userInput[64];

	sprintf(dialogue, "What is your name?\n");	
	print(dialogue);
	while(1) {
		fgets(userInput, 19, stdin);
		if (sscanf(userInput, "%s", name) == 1) break;

		else {
		sprintf(dialogue, "That's an invalid name\n");	
		print(dialogue);
		}
	}
	sleep(1);
	sprintf(dialogue, "\n...\n");	
	print(dialogue);
	sleep(1);
}

#endif





