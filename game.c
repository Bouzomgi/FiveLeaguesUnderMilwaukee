#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <assert.h>
#include "additionalFunctions/boss.h"
#include "additionalFunctions/item.h"
#include "additionalFunctions/aux.h"
#include "additionalFunctions/moves.h"
#include "additionalFunctions/text.h"
#include "additionalFunctions/leaderboard.h"

//Secret word to skip tutorial
//Add leaderboard, badges, tells the player the right answer after answering incorrectly

//Move the first genmoney bc it is right before shop, not after beating salbert
//Couple grammar errors
//Changed layout

const char *moveDoc1 = "./questions/chpt1.txt";
const char *moveDoc2 = "./questions/chpt2.txt";
const char *moveDoc3 = "./questions/chpt3.txt";
const char *moveDoc4 = "./questions/chpt4.txt";
const char *moveDoc5 = "./questions/chpt5.txt";
const char *moveDoc6 = "./questions/chpt6.txt";
const char *moveDoc7 = "./questions/chpt7.txt";
const char *moveDoc8 = "./questions/chpt8.txt";

const char *itemDoc1 = "./itemsets/items1.txt";
const char *itemDoc2 = "./itemsets/items2.txt";
const char *itemDoc3 = "./itemsets/items3.txt";
const char *itemDoc4 = "./itemsets/items4.txt";

const char *MurrayDocument = "./movesets/murray.txt";
const char *CravenDocument = "./movesets/craven.txt";
const char *DoughlandDocument = "./movesets/doughland.txt";
const char *MilwuakeeJoeDocument = "./movesets/milwuakeeJoe.txt";

const char *recordsDoc = "./records.txt";

typedef struct Character {
	char name[20];
	int stats[5]; //health, attack, defense, critical, dodge
	int maxHealth;
	int level;
	int money;
	int combo;
	ItemNode *equipped[3]; //weapon, helmet, armor
	ItemNode *itemsOwned[10];

} Character;

void printStats(Character *);
int checkTitle(Character *);
void callForCombos();


//Initializes a character
void initPlayer(Character *player, char *name) {
	strcpy(player->name, name);
	player->maxHealth = 100;
	player->stats[0] = 100;
	for (int i=1; i<5; i++) player->stats[i] = 0;
	player->level = 0;
	player->money = 0;
	player->combo = 0;
	memset(player->itemsOwned, '\0', 10);
	memset(player->equipped, '\0', 10);

}

//Code for choosing a move. Scrapes off 4 random questions, lets you choose, one, then prompts you for the answer
MoveNode *chooseMove(MoveLL *moveList, const char *moveDocList[8]) {
	int moveChoice, answerChoice, indices[4];
	char userInput[64];
	MoveNode *chosenMove;
	MoveNode *moves[4];
	if (moveList->size < 4) {
		MoveLLInit(moveList, moveDocList);
	}
	for (int i=0; i<4; i++) {
		moves[i] = pullMove(moveList);
	}
	sprintf(dialogue, "Choose a move\n");
	print(dialogue);
	sprintf(dialogue, "%c%-30s%c%-30s\n%c%-30s%c%-30s\n", 
		toupper((moves[0]->moveName)[0]), (moves[0]->moveName)+1,
		toupper((moves[1]->moveName)[0]), (moves[1]->moveName)+1, 
		toupper((moves[2]->moveName)[0]), (moves[2]->moveName)+1, 
		toupper((moves[3]->moveName)[0]), (moves[3]->moveName)+1);
	print(dialogue);
	
	while(1) {
		fgets(userInput, 63,stdin);
		if (sscanf(userInput, "%d", &moveChoice) == 1) {
			if ((1 <= moveChoice) && (moveChoice <= 4)) break;

			if (moveChoice == 0) {
				sprintf(dialogue, "\nOrdering of question difficulty from easiest to hardest:\n  frail->weak->middling->sufficient->considerable->\n  forceful"
					"->violent->brutal->merciless->herculean\n\nCorresponding question styles:\n   %-9s%-30s   %-9s%-30s\n   %-9s%-30s"
					"   %-9s%-30s\n   %-9s%-30s   %-9s%-30s\n   %-9s%-30s   %-9s%-30s\n","stab:", "OS Introductions", "slice:",
					"OS Structures", "jab:", "Processes", "thrust:", "Threading", "assault:", "Process Synchronization", "strike:", 
					"Process Scheduling", "cleave:", "Memory Management", "slash:", "Virtual Memory");
				printColorSpeed(dialogue, 'y', 'N');
				sprintf(dialogue, "Choose a move\n");
				print(dialogue);
				sprintf(dialogue, "%c%-30s%c%-30s\n%c%-30s%c%-30s\n", 
					toupper((moves[0]->moveName)[0]), (moves[0]->moveName)+1,
					toupper((moves[1]->moveName)[0]), (moves[1]->moveName)+1, 
					toupper((moves[2]->moveName)[0]), (moves[2]->moveName)+1, 
					toupper((moves[3]->moveName)[0]), (moves[3]->moveName)+1);
				print(dialogue);
				continue;
			}

		}
		sprintf(dialogue, "Choose a valid number!\n");
		print(dialogue);
	}

	chosenMove = moves[moveChoice-1];
	for (int i=0; i<4; i++) {
		if (i != (moveChoice-1)) {
			addRandomSpot(moveList, moves[i]);
		}
	}
	sprintf(dialogue, "\n%s\n", chosenMove->movePrompt);
	print(dialogue);
	randomIndices(indices);

	sprintf(dialogue, "%s\n%s\n%s\n%s\n", chosenMove->answers[indices[0]], chosenMove->answers[indices[1]], 
		chosenMove->answers[indices[2]], chosenMove->answers[indices[3]]);
	print(dialogue);

	while(1) {
		fgets(userInput, 63,stdin);
		if (sscanf(userInput, "%d", &answerChoice) == 1) {
			if ((1 <= answerChoice) && (answerChoice <= 4)) {
				break;
			}
		}
		sprintf(dialogue, "Choose a valid number!\n");
		print(dialogue);
	}

	if (strcmp(chosenMove->answers[indices[answerChoice-1]], chosenMove->correctAnswer) == 0) {
		chosenMove->successful = 1;
		return chosenMove;
	}
	else {
		sprintf(dialogue, "\nD'oh! The answer was %s\n", chosenMove->correctAnswer);
		print(dialogue);
		return chosenMove;
	}
}

//Code for boss battles. The enemy will make a random move, then it will call makeMove(). If you hit, damage adjusters are added
int battle(const char *moveDocList[8], MoveLL *moveList, EnemyMoveLL *bossList, Character *player, Enemy *boss) {
	int damage, randMiss;
	EnemyMoveNode *bossMove;
	MoveNode *move;
	int playerDamage;
	while (boss->stats[0] > 0) {
		sprintf(dialogue, "Current health: %d / %d %40s's health: %d / %d \n", player->stats[0], player->maxHealth, boss->name, boss->stats[0], boss->maxHealth);
		print(dialogue);

		sleep(1);
		bossMove = pullMoveEnemy(bossList);
		addRandomSpotEnemy(bossList, bossMove);
		sprintf(dialogue, "%s\n", bossMove->moveDescription);
		print(dialogue);
		if (bossMove->movePower != 0) {
			if (dodgeAssert(player->stats[4])) {
				randMiss = rand()%3;
				if (randMiss == 0) sprintf(dialogue,"%s jumped out of the way!\n", player->name);
				else if (randMiss == 1) sprintf(dialogue,"%s dodged the attack!\n", player->name);		
				else if (randMiss == 2) sprintf(dialogue,"%s evaded the attack!\n", player->name);	
			}
			else {
				damage = bossMove->movePower * (1 + ((float)boss->stats[1] / 10));
				damage *= (1 - ((float)player->stats[2] / 20));
				sprintf(dialogue, "Did %d damage!\n", damage);
				player->stats[0] -= damage;
			}
			print(dialogue);
		}

		adjustBossStat(boss, bossMove->statRaise);
		sleep(1);

		if (player->stats[0] <= 0) {
			sleep(1);
			sprintf(dialogue, "...\n");
			print(dialogue);
			sleep(1);
			sprintf(dialogue, "...\n");
			print(dialogue);
			sleep(1);
			sprintf(dialogue, "...%s died to %s's %s...\n", player->name, boss->name, bossMove->moveName);
			print(dialogue);		

			sleep(1);
			loseGame();	
			return 0;
		}

		move = chooseMove(moveList, moveDocList);
		if (move->successful == 1) {
			damage = (move->movePower/2 + 30) * (1 + ((float)player->stats[1] / 10));

			//Critical hit
			if (player->stats[3] && rand()%9+1 <= player->stats[3]) {
				sprintf(dialogue, "Critical hit!");
				print(dialogue);
				damage *= 2;	
			}
			if (damage <= 50) sprintf(dialogue, "%s mananged a %s on %s, doing %d damage!\n", player->name, move->moveName, boss->name, damage);
			else if (damage <= 100) sprintf(dialogue, "%s preformed a %s on %s, hitting for %d damage!\n", player->name, move->moveName, boss->name, damage);
			else sprintf(dialogue, "%s mounted a %s, devastating %s for %d damage!\n", player->name, move->moveName, boss->name, damage);
			boss->stats[0] -= damage;

		}

		else {
			randMiss = rand()%3;
			if (randMiss==0) sprintf(dialogue, "%s whiffed!\n", player->name);
			else if (randMiss==1) sprintf(dialogue, "%s fumbled!\n", player->name);
			else if (randMiss==2) sprintf(dialogue, "%s missed!\n", player->name);
		}
		print(dialogue);
		free(move);
	}
	sprintf(dialogue, "%s has slain %s!", player->name, boss->name);
	print(dialogue);
	return 1;
}

//Prints all equipped items. If there is no item, shows a default one.
void printEquipped(Character *player) {
	ItemNode *baseWeapon = malloc(sizeof(ItemNode));
	ItemNode *baseHelmet = malloc(sizeof(ItemNode));
	ItemNode *baseArmor = malloc(sizeof(ItemNode));
	itemNodeInit(baseWeapon, "Razor Blade", "You managed to unscrew it from a pencil sharpener, but it wasn't even the good kind", 0,0,0,0,0,'W');
	itemNodeInit(baseHelmet, "Computer Science Degree", "You know how to make a Linked List", 0,0,0,0,0,'H');
	itemNodeInit(baseArmor, "Stained White Tee", "No wonder nobody respects you...", 0,0,0,0,0,'A');

	for (int i = 0; i<3; i++) {
		if (i==0) sprintf(dialogue, "WEAPON");
		else if (i==1) sprintf(dialogue, "HELMET");
		else if (i==2) sprintf(dialogue, "ARMOR");
		print(dialogue);

		if (player->equipped[i] == NULL) {
			if (i==0) printItem(baseWeapon, 0);
			else if (i==1) printItem(baseHelmet, 0);
			else if (i==2) printItem(baseArmor, 0);
		}
		else printItem(player->equipped[i], 0);
	}
	free(baseWeapon);
	free(baseHelmet);
	free(baseArmor);
}

//YOU CAN EQUIP AN ITEM AND IT CAN KILL YOU IF YOU DON'T HAVE ENOUGH HEALTH FROM HP DROP

//Allows the player to equipt an item to their equip slots
void equipItem(Character *player, ItemNode *item) {
	int index;
	if (item->type == 'W') index = 0;
	else if (item->type == 'H') index = 1;
	else if (item->type == 'A') index = 2;

	if (player->equipped[index] != NULL) {
		for (int i=0; i<5; i++) {
			player->stats[i] -= player->equipped[index]->stats[i];
		}
		player->maxHealth -= player->equipped[index]->stats[0];
		for (int i=0; i<10; i++) {
			if (player->itemsOwned[i] == NULL) {
				player->itemsOwned[i] = player->equipped[index];
				break;
			}
		}
	}
	
	for (int i=0; i<5; i++) {
		player->stats[i] += item->stats[i];
	}

	player->maxHealth += item->stats[0];
	player->equipped[index] = item;
}

//Salbert's store message prompt
void shopPrompt(Character *player, ItemNode *storeList[2], int stock[3]) { 
	sprintf(dialogue, "CURRENT CASH: %d bucks\nCURRENT HEALTH: %d / %d\n", player->money, player->stats[0], player->maxHealth);
	print(dialogue);

	for (int i=0; i<2; i++) {
		sprintf(dialogue, "ITEM %d", i+1);
		print(dialogue);
		if (stock[i]) {
			printItem(storeList[i], 1);
			sprintf(dialogue, "Cost: %d bucks\n", storeList[i]->cost);
		}
		else sprintf(dialogue, "SOLD OUT\n");
		print(dialogue);
	}

	if (stock[2]) {
		sprintf(dialogue, "ITEM 3\nBubble Tea\nDamn, it's delicious. Consume it right away to restore all of your health\nCost: 5 bucks");

	}
	else sprintf(dialogue, "SOLD OUT\n");
	
	print(dialogue);
	sprintf(dialogue, "\n[4] LEAVE\n");
	print(dialogue);
}

//Salbert's store. Allows the player to buy items.
void shop(Character *player, ItemLL *masterItemList[4]) {
	char userInput[64];
	int decision, stock[3] = {1,1,1};

	ItemNode *storeList[2];
	for (int i=0; i<2; i++) storeList[i] = pullItem(masterItemList[player->level-1]);

	sprintf(dialogue, "IT'S A ONE STOP SHOP BUDDY. BUY AN ITEM IF YOU HAVE THE COIN, OR GET OUT");
	printColorSpeed(dialogue, 'R', 'N');

	shopPrompt(player, storeList, stock);

	while(1) {
		fgets(userInput, 63,stdin);
		if (sscanf(userInput, "%d", &decision) == 1) {
			if ((1 <= decision) && (decision <= 3) && (stock[decision-1] == 0)) {
				sprintf(dialogue, "CAN'T YOU READ? THAT ITEM IS SOLD OUT!!!\n");
				printColorSpeed(dialogue, 'R', 'N');
				continue;
			}
			else if (decision == 1 || decision == 2) {
				if (player->money >= storeList[decision-1]->cost) {
					stock[decision-1] = 0;
					equipItem(player, storeList[decision-1]);
					player->money -= storeList[decision-1]->cost;
					sprintf(dialogue, "You have purchased and equipped the %s\n\n", storeList[decision-1]->name);
					print(dialogue);
					shopPrompt(player, storeList, stock);
				}
				else {
					sprintf(dialogue, "YOU DON'T HAVE THE MONEY...? AHHHHHH!!!\n");
					printColorSpeed(dialogue, 'R', 'N');
				}
				continue;
			}
			else if (decision == 3) {
				if (player->money >= 5) {
					stock[decision-1] = 0;
					sprintf(dialogue, "...");
					print(dialogue);
					sleep(1);
					player->stats[0] = player->maxHealth;
					player->money -= 5;
					sprintf(dialogue, "You chugged the bubble tea. You wonder if you'd look foolish if you ordered one with just tapioca pearls"
					" next time...\nYour health is fully restored!\n\n");
					print(dialogue);
					shopPrompt(player, storeList, stock);
				}
				else {
					sprintf(dialogue, "YOU DON'T HAVE THE MONEY...? AHHHHHH!!!\n");
					printColorSpeed(dialogue, 'R', 'N');
				}
				continue;
			}
			else if (decision == 4) {
				sprintf(dialogue, "AIGHT! GET OUT AND STAY OUT!\n");
				printColorSpeed(dialogue, 'R', 'N');
				break;
			}				
		}
		sprintf(dialogue,"THAT AIN'T AN OPTION!");
		printColorSpeed(dialogue, 'R', 'N');
	}	
}


//Salbert's store message prompt
void tutorialShopPrompt(Character *player, ItemNode *storeList[2], int stock[2]) { 
	sprintf(dialogue, "CURRENT CASH: %d bucks\nCURRENT HEALTH: %d / %d\n", player->money, player->stats[0], player->maxHealth);
	print(dialogue);

	for (int i=0; i<2; i++) {
		sprintf(dialogue, "ITEM %d", i+1);
		print(dialogue);
		if (stock[i]) {
			printItem(storeList[i], 1);
			sprintf(dialogue, "Cost: %d bucks\n", storeList[i]->cost);
		}
		else sprintf(dialogue, "SOLD OUT\n");
		print(dialogue);
	}
	
	sprintf(dialogue, "\n[3] LEAVE\n");
	print(dialogue);
}

//Salbert's store. Allows the player to buy items.
void tutorialShop(Character *player, ItemLL *masterItemList[4]) {
	char userInput[64];
	int decision, stock[2] = {1,1};

	ItemNode *storeList[2];
	for (int i=0; i<2; i++) storeList[i] = pullItem(masterItemList[player->level-1]);

	sprintf(dialogue, "IT'S A ONE STOP SHOP BUDDY. BUY AN ITEM IF YOU HAVE THE COIN, OR GET OUT");
	printColorSpeed(dialogue, 'R', 'N');

	tutorialShopPrompt(player, storeList, stock);

	while(1) {
		fgets(userInput, 63,stdin);
		if (sscanf(userInput, "%d", &decision) == 1) {
			if ((1 <= decision) && (decision <= 2) && (stock[decision-1] == 0)) {
				sprintf(dialogue, "CAN'T YOU READ? THAT ITEM IS SOLD OUT!!!\n");
				printColorSpeed(dialogue, 'R', 'N');
				continue;
			}
			else if (decision == 1 || decision == 2) {
				if (player->money >= storeList[decision-1]->cost) {
					stock[decision-1] = 0;
					equipItem(player, storeList[decision-1]);
					player->money -= storeList[decision-1]->cost;
					sprintf(dialogue, "You have purchased and equipped the %s\n\n", storeList[decision-1]->name);
					print(dialogue);
					tutorialShopPrompt(player, storeList, stock);
				}
				else {
					sprintf(dialogue, "YOU DON'T HAVE THE MONEY...? AHHHHHH!!!\n");
					printColorSpeed(dialogue, 'R', 'N');
				}
				continue;
			}
			else if (decision == 3) {
				sprintf(dialogue, "\nAIGHT! GET OUT AND STAY OUT!\n");
				printColorSpeed(dialogue, 'R', 'N');
				break;
			}				
		}
		sprintf(dialogue,"THAT AIN'T AN OPTION!");
		printColorSpeed(dialogue, 'R', 'N');
	}
	if (checkTitle(player) && player->combo == 0) callForCombos();
}


//Propt displayed for inventory check
int inventoryPrompt(Character *player) {
	if (player->itemsOwned[0] == NULL) {
		sprintf(dialogue, "You don't have anything. Purchase items from Salbert's shop\n");
		print(dialogue);
		return 0;
	}
	sprintf(dialogue, "Select an item to equip it\n\n[0] EXIT\n");
	print(dialogue);

	for (int i=0; i<10; i++) {
		if (player->itemsOwned[i] == NULL) {
			continue;
		}
		sprintf(dialogue, "ITEM %d", i+1);
		print(dialogue);
		printItem(player->itemsOwned[i], 0);
		puts("\n");
	}
	return 1;
}

//pPrompt displayed for equiping an item.
void inventory(Character *player) {
	char userInput[64];
	int hasItems, decision;
	ItemNode *item;

	hasItems = inventoryPrompt(player);
	if (!hasItems) return;
	
	while(1) {
		fgets(userInput, 63,stdin);
		if (sscanf(userInput, "%d", &decision) == 1 && (0 < decision) && (decision <= 10) &&(player->itemsOwned[decision-1] != NULL)) {
			item = player->itemsOwned[decision-1];
			player->itemsOwned[decision-1] = NULL;
			equipItem(player, item);
			sprintf(dialogue, "%s has been equipped\n", item->name);
			print(dialogue);
			inventoryPrompt(player);
			continue;
		}
		else if (decision == 0) {
			return;
		}
		sprintf(dialogue, "That's not an option!");
		print(dialogue);

	}
}

//Prompt displayed for showing player's stats
void printStats(Character *player) {
	sprintf(dialogue, "Name: %s\nMaximum Health: %d\nCurrent Health: %d\nAttack: %d\nDefense: %d\nCritical: %d\nDodge: %d\nMoney: %d bucks\n", 
		player->name, player->maxHealth, player->stats[0], player->stats[1], player->stats[2], player->stats[3], player->stats[4], player->money);
	print(dialogue);
}

int checkTitle(Character *player) {
	int cbwarrior = 0; //cardboard helmet, cardboard armor
	int multimeaning = 0; // chingus mace, bucket hat, sharpened shovel
	int sneaky = 0; //balaclava, gi
	int lamewarlord = 0; //broken stick, warlord cap
	int chillin = 0; //costco parka, iced pick
	int multiera = 0; //bayonet, chainmail, lightsaber
	int terrifying = 0; //gas mask, cleaver, bonecrusher

	for (int i=0; i<3; i++) {
		if (player->equipped[i] != NULL) {
			if (strcmp(player->equipped[i]->name, "Cardboard Helmet") == 0) cbwarrior++;
			else if (strcmp(player->equipped[i]->name, "Cardboard Armor") == 0) cbwarrior++;
			else if (strcmp(player->equipped[i]->name, "Chingus's Mace") == 0) multimeaning++;
			else if (strcmp(player->equipped[i]->name, "Bucket Hat") == 0) multimeaning++;
			else if (strcmp(player->equipped[i]->name, "Sharpened Shovel") == 0) multimeaning++;
			else if (strcmp(player->equipped[i]->name, "Balaclava") == 0) sneaky++;
			else if (strcmp(player->equipped[i]->name, "Gi") == 0) sneaky++;
			else if (strcmp(player->equipped[i]->name, "Broken Stick") == 0) lamewarlord++;
			else if (strcmp(player->equipped[i]->name, "Warlord Cap") == 0) lamewarlord++;
			else if (strcmp(player->equipped[i]->name, "COSTCO Parka") == 0) chillin++;
			else if (strcmp(player->equipped[i]->name, "Iced Pick") == 0) chillin++;
			else if (strcmp(player->equipped[i]->name, "Bayonet") == 0) multiera++;
			else if (strcmp(player->equipped[i]->name, "Chainmail") == 0) multiera++;
			else if (strcmp(player->equipped[i]->name, "Lightsaber") == 0) multiera++;
			else if (strcmp(player->equipped[i]->name, "M50A1 Gas Mask") == 0) terrifying++;
			else if (strcmp(player->equipped[i]->name, "Rusted Butcher Cleaver") == 0) terrifying++;
			else if (strcmp(player->equipped[i]->name, "Bonecrusher") == 0) terrifying++;
		}
	}

	if (cbwarrior >= 2) return 1;
	else if (multimeaning >= 2) return 2;
	else if (sneaky >= 2) return 3;
	else if (lamewarlord >= 2) return 4;
	else if (chillin >= 2) return 5;
	else if (multiera >= 2) return 6;
	else if (terrifying >= 2) return 7;
	else return 0;	
}

void printTitle(Character *player) {

	int titleType = checkTitle(player);

	if (titleType == 1) {
		sprintf(dialogue, "Cardboard Warrior\n\nDonning both armor and helm of the board, you have ascended beyond mere mortals. "
			"Salbert is secretly incredibly jealous of you.\n");
	}
	else if (titleType == 2) {
		sprintf(dialogue, "Multidimensional Master\n\nMultifaceted multitools maintaining much meaning.\n");
	}
	else if (titleType == 3) {
		sprintf(dialogue, "Sneeeeeaky\n\nWhoa there, you sure you wanna wear that stuff? Aren't you worried about scaring Milwuakee Joe? No? Alright then.\n");
	}
	else if (titleType == 4) {
		sprintf(dialogue, "Lame Warlord\n\nWhat kind of warlord carries around a broken stick as a weapon...? I mean you made it this far, so I guess "
			"just keep on going then.\n");
	}
	else if (titleType == 5) {
		sprintf(dialogue, "Cool Guy\n\nIce is nice. Some freeze is the bees knees. You're chillin' like a villian... wait... aren't "
			"you supposed to be the hero?\n");
	}
	else if (titleType == 6) {
		sprintf(dialogue, "Cosplay Freak\n\nYo, what the hell are you wearing? That doesn't match at all, like, that outfit is generations apart. "
			"Your style intelligence is concerning...\n");
			
	}
	else if (titleType == 7) {
		sprintf(dialogue, "Terror of the Night\n\nWhat's the point of the game if you look scarier than Milwuakee Joe? Are you trying to give "
			"Salbert nightmares?!?\n");		
	}
	else {
		sprintf(dialogue, "Looks like you don't have any impressive gear combinations. Try buying more items from Salbert...\n");
		printColorSpeed(dialogue, 'X', 'N');
		return;
	}
	
	printColorSpeed(dialogue, 'X', 'N');
	if (player->combo == 0) {
		sprintf(dialogue, "\nYour attack stat has been permanently raised by 2.\n");	
		printColorSpeed(dialogue, 'X', 'N');
		player->stats[1] += 2;
		player->combo++;
	}
	return;
}

void callForCombos() {
	sleep(1);
	sprintf(dialogue, "...HEY KID! CHECK YER COMBO PAGE!\n");
	printColorSpeed(dialogue, 'R', 'N');
	sleep(1);
}	

//Prompt displayed as a menu between each level
void betweenLevels(Character *player, ItemLL *masterItemList[4]) {
	char decision[20], userInput[64];
	int shopped = 0;

	while(1) {
		sprintf(dialogue, "NOW WHAT?\n");
		printColorSpeed(dialogue, 'R', 'N');
		fgets(userInput, 20, stdin);
		if (sscanf(userInput, "%s", decision) == 1) {
			if (strcmp(decision, "fight") == 0) break;
			else if (strcmp(decision, "shop") == 0) {
				if (!shopped) { 
					puts("\n");
					shop(player, masterItemList);
					shopped++;
					if (checkTitle(player) && player->combo == 0) callForCombos();
				}
				else {
					sprintf(dialogue, "\nNO. YOU SHOP ONCE, THEN YOU'RE DONE.\n");
					printColorSpeed(dialogue, 'R', 'N');
				}
				continue;
			}

			else if (strcmp(decision, "equipped") == 0) {
				puts("\n");
				printEquipped(player);
				if (checkTitle(player) && player->combo == 0) callForCombos();
				continue;
			}
			else if (strcmp(decision, "inv") == 0) {
				puts("\n");
				inventory(player);
				continue;
			}
			else if (strcmp(decision, "stats") == 0) {
				puts("\n");
				printStats(player);
				continue;				
			}
			else if (strcmp(decision, "combos") == 0) {
				puts("\n");
				printTitle(player);
				continue;				
			}
			else if (strcmp(decision, "help") == 0) {
				puts("\n");
				sprintf(dialogue, "\nWELL, BUDDY, YA COULD...\n   %-10sCHECK OUR YER ITEMS ON YER BODY\n   %-10sSWAP AROUND YER ITEMS\n   %-10s"
					"VIEW YER STATS\n   %-10sBROWSE ME SHOP\n   %-10sSEE YER ITEM COMBOS\n   %-10sMOVE ON TO THE NEXT FLOOR\n   %-10sRECURSION\n",
					"equipped:", "inv:", "stats:", "shop:", "combos:", "fight:", "help:");
				printColorSpeed(dialogue, 'R', 'N');
				continue;
			}
		}
		sprintf(dialogue, "THAT'S NOT AN OPTION, FOOL!");
		printColorSpeed(dialogue, 'R', 'N');
	}
}

//Gives the player money
void genMoney(Character *player) {
	int winnings; 
	player->level++;
	winnings = (3*player->level) + (rand()%(player->level + 2));
	player->money += winnings;
	sprintf(dialogue, "\nYou won %d bucks from that victory.\n", winnings);
	printColorSpeed(dialogue, 'X', 'N');
	sleep(1);

}

//The actual game. I wrote it here pretty linearly
int main() {

	time_t start;
    time_t t = time(NULL);

	const char *moveDocList[8] = {moveDoc1, moveDoc2, moveDoc3, moveDoc4, moveDoc5, moveDoc6, moveDoc7, moveDoc8};
	const char *itemDocList[4] = {itemDoc1, itemDoc2, itemDoc3, itemDoc4};
	int skip;
	char name[20];

	MoveLL *moveList = malloc(sizeof(MoveLL));
	EnemyMoveLL *murrayList = malloc(sizeof(EnemyMoveLL));
	EnemyMoveLL *cravenList = malloc(sizeof(EnemyMoveLL));
	EnemyMoveLL *doughlandList = malloc(sizeof(EnemyMoveLL));
	EnemyMoveLL *milwuakeeJoeList = malloc(sizeof(EnemyMoveLL));


	Character *player = malloc(sizeof(Character));
	Enemy *murray = malloc(sizeof(Enemy));
	Enemy *craven = malloc(sizeof(Enemy));
	Enemy *doughland = malloc(sizeof(Enemy));
	Enemy *milwuakeeJoe = malloc(sizeof(Enemy));

	srand(time(0));

	EnemyMoveLLInit(murrayList, MurrayDocument);
	EnemyMoveLLInit(cravenList, CravenDocument);
	EnemyMoveLLInit(doughlandList, DoughlandDocument);
	EnemyMoveLLInit(milwuakeeJoeList, MilwuakeeJoeDocument);

	MoveLLInit(moveList, moveDocList);

	ItemLL *masterItemList[4];
	for (int i=0; i<4; i++) {
		masterItemList[i] = (ItemLL *)malloc(sizeof(ItemLL));
		itemLLInit(masterItemList[i], itemDocList[i]);
	}

	initEnemy(murray, "Lowlife Murray", 100);
	initEnemy(craven, "The Craven", 125);
	initEnemy(doughland, "Mike McDoughland", 160);
	initEnemy(milwuakeeJoe, "Milwaukee Joe", 200);

	system("clear");


	skip = taitle();
    time(&start); //starts our timer

	if (!skip) {
		wakeUp(name);
	 	salbertTutorial(name);
	 	initPlayer(player, name);
	 	genMoney(player);
	 	afterTutorial();
	 	tutorialShop(player, masterItemList);
	 	staircaseMurray();
	}
	else {
		askName(name);
		initPlayer(player, name);
		genMoney(player);
		tutorialShop(player, masterItemList);
	}

	if (!battle(moveDocList, moveList, murrayList, player, murray)) return 0;
	genMoney(player);
	afterMurray();
	betweenLevels(player, masterItemList);
	staircaseCraven();
	if (!battle(moveDocList, moveList, cravenList, player, craven)) return 0;
	genMoney(player);
	afterCraven();
	betweenLevels(player, masterItemList);
	staircaseDoughland();
	if (!battle(moveDocList, moveList, doughlandList, player, doughland)) return 0;
	genMoney(player);
	afterDoughland();
	betweenLevels(player, masterItemList);
	staircaseMiluakeeJoe(name);
	if (!battle(moveDocList, moveList, milwuakeeJoeList, player, milwuakeeJoe)) return 0;
	ending();

	time_t end;
    time(&end);
	writeToRecords(recordsDoc, difftime(end, start));
	return 1;
}

