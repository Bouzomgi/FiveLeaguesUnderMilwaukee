#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "aux.h"

#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
////////////////////////////////////////////////////////////////

typedef struct EnemyMoveNode {
	int successful;
	int movePower;
	char moveName[30];
	char moveDescription[200];
	char statRaise;
	struct EnemyMoveNode *next;
} EnemyMoveNode;

typedef struct EnemyMoveLL {
	int size;
	EnemyMoveNode *head;
	EnemyMoveNode *tail;
} EnemyMoveLL;

typedef struct Enemy {
  	char name[20];
  	int maxHealth;
  	int stats[3]; //health, attack, defense
  	EnemyMoveLL *bossAttacks;
} Enemy;

void MoveEnemyNodeInit(EnemyMoveNode *node, char name[30], char description[200], char stats, int power) {
	node->successful = 0;
	node->movePower = power;
	node->statRaise = stats;
	strcpy(node->moveName, name);
	strcpy(node->moveDescription, description);
}

void printEnemyLL(EnemyMoveLL *list) {
	EnemyMoveNode *currNode = list->head;
	for (int i = 0; i < list->size ;i++) {
		printf("%s\n", currNode->moveName);
		currNode = currNode->next;
	}
	printf("End\n\n");
}

void addRandomSpotEnemy(EnemyMoveLL *list, EnemyMoveNode *node) {
	int spot = rand() % (list->size + 1);
	EnemyMoveNode *currNode = list->head;

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
	list->size ++;
}


EnemyMoveNode *pullMoveEnemy(EnemyMoveLL *list) {
	EnemyMoveNode *currNode = list->head;
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
	list->size --;
	return currNode;
}

void initEnemy(Enemy *boss, char *name, int health) {
	strcpy(boss->name, name);
	boss->maxHealth = health;
	boss->stats[0] = health;
	for (int i = 1; i<3; i++) boss->stats[i] = 0;
}

void EnemyMoveLLInit(EnemyMoveLL *list, const char *moveDoc) {
	FILE *fp;
	int movePower, timesInserted;
	char buff[255], moveName[30], moveDescription[200], intermediate[200], stat;

	list->head = NULL;
	list->tail = NULL;	
	list->size = 0;

	fp = fopen(moveDoc, "r");

	if (fp == NULL) {
		printf("Error opening file\n");
		return;
	}

	while (fgets(buff, 255, (FILE*)fp)) {
		//This above fgets is a whitespace skip

		fgets(buff, 255, (FILE*)fp);
		removeNewLine(moveName, buff);

		fgets(buff, 255, (FILE*)fp);
		removeNewLine(moveDescription, buff);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		movePower = atoi(intermediate);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		stat = intermediate[0];

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		timesInserted = atoi(intermediate);

		for (int i = 0; i<timesInserted; i++) {
			EnemyMoveNode *node = malloc(sizeof(EnemyMoveNode));
			MoveEnemyNodeInit(node, moveName, moveDescription, stat, movePower);			
			addRandomSpotEnemy(list, node);
		}
	}
	fclose(fp);
}

void adjustBossStat(Enemy *boss, char stats) {
	if (stats == 'A') {
		boss->stats[1] += 2;
	}
	else if (stats == 'D') {
		boss->stats[2] += 2;
	}
}


#endif