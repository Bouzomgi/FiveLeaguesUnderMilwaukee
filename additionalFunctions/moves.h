#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "aux.h"

#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED
////////////////////////////////////////////////////////////////

typedef struct MoveNode {
	int successful;
	int moveDifficulty;
	int movePower;
	int moveType;
	char answers[4][200];
	char correctAnswer[200];
	char movePrompt[200];
	char moveName[30];
	struct MoveNode *next;
} MoveNode;

typedef struct MoveLL {
	int size;
	MoveNode *head;
	MoveNode *tail;
} MoveLL;

void MoveNodeInit(MoveNode *node, int diff, char answer[200], char posAnswers[4][200],  char *prompt, char *name, int type) {
	node->successful = 0;
	node->moveDifficulty = diff;
	node->movePower = diff * 10;
	node->moveType = type;
	strcpy(node->movePrompt, prompt);
	strcpy(node->moveName, name);
	strcpy(node->correctAnswer, answer);
	for (int i = 0; i<4; i++) {
		strcpy(node->answers[i], posAnswers[i]);
	}
}

void printLL(MoveLL *list) {
	MoveNode *currNode = list->head;
	for (int i = 0; i < list->size ;i++) {
		printf("%s\n", currNode->moveName);
		currNode = currNode->next;
	}
	printf("End\n\n");
}

void addRandomSpot(MoveLL *list, MoveNode *node) {
	int spot = rand() % (list->size + 1);
	MoveNode *currNode = list->head;

	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	}
	else if (spot == 0) {
		node->next = list->head;
		list->head = node;
	}
	else if (spot == list->size) {
		list->tail->next = node;
		list->tail = node;
	}
	else {
		while (spot-1) {
			currNode = currNode->next;
			spot--;
		}
		node->next = currNode->next;
		currNode->next = node;
	}
	list->size++;
}

MoveNode *pullMove(MoveLL *list) {
	MoveNode *currNode = list->head;
	if (list->size == 0) {
		return NULL;
	}
	else if (list->size == 1) {
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		list->head = currNode->next; 
	}
	list->size--;
	return currNode;
}

void MoveLLInit(MoveLL *list, const char *moveDocList[8]) { 
	FILE *fp;
	int diff, type;
	char buff[255], prompt[200], name[30], answers[4][200], intermediate[10], correctAnswer[200], noun[15], adj[15], moveDocument[55];

	list->head = NULL;
	list->tail = NULL;	
	list->size = 0;

	for (int i = 0; i < 8; i++) {
		strcpy(moveDocument, moveDocList[i]);
		if (i == 0) {
			type = 1;
			strcpy(noun, "stab");
		}
		else if (i == 1) {
			type = 2;
			strcpy(noun, "slice");
		}
		else if (i == 2) {
			type = 3;
			strcpy(noun, "jab");
		}
		else if (i == 3) {
			type = 4;
			strcpy(noun, "thrust");
		}
		else if (i == 4) {
			type = 5;
			strcpy(noun, "assault");
		}
		else if (i == 5) {
			type = 6;
			strcpy(noun, "strike");
		}
		else if (i == 6) {
			type = 7;
			strcpy(noun, "cleave");
		}
		else if (i == 7) {
			type = 8;
			strcpy(noun, "slash");
		}

		fp = fopen(moveDocument, "r");

		if (fp == NULL) {
			printf("Error opening file\n");
			return;
		}
		while (fgets(buff, 255, (FILE*)fp)) {
			//This above fgets is a whitespace skip

			fgets(buff, 255, (FILE*)fp);
			//Gets rid of corresponding number

			fgets(buff, 255, (FILE*)fp);
			removeNewLine(prompt, buff);


			for (int i = 0; i<4; i++) {
				fgets(buff, 255, (FILE*)fp);
				removeNewLine(answers[i], buff);
				if (i==0) removeNewLine(correctAnswer, buff);
			}

			fgets(buff, 255, (FILE*)fp);
			pullNumber(intermediate, buff);
			diff = atoi(intermediate);

			if (diff == 1) strcpy(adj, "frail");
			else if (diff == 2) strcpy(adj, "weak");
			else if (diff == 3) strcpy(adj, "middling");
			else if (diff == 4) strcpy(adj, "sufficient");
			else if (diff == 5) strcpy(adj, "considerable");
			else if (diff == 6) strcpy(adj, "forceful");
			else if (diff == 7) strcpy(adj, "violent");
			else if (diff == 8) strcpy(adj, "brutal");
			else if (diff == 9) strcpy(adj, "merciless");
			else if (diff == 10) strcpy(adj, "herculean");

			sprintf(name, "%s %s", adj, noun);

			MoveNode *node = malloc(sizeof(MoveNode));
			MoveNodeInit(node, diff, correctAnswer, answers, prompt, name, type);
			addRandomSpot(list, node);
		}
	}
	fclose(fp);
}

#endif