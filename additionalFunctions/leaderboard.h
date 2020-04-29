#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "text.h"
#include "aux.h"

#ifndef LEADERBOARD_H_INCLUDED
#define LEADERBOARD_H_INCLUDED
////////////////////////////////////////////////////////////////

#define MAXRECORDS 5

typedef struct Record {
	char name[10];
	float time;
	struct Record *next;
} Record;

typedef struct RecordLL {
	int size;
	Record *head;
	Record *tail;
} RecordLL;

void printRecordsLL(RecordLL *list) {
	Record *currNode = list->head;
	for (int i = 0; i < list->size; i++) {
		sprintf(dialogue, "%35s: %f seconds\n", currNode->name, currNode->time);
		printColorSpeed(dialogue, 'X', 'N');

		currNode = currNode->next;
	}
}

void popRecord(RecordLL *list) {
	Record *currNode = list->head;
	if (list->size == 0) {
		return;
	}
	else if (list->size == 1) {
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		while (currNode->next->next != NULL) {
			currNode = currNode->next;
		}
		currNode->next = NULL;
		list->tail = currNode;
	}
	list->size --;
}


void addRecord(RecordLL *list, Record *node) {
	Record *currNode = list->head;

	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	}
	else if (node->time < currNode->time) {
		node->next = list->head;
		list->head = node;
	}
	else {
		while (currNode->next != NULL) {
			if (node->time < currNode->next->time) {
				node->next = currNode->next;
				currNode->next = node;
				break;
			}
			currNode = currNode->next;
		}
		if (currNode == list->tail) {
			currNode->next = node;
			list->tail = node;
		}
	}

	list->size ++;

	if (list->size > MAXRECORDS) {
		popRecord(list);
	}
}


void recordInit(Record *node, char username[10], float score) {
	strcpy(node->name, username);
	node->time = score;
	node->next = NULL;
}

void recordLLInit(RecordLL *recordList, const char *recordDocument) {
	FILE *fp;

	char buff[255], name[10], description[200], intermediate[10], type;
	float score;

	recordList->head = NULL;
	recordList->tail = NULL;
	recordList->size = 0;

	fp = fopen(recordDocument, "r");

	if (fp == NULL) {
		printf("Error opening file\n");
		return;
	}
	while (fgets(buff, 255, (FILE*)fp)) {
		//This above fgets is a whitespace skip

		fgets(buff, 255, (FILE*)fp);
		removeNewLine(name, buff);

		fgets(buff, 255, (FILE*)fp);
		removeNewLine(intermediate, buff);
		score = atof(intermediate);

		Record *node = malloc(sizeof(Record));
		recordInit(node, name, score);
		addRecord(recordList, node);	
	}
	fclose(fp);
}

int isRecord(RecordLL *list, float time) {
	return time < (list->tail->time);
}

void writeToRecords(const char *recordDocument, float time) {
	FILE *fp;

	char buff[255], name[10], intermediate[10], userInput[64];;

	Record *currNode;

	RecordLL *list = malloc(sizeof(RecordLL));	
	recordLLInit(list, recordDocument);

	if (isRecord(list, time)) {
		while(1) {
			sprintf(dialogue, "High score! Give a name for the leaderboard...\n");
			printColorSpeed(dialogue, 'X', 'N');
			fgets(userInput, 10, stdin);
			if (sscanf(userInput, "%s", name) == 1) break;
			else {
				sprintf(dialogue, "That isn't a name...\n");
				printColorSpeed(dialogue, 'X', 'N');
			}
		}

		Record *newRecord = malloc(sizeof(Record));
		recordInit(newRecord, name, time);

		addRecord(list, newRecord);
	}

	fp = fopen(recordDocument, "w");

	if (fp == NULL) {
		printf("Error opening file\n");
		return;
	}

	currNode = list->head;

	while (currNode != NULL) {

		if (currNode == list->tail) fprintf(fp, "\n%s\n%f", currNode->name, currNode->time);
		else fprintf(fp, "\n%s\n%f\n", currNode->name, currNode->time);

		currNode = currNode->next;
	}
	fclose(fp);

	highScoring();
	printRecordsLL(list);

	sleep(4);
}




#endif


