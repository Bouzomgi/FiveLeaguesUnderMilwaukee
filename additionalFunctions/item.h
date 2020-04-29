#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "aux.h"

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
////////////////////////////////////////////////////////////////

typedef struct ItemNode {
	char name[30];
	char description[200];
	int stats[5]; //maxHealth, attack, defense, critical, dodge
	int cost;
	char type;
	struct ItemNode *next;
} ItemNode;

typedef struct ItemLL {
	int size;
	ItemNode *head;
	ItemNode *tail;
} ItemLL;

void printItemLL(ItemLL *list) {
	ItemNode *currNode = list->head;
	for (int i = 0; i < list->size ;i++) {
		printf("%s: %d\n", currNode->name, currNode->cost);
		currNode = currNode->next;
	}
	printf("End\n\n");
}

void addRandomSpotItem(ItemLL *list, ItemNode *node) {
	int spot = rand() % (list->size + 1);
	ItemNode *currNode = list->head;

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

ItemNode *pullItem(ItemLL *list) {
	ItemNode *currNode = list->head;
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

void itemNodeInit(ItemNode *node, char name[30], char itemDescription[200], int maxHealth, 
	int attack, int defense, int critical, int dodge, char itemType) {

	strcpy(node->name, name);
	strcpy(node->description, itemDescription);
	node->stats[0] = maxHealth;
	node->stats[1] = attack;
	node->stats[2] = defense;
	node->stats[3] = critical;
	node->stats[4] = dodge;
	node->cost = maxHealth/10 + attack + defense + critical + dodge*2.5;
	node->type = itemType;
	struct ItemNode *next;	
}

//List of 5 item LL
void itemLLInit(ItemLL *itemList, const char *itemDocument) {
	FILE *fp;
	int maxHealth, attack, defense, dodge, critical, rarity;
	char buff[255], name[30], description[200], intermediate[10], type;

	itemList->head = NULL;
	itemList->tail = NULL;
	itemList->size = 0;

	fp = fopen(itemDocument, "r");

	if (fp == NULL) {
		printf("Error opening file\n");
		return;
	}
	while (fgets(buff, 255, (FILE*)fp)) {
		//This above fgets is a whitespace skip

		fgets(buff, 255, (FILE*)fp);
		removeNewLine(name, buff);

		fgets(buff, 255, (FILE*)fp);
		removeNewLine(description, buff);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		maxHealth = atoi(intermediate);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		attack = atoi(intermediate);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		defense = atoi(intermediate);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		critical = atoi(intermediate);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		dodge = atoi(intermediate);

		fgets(buff, 255, (FILE*)fp);
		pullNumber(intermediate, buff);
		type = intermediate[0];

		ItemNode *node = malloc(sizeof(ItemNode));
		itemNodeInit(node, name, description, maxHealth, attack, defense, critical, dodge, type);
		addRandomSpotItem(itemList, node);	
	}
	fclose(fp);
}

//maxHealth, attack, defense, critical, dodge
void printItem(ItemNode *node, int shopping) {

	if (shopping) {
		if (node->type == 'W') {
			sprintf(dialogue, "%s\nAttack: %d\nCritical: %d\nDodge: %d",
				node->name, node->stats[1], node->stats[3], node->stats[4]);
		}
		else {
			sprintf(dialogue, "%s\nMaximum Health: %d\nAttack: %d\nDefense: %d\nCritical: %d\nDodge: %d", 
				node->name, node->stats[0], node->stats[1], node->stats[2], node->stats[3], node->stats[4]);
		}
	}
	else {
		if (node->type == 'W') {
			sprintf(dialogue, "%s\n%s\nAttack: %d\nCritical: %d\nDodge: %d\n",
				node->name, node->description, node->stats[1], node->stats[3], node->stats[4]);
		}
		else {
			sprintf(dialogue, "%s\n%s\nMaximum Health: %d\nAttack: %d\nDefense: %d\nCritical: %d\nDodge: %d\n", 
				node->name, node->description, node->stats[0], node->stats[1], node->stats[2], node->stats[3], node->stats[4]);
		}
	}
	print(dialogue);
}

#endif


