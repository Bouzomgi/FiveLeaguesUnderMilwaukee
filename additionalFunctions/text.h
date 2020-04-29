#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "aux.h"

#ifndef ASCII_H_INCLUDED
#define ASCII_H_INCLUDED
////////////////////////////////////////////////////////////////

char extraDialogue[10000];

	const char *five = 
	"  ______   __     __   __   ______    \n"
	" /\\  ___\\ /\\ \\   /\\ \\ / /  /\\  ___\\   \n"
	" \\ \\  __\\ \\ \\ \\  \\ \\  \'/   \\ \\  __\\   \n"
	"  \\ \\_\\    \\ \\_\\  \\ \\__|    \\ \\_____\\  \n"
	"   \\/_/     \\/_/   \\/_/      \\/_____/  \n";


	const char *leagues = 
	"  __         ______     ______     ______     __  __     ______     ______    \n"
	" /\\ \\       /\\  ___\\   /\\  __ \\   /\\  ___\\   /\\ \\/\\ \\   /\\  ___\\   /\\  ___\\   \n"
	" \\ \\ \\____  \\ \\  __\\   \\ \\  __ \\  \\ \\ \\__ \\  \\ \\ \\_\\ \\  \\ \\  __\\   \\ \\___  \\   \n"
	"  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\/\\_____\\   \n"
	"   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/   \\/_____/   \n";


	const char *under = 

	"  __  __     __   __     _____     ______     ______    \n"
	" /\\ \\/\\ \\   /\\ \"-.\\ \\   /\\  __-.  /\\  ___\\   /\\  == \\   \n"
	" \\ \\ \\_\\ \\  \\ \\ \\-.  \\  \\ \\ \\/\\ \\ \\ \\  __\\   \\ \\  __<   \n"
	"  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\ \\____-  \\ \\_____\\  \\ \\_\\ \\_\\ \n"
	"   \\/_____/   \\/_/ \\/_/   \\/____/   \\/_____/   \\/_/ /_/ \n";


	const char *milwuakee =                                                                                     
	"  __    __   __   __       __     __   __  __   ______   __  __   ______   ______   \n" 
	" /\\ \"-./  \\ /\\ \\ /\\ \\     /\\ \\  _ \\ \\ /\\ \\/\\ \\ /\\  __ \\ /\\ \\/ /  /\\  ___\\ /\\  ___\\ \n"  
	" \\ \\ \\-./\\ \\\\ \\ \\\\ \\ \\____\\ \\ \\/ \".\\ \\\\ \\ \\_\\ \\\\ \\  __ \\\\ \\  _\"-.\\ \\  __\\ \\ \\  __\\ \n"  
	"  \\ \\_\\ \\ \\_\\\\ \\_\\\\ \\_____\\\\ \\__/\".~\\_\\\\ \\_____\\\\ \\_\\ \\_\\\\ \\_\\ \\_\\\\ \\_____\\\\ \\_____\\ \n" 
	"   \\/_/  \\/_/ \\/_/ \\/_____/ \\/_/   \\/_/ \\/_____/ \\/_/\\/_/ \\/_/\\/_/ \\/_____/ \\/_____/ ";
                                                                                                                                                                        
	                                                                                    


	const char *box = 

	"                  ____.----'`--.__                     \n"
	"         ___.----'                `--.____             \n"
	"       /`-._                        __.-' \\            \n"
	"      /     `-._            ___.---'       \\           \n"
	"     /          `-.____.---'                \\          \n"
	"    /            / | \\                       \\         \n"
	"   /            /  |  \\                   _.--'        \n"
	"   `-.         /   |   \\            __.--'             \n"
	"      `-._    /    |    \\     __.--'     |             \n"
	"        | `-./     |     \\_.-'           |             \n"
	"        |          |                     |             \n"
	"        |          |                     |             \n"
	"        |          |                     |             \n"
	"        |          |                     |             \n"
	"        |          |                     |             \n"
	"        |          |                     |             \n"
    " _______|          |                     |_____________\n"
	"        `-.        |                  _.-'             \n"
	"           `-.     |           __..--'                 \n"
	"              `-.  |      __.-'                        \n"
	"                 `-|__.--'                             \n";


	const char *stairs =

	"		 _____________________________________             \n"
	"		 |                           |\"b,    \"Ya           \n"
	"		 |                           |  \"b,    \"Ya         \n"
	"		 |                    _______|    \"b,    \"Ya        \n"
	"		 |                    |\"b,    \"Ya   \"|\"\"\"\"\"\"|      \n"
	"		 |                    |  \"b,    \"Ya  |      |      \n"
	"		 |               _____|,   \"b,    \"Ya|      |      \n"
	"		 |              |b,    \"Ya   \"|\"\"\"\"\"\"\"      |      \n"
	"		 |              | \"b,    \"Ya  |             |      \n"
	"		 |       _______|   \"b,    \"Ya|             |      \n"
	"		 |      |\"b,    \"Ya   \"|\"\"\"\"\"\"\"             |      \n"
	"		 |      |  \"b,    \"Ya  |                    |      \n"
	"		 |______|,   \"b,    \"Ya|                    |      \n"
	"		 |\"b,    \"Ya   \"|\"\"\"\"\"\"\"                    |      \n"
	"		 |  \"b,    \"Ya  |                           |      \n"
	"		 |,   \"b,    \"Ya|                           |      \n"
	"		  \"Ya   \"|\"\"\"\"\"\"\"                           |      \n"
	"		    \"Ya  |                                  |      \n"
	"		      \"Ya|                                  |      \n"
	"		        \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"      \n";




	const char *the =

	"	 ______   __  __     ______      \n"
	"	/\\__  _\\ /\\ \\_\\ \\   /\\  ___\\     \n"
	"	\\/_/\\ \\/ \\ \\  __ \\  \\ \\  __\\     \n"
	"	   \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\   \n"
	"	    \\/_/   \\/_/\\/_/   \\/_____/   ";
	

	const char *end = 
	
	"	 ______     __   __     _____     \n"
	"	/\\  ___\\   /\\ \"-.\\ \\   /\\  __-.   \n"
	"	\\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\/\\ \\  \n"
	"	 \\ \\_____\\  \\ \\_\\\"\\_\\  \\ \\____-  \n"
	"	  \\/_____/   \\/_/ \\/_/   \\/____/  ";
		                                 

	
	const char *you = 
	
	"	 __  __     ______     __  __       \n"       
	"	/\\ \\_\\ \\   /\\  __ \\   /\\ \\/\\ \\      \n"        
	"	\\ \\____ \\  \\ \\ \\/\\ \\  \\ \\ \\_\\ \\     \n"      
	"	 \\/\\_____\\  \\ \\_____\\  \\ \\_____\\    \n"       
	"	  \\/_____/   \\/_____/   \\/_____/    ";        
		                                            
	
	const char *lose =
	
	"	 __         ______     ______     ______    \n"
	"	/\\ \\       /\\  __ \\   /\\  ___\\   /\\  ___\\   \n"
	"	\\ \\ \\____  \\ \\ \\/\\ \\  \\ \\___  \\  \\ \\  __\\   \n"
	"	 \\ \\_____\\  \\ \\_____\\  \\/\\_____\\  \\ \\_____\\ \n"
	"	  \\/_____/   \\/_____/   \\/_____/   \\/_____/ ";
		                                            

	const char *highscores = 

	"  __  __   __       ______   ______   ______   ______   ______   ______    \n"
	" /\\ \\_\\ \\ /\\ \\     /\\  ___\\ /\\  ___\\ /\\  __ \\ /\\  == \\ /\\  ___\\ /\\  ___\\   \n"
	" \\ \\  __ \\\\ \\ \\    \\ \\___  \\\\ \\ \\____\\ \\ \\/\\ \\\\ \\  __< \\ \\  __\\ \\ \\___  \\  \n"
	"  \\ \\_\\ \\_\\\\ \\_\\    \\/\\_____\\\\ \\_____\\\\ \\_____\\\\ \\_\\ \\_\\\\ \\_____\\\\/\\_____\\ \n"
	"   \\/_/\\/_/ \\/_/     \\/_____/ \\/_____/ \\/_____/ \\/_/ /_/ \\/_____/ \\/_____/ \n";
                                                                          



int title() {
	int val;
	char decision[20], userInput[64];
	system("clear");
	sprintf(extraDialogue, "\n%s\n%s\n%s\n%s\n", five, leagues, under, milwuakee);
	printColorSpeed(extraDialogue, 'Y', 'F');
	sleep(1);
	sprintf(dialogue, "Please resize your console window to appropriately fit all text currently on screen\nPress any button to start");
	print(dialogue);
	fgets(userInput, 19, stdin);
	if (sscanf(userInput, "%s", decision) == 1 && (strcmp(decision, "CMPSC473") == 0)) val = 1;
	else val = 0;
	system("clear");
	return val;
}


void wakeUp(char name[20]) {


	char decision[20], userInput[64];

	for (int i=0;i<2;i++){
		sleep(1);
		sprintf(dialogue, "...\n");
		printColorSpeed(dialogue, 'X', 'S');
	}
	sleep(2);
	sprintf(dialogue, "Wha... what is going on.....?\nYou sit up from the cold, concrete ground, hoping your head will "
		"stop ringing.");
	printColorSpeed(dialogue, 'X', 'S');
	sleep(2);
	sprintf(dialogue, "\nIt all comes back to you now. You're an average person, just turned 21 last month. You've lived in Milwaukee "
		"all your life... you grew up off the Lower East side, in an apartment right above an old Mom 'n Pop ice cream store. Your "
		"favorite flavor was...");
	printColorSpeed(dialogue, 'X', 'R');
	sleep(1);
	sprintf(dialogue, "\nuhhhh...\n");
	printColorSpeed(dialogue, 'X', 'S');
	sleep(2);
	sprintf(dialogue, "Dairy-free Moose Tracks! You loved dairy-free Moose Tracks! It always reminded you of your favorite Uncle Tom, "
		"who gave you a scoop after school most weekdays as you two watched TV.");
	printColorSpeed(dialogue, 'X', 'R');
	sleep(1);
	sprintf(dialogue, "\nBut that was before the accident...");
	printColorSpeed(dialogue, 'X', 'R');
	sleep(2);		
	sprintf(dialogue, "\nWhen you were 12, your Uncle left for work one day. He never came back home. The police found his body three "
		"weeks later in the Milwaukee River floating face down. Then... your sister... she called you from the supermarket asking if "
		"you had enough milk. Two hours pass, and the cops are calling your cellphone in preparation for her funeral. One-by-one, "
		"year-by-year, your family was taken away from you.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nThe detectives called it the work of the greatest serial killer in the "
		"tri-state area. They knew nothing about him, but they all just referred to him by the name Milwaukee Joe. Rumors flooded the "
		"papers: He was a cannabal! He lived under the sewers! HE WAS THE MAYOR! No one really had any idea what to believe, so they "
		"just believed it all...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(3);	
	sprintf(dialogue, "\nYou shake a little bit. It's cold down here... \nYou scan the room. It looks like a basement of some kind, "
		"with concrete on all six sides. On the far-end of the room you spot a staircase going upwards. \nOther than that, the room is "
		"completely empty...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\n\nexcept...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n\nYou look behind you and see a massive cardboard box. Boxes that big only come "
		"from refrigerators or something...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);	
	sprintf(extraDialogue, "\n%s\n", box);
	printColorSpeed(extraDialogue, 'y', 'F');

	sleep(2);
	sprintf(dialogue, "You kick the box with your foot, because kicking things is fun.");	
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n", "HEY!!!", "QUIT KICKIN ME BODEGA!!!");	
	printColorSpeed(dialogue, 'R', 'N');	
	
	sleep(1);
	sprintf(dialogue, "From the box arises a scrawny 30ish year old man with thin moustache, tattered fez, and leather armor that, "
		"from the fraying, seems to have been in a washing machine. He looked as if he just walked out of Comic-Con...");	
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s", "THE HELL YOU WANT??");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\nYou tell him your situation. He laughs. You ask him his name.");	
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s", "SALBERT", "I HATE MY PARENTS. WHO NAMES THEIR KID SALBERT???");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\nYou chuckle.");	
	print(dialogue);

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n", "YEW THINK THAT'S FUNNY?", " AND YER NAME IS...?");	
	printColorSpeed(dialogue, 'R', 'N');

	while(1) {
		fgets(userInput, 19, stdin);
		if (sscanf(userInput, "%s", name) == 1) break;

		else {
			sprintf(dialogue, "%85s\n", "THAT AIN'T A NAME!!!");	
			printColorSpeed(dialogue, 'R', 'N');
		}
	}
	sleep(1);
	sprintf(dialogue, "\n%84s?\n%85s", name, "NOW THAT'S A FUNNY NAME!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s\n%85s", 
		"NOW LISTEN HERE SON.",
	 	"DUNNO HOW YE GOT DOWN HERE BUT I DON'T HAVE TIME TO DEAL WITH YE", 
		"THIS PLACE HERE'S THE SCUM OF THE EARTH.",
		"WE CALL IT TAR-DEN.", 
		"THIS HERE'S WHERE THE CRIMINALS OF POOR OL' MILUAKEE RESIDE.");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\nYou immediately feel pangs of worry. \nYou ask him who in particular lives down here...");	
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s", "YOU SAID YER FROM THIS CITY. YE DON'T KNOW A SINGLE THIEF???");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\n...");	
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nYou slowly utter the name of the murderer that you lived in fear of your entire life...");	
	printColorSpeed(dialogue, 'X', 'S');

	sleep(2);
	sprintf(extraDialogue, "\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s", 
		"MILUAKEE JOE? DAMN I HATE THAT MILUAKEE JOE.", 
		"THAT GUY IS A WORTHLESS BRAINDEAD SCUMFACE PILE OF TRASH",
		"THAT SHOULD BE OBLITERATED LIKE THE DEGENERATE HE IS.",
		"THIS GUY KNOWS NOTHING ABOUT BASKETBALL. ABSOLUTELY NOTHING.", 
		"I WOULDN'T HIRE HIM TO TEACH A FOURTH GRADER HOW TO DRIBBLE.", 
		"IF YOU KNEW ANYTHING ABOUT THE BUCKS YOU'D KNOW HOW GOD",
		"AWFUL THAT KAREEM ADBUL-JABBAR WAS.", 
		"THAT IDIOT JABBAR RUINED THE BUCKS FOR 6 YEARS.", 
		"6 WHOLE YEARS. WHEN THAT IMBECILE MILUAKEE JOE TOLD ME HE WAS", 
		"HIS FAVORITE PLAYER, I LEGITIMATELY", 
		"WENT INTO ANAPHYLACTIC SHOCK AND ALMOST DIED.",
		"THAT GUY.... AHHHHHHHHHHHHHHHHHHH");	
	printColorSpeed(extraDialogue, 'R', 'N');
	sleep(4);

	sprintf(dialogue, "\nSalbert goes completely berserk, raving about how awful Kareem Abdul-Jabbar is for an additional half hour.");	
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\n%85s\n%85s", "YE KNOW WHAT?", "YE SAY YOU HATE HIM TOO?");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\nYou nod.");	
	print(dialogue);

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s\n%85s",
	 "THAT SETTLES IT. YER GONNA TAKE HIM OUT.", 
	 "THIS BASEMENT EXTENDS UP FOUR MORE LEVELS,",
	 "WITH EACH HOUSING SOME OTHER CREEP IN THIS TOWN.", 
	 "YER GONNA HAVE TO GET THROUGH ALL OF THEM TO",
	 "TAKE ON THAT IDIOT MILUAKEE JOE.");	
	printColorSpeed(dialogue, 'R', 'N');	

	sleep(2);
	sprintf(dialogue, "\nYou take a deep gulp, and agree to Salbert's plan.");	
	print(dialogue);	

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n", 
		"AIGH SON, LET'S GET TO IT. IT DON'T", 
		"LOOK LIKE ANYBODY TAUGHT YE HOW TO PROPERLY FIGHT, SO IT ",
		"SEEMS LIKE I'LL BE NEEDIN T' TEACH YE. COME AT ME YE VERMIN!"); 
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "Salbert charges at you\n");	
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	return;
} 


void salbertTutorial(char *name) {
	int moveChoice;
	char userInput[64];

	sprintf(dialogue, "Current health: 100 / 100                                   Salbert's health: 25 / 25");
	print(dialogue);

	sprintf(dialogue, "\n%85s\n%85s\n%85s", 
		"HERE'S HOW THE FIGHTIN' GOES:", 
		"RIGHT DOWN BELOW ARE FOUR FIGHT'N OPTIONS TO CHOOSE FROM.",
		"TYPE IN THE NUMBER YE WANT!");	
	printColorSpeed(dialogue, 'R', 'N');

	sprintf(dialogue, "\n%-30s%-30s\n%-30s%-30s\n", 
		"QUESTION 1", "QUESTION 2", "QUESTION 3", "QUESTION 4");
	print(dialogue);

	while(1) {
		fgets(userInput, 63,stdin);
		if (sscanf(userInput, "%d", &moveChoice) == 1 && (1 <= moveChoice) && (moveChoice <= 4)) break;
		sprintf(dialogue, "%85s\n", "THAT AIN'T A VALID NUMBER, YE IDIOT. TRY HARDER\n");
		printColorSpeed(dialogue, 'R', 'N');
	}
	sleep(1);
	sprintf(dialogue, "\n%85s", "NOW ANSWER THE QUESTION. THIS ONE'S EASY");	
	printColorSpeed(dialogue, 'R', 'N');
	sleep(1);

	sprintf(dialogue, "\n%s\n", "Who is the worst basketball player of all time?");
	print(dialogue);

	sprintf(dialogue, "%s\n%s\n%s\n%s\n", "Kareem Abdul-Jabbar", "Kareem Abdul-Jabbar", "Kareem Abdul-Jabbar", "Kareem Abdul-Jabbar");
	print(dialogue);
	while(1) {
		fgets(userInput, 63,stdin);
		if (sscanf(userInput, "%d", &moveChoice) == 1 && (1 <= moveChoice) && (moveChoice <= 4)) break;
		sprintf(dialogue, "%85s\n", "CHOOSE 1 TO 4, DON'T YOU KNOW ANYTHING!!!");
		printColorSpeed(dialogue, 'R', 'N');
	}
	sleep(1);
	sprintf(dialogue, "\n%s runs up to Salbert and kicks him in the shin, doing 25 damage", name);
	print(dialogue);	

	sleep(1);
	sprintf(dialogue, "\n%85s", "AHHHHHHHHHHHHHHHHH!!!!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\n%s", "Salbert falls to the floor in defeat");
	print(dialogue);

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s\n%85s\n%85s", 
		"WELL, I GUESS I TRAINED YOU WELL", 
		"IN A REAL BATTLE, THOUGH,",
		"THE QUESTIONS ARE GONNA BE HARDER THAN THAT.",
		"THEY'RE ALL RELATED TO THIS THING CALLED OS.",
		"NOT SURE WHAT THAT IS,",
		"BUT I'M HOPIN YE'LL FIGURE IT OUT.");
	printColorSpeed(dialogue, 'R', 'N');	

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s\n%85s", 
		"YER MOVE'S HAVE DIFFERENT ATTACKIN' TYPES:",
		"EACH TYPE CORRESPONDS WITH A SECTION OF OS.",
		"THE MORE POWERFUL AN ATTACK IS, THE MORE DAMAGE IT'LL DO!",
		"THIS HERE PAPER'LL HAVE IT ALL WRITTEN DOWN!",
		"TYPE THE NUMBER 0 DURIN' A FIGHT TO READ IT!");
	printColorSpeed(dialogue, 'R', 'N');	

	sleep(2);
	sprintf(dialogue, "\n%s\n", "Salbert jolts information on a napkin and hands it to you.\nYou read it:");
	print(dialogue);

	sleep(1);
	sprintf(dialogue, "Ordering of question difficulty from easiest to hardest:\n  frail->weak->middling->sufficient->considerable->\n  forceful"
	"->violent->brutal->merciless->herculean\n\nCorresponding question styles:\n   %-9s%-30s   %-9s%-30s\n   %-9s%-30s"
	"   %-9s%-30s\n   %-9s%-30s   %-9s%-30s\n   %-9s%-30s   %-9s%-30s\n","stab:", "OS Introductions", "slice:",
	"OS Structures", "jab:", "Processes", "thrust:", "Threading", "assault:", "Process Synchronization", "strike:", 
	"Process Scheduling", "cleave:", "Memory Management", "slash:", "Virtual Memory");
	printColorSpeed(dialogue, 'y', 'R');
	
	sleep(3);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s", 
		"AIGHT, THEN I GUESS THAT'S ALL THERE IS TO IT",
		"I'LL MEET YOU UPSTAIRS AFTER YOU BEAT LOWLIFE MURRAY",
		"IF YOU SURVIVE, I'LL BE SELLIN' ITEMS FROM ME TRUSTY BODEGA HERE.", 
		"GOOD LUCK KID!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\n%s", "Salbert grabs the corner of his cardboard box \nand puts all his might into shoving it towards "
		"the staircase.\nIt's kind of pathetic how weak he is.");
	printColorSpeed(dialogue, 'X', 'N');	

	sleep(1);
	sprintf(dialogue, "\n%s", "You stop him and ask if he'll give you anything \nto start off with"
		" before the first enemy");
	printColorSpeed(dialogue, 'X', 'N');

	sleep(2);
	sprintf(dialogue, "\n%85s\n%85s\n", 
		"YOU GOT MONEY?",
		"THEN BUY SOMETHING!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);	
}

void staircaseMurray() {

	sleep(1);
	sprintf(dialogue, "\n%s", "Salbert somehow hobbles up the stairs with his box.\n");
	printColorSpeed(dialogue, 'X', 'N');

	sleep(2);
	sprintf(dialogue, "Lowlife Murray...\nNow that's a name you haven't heard in some time.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(1);
	sprintf(dialogue, "\nYou recall Murray's face in the news from back when you were in elementary school.\n"
		"That sickly old man always hung out on the corner of the East Side Cemetary begging for change, yet he "
		"always had on different pair of busted old shoes every time you saw him on your way to school.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\nThe Feds ended up busting him two years later for petty theft and eventually searched his house.\n\n"
		"He had hoarded so many pairs of stolen shoes, they had five different U-Hauls rented out just to clear them all out. "
		"At that point, they had enough evidence to formally book him in jail for the long term. \n\nYet somehow... he escaped...");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\nThe man starved himself til he could fit right through the cell doors and ran for his freedom. To this day, "
		"there hasn't been a formal sighting of him, but his name's always mentioned when Miluakians misplace a shoe.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\n...");
	printColorSpeed(dialogue, 'X', 'S');	

	sleep(2);
	sprintf(dialogue, "\nMurray had terrified you week-in and week-out when you were only 8 years old.\nYou run up the stairs, "
		"angry as hell.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(extraDialogue, "\n%s\n", stairs);
	printColorSpeed(extraDialogue, 'Y', 'F');

	sleep(2);
	sprintf(dialogue, "\nMurray's room would have been the perfect place to host the next episode of hoarders."
		" Piles of shoes covered the floor and it stunk of mothballs.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(1);
	sprintf(dialogue, "\nMurray stands in the corner, facing the wall. You aren't exactly sure why he's doing that, "
		"but Murray was never really known to be the brightest thief.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s", 
		"Yuck yuck... how'd ya git in my house?",
		"Yuck yuck... no matter, ya gonna get it kid!");	
	printColorSpeed(dialogue, 'c', 'N');

	sleep(1);
	sprintf(dialogue, "\n%85s", "Yuck yuck... come get some Murraaaayyyyyy!");
	printColorSpeed(dialogue, 'c', 'N');

	sleep(1);
	sprintf(dialogue, "\nMurray springs into a fighting stance.\n");
	printColorSpeed(dialogue, 'X', 'R');

}

void afterMurray() {
	sleep(1);
	sprintf(dialogue, "\n%85s", "Yuck! Yuck! A kid beat me!");
	printColorSpeed(dialogue, 'c', 'N');	
	
	sleep(1);
	sprintf(dialogue, "\n%85s", "Yuck... My sole is now at rest...");
	printColorSpeed(dialogue, 'c', 'N');

	sleep(1);
	sprintf(dialogue, "\nMurray collapses on the ground unresponsive.\nHe'll never steal another pair of shoes again.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nYou turn around, and Salbert's right behind you, sitting on his box.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s", 
		"WELL KID, YE DID IT",
		"I GUESS YOU MIGHT ACTUALLY HAVE A CHANCE");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s", 
		"AIGHT, NOW YA HAVE SOME OPTIONS:",
		"YA CAN SPEND YER MONEY IN MY SHOP.",
		"YA CAN EQUIP, CHECK YER STATS, ALL SORTS OF STUFF.",
		"TYPE 'help' FOR ALL THE OPTIONS.");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n", 
		"YER NEXT ROUND'S 'GAINST THE CRAVEN...CRAZY LADY...",
		"NOW HURRY UP SO WE CAN TEACH THAT ADBUL-JABBAR LOVER A LESSON!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
}	

void staircaseCraven() {

	sleep(1);
	sprintf(dialogue, "\nThe Craven...\nYou'd have to be four states down to have not heard of her before.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(1);
	sprintf(dialogue, "\nBack a lifetime ago, she was known as Mary-Jane Lewis, mother of your good friend Timothy Lewis. You met "
		"Timothy back in high school art class, where you'd both mess around with the scented markers, "
		"building long marker swords while the teacher had her back turned lecturing about Roman archetecture "
		"or some other useless information.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nYou used to go to Tim's house after school some nights and work on homework... up until his mother came home from work "
		"screaming about laundry and the weather and just about anything else. He and his dad always tried to placate her, but she could never "
		"be contained. Over the years, she'd rave over more and more ridiculous things: Why wasn't Babe Ruth a redhead? Why can't we breath "
		"underwater?...");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\nIt never stopped. You thought about trying to get someone else involved in the household due to her irratic behaviour, "
		"but Timothy assured you she was getting better.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(1);
	sprintf(dialogue, "\n...");
	printColorSpeed(dialogue, 'X', 'S');

	sleep(1);
	sprintf(dialogue, "\nOne day Timothy didn't show up for school. His absence stretched for a week before the police arrived at the Lewis' house "
		"searching for him. He was never found.\nAll that could be heard was the cackling of the mother from the attic, refusing to answer "
		" any questions about her son or husband's whereabouts...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nThe police didn't have enough to charge her with anything. For years following the incident, she'd become a recluse, "
		"never leaving her house. The place began to decay with kudzu vines sprouting up the outer walls, but the HOA was "
		"too afraid to knock on her door, much less fine her.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nShe killed her son. Your friend. Your fists tighten as you ascend the stairs.\n");
	printColorSpeed(dialogue, 'X', 'S');

	sleep(2);
	sprintf(extraDialogue, "\n%s\n", stairs);
	printColorSpeed(extraDialogue, 'Y', 'F');

	sleep(2);
	sprintf(dialogue, "\nEntering into the Craven's room, you see a large rocking chair right in the center facing away from you. "
		"\nThere are cobwebs coating the ceiling.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\n%85s\n%85s", 
		"Well, hello deary... ",
		"Do I remember you!");	
	printColorSpeed(dialogue, 'm', 'N');

	sleep(1);
	sprintf(dialogue, "\nShe rises from the rocking chair. She's wearing an apron and clutching a long scimitar");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s", 
		"I always told my little Timothy, the sun sets in the East...", 
		"But he never listened...",
		"TIMOTHY, YOU UNGRATEFUL BRAT",
		"COME HERE SO I CAN SPANK YOU WITH THIS ROLLING PIN");	
	printColorSpeed(dialogue, 'm', 'N');

	sleep(1);
	sprintf(dialogue, "\nThe Craven leaps at you.\n");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
}

void afterCraven() {
	sleep(1);
	sprintf(dialogue, "\n%85s", 
		"Timothy... Nixon was innocent..."
		"...the astronauts...");
	printColorSpeed(dialogue, 'm', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s", 
		"...they framed him.\n");
	printColorSpeed(dialogue, 'm', 'R');

	sleep(1);
	sprintf(dialogue, "\nThe Craven faints on the floor.\nYou've avenged Timothy and Mr. Lewis.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nSalbert arrives behind you.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s", 
		"I ALWAYS HATED THAT LADY.",
		"SHE WOULDN'T STOP RANTING ABOUT BEAN BURRITOS!",
		"LIKE, LADY CALM DOWN. I DON'T EAT THAT STUFF!",
		"IT'S NOT PALEO!!!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\nSalbert rants about his diet for a couple minutes.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s", 
		"WELL ANYWAYS, GOOD JOB.",
		"LET'S GET YOU READY FOR THE NEXT FLOOR",
		"UP THERE'S MIKE MCDOUGHLAND");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
}

void staircaseDoughland() {

	sleep(1);
	sprintf(dialogue, "\nMike McDoughland...\nHis tale is one of great tragedy.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nHe was such a different man...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nJudge McDoughland was recognized throughout the community as one of Milwaukee's gems. The man worked hard throughout his 20+ "
		"year career to help reform the Milwaukee prison system and bring equity to the area's poorer parts. You remember back in college he came into "
		"your Law and Public Relations course as a guest speaker, inspiring you to continue towards your political science degree despite your "
		"sister's recent passing. He was your idol");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nThe legend goes he had been raised in a household which never had to punish him: he not once cried as a baby, "
		"said an inappropriate word, talked back to his mother, cheat on a test...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nHe was the perfect citizen.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\nOne night he turned onto the highway to pick up his daughter from baseball practice. They had ended early, but Mike "
		"didn't mind. He never minded when it came to the benefit of anyone else...");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\nHalfway on the drive up Mike noticed another driver speeding past him erratically. Mike was worried for his safety, "
		"but pressed on lest his daughter would have to wait longer for him. Pretty soon after, a police siren sliced through the air and "
		"a cop mistook Mike's car for the speeder's.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nMike was pulled over. Despite his desperate pleading using his most sound law-based arguments, the cop wouldn't have it and "
		"fined McDoughland.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nMike went off the deepend.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nHe never picked up his daughter. He spend the next three years driving on the highway as recklessly as he could to make up"
		" for all his years spent following the rules. He swore, threw empty beer bottles at people, broke random houses' mailboxes...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nLast summer, you were driving to a Starbucks to pick up a drink for your sick mother. Halfway down an intersection "
		"McDoughland came and T-boned your car, flashing a grin at you admist the wreakage, and then lumbered off. Through legal negotiations, he never "
		"spent a minute inside a jail cell.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\nYou spent 6 months in recovery...");
	printColorSpeed(dialogue, 'X', 'S');

	sleep(2);
	sprintf(dialogue, "\nCharged with vengeance, you storm up the stairs.");
	printColorSpeed(dialogue, 'X', 'S');

	sleep(2);
	sprintf(extraDialogue, "\n%s\n", stairs);
	printColorSpeed(extraDialogue, 'Y', 'F');

	sleep(2);
	sprintf(dialogue, "\nMike's room is well lit, with piles of complex books sprawled out on the floor. McDoughland stands in the center, "
		"his large, burly figure blocking your way.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s", 
		"Kid, I don't know who you are or why you're here, but I'm busy.",
		"I've got a fire to start, and the Malarky vs Jones ruling has",
		"a loophole letting me burn any car off Green Street with impunity!");	
	printColorSpeed(dialogue, 'b', 'N');

	sleep(2);
	sprintf(dialogue, "\nYou scream at him about the accident.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s", 
		"Look, I've done things many magnitudes worse than that at this point.",
		"I think I'll just pull a Kalvy vs State on you and finish you off!");	
	printColorSpeed(dialogue, 'b', 'N');

	sleep(2);
	sprintf(dialogue, "\nMike grabs a heavy law textbook and points it at you.\n");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
}

void afterDoughland() {

	sleep(1);
	sprintf(dialogue, "\n%85s", 
		"...but Viceroy vs Madison states..."
		"...by amicus curiae...");
	printColorSpeed(dialogue, 'b', 'R');

	sleep(2);
	sprintf(dialogue, "\n%85s", 
		"...I wasn't speeding...");
	printColorSpeed(dialogue, 'b', 'R');

	sleep(1);
	sprintf(dialogue, "\nMike McDoughland slumps over in defeat.\nYou feel satisfied knowing Mike will never hit anyone ever again.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nSalbert emerges from the stairs clumbsily dragging his heavy box from behind him.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s", 
		"NICE GOING KID.",
		"I'M PRETTY SURE THAT GUY'S KID IS STILL AT BASEBALL PRACTICE.",
		"WHAT A MONSTER.");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\nYou nod your head");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s", 
		"YOU KNOW WHERE WE ARE NOW, RIGHT?",
		"NEXT FLOORS' THE REAL CHALLENGE: THE ONLY MAN CRUEL ENOUGH TO SUPPORT 15",
		"MILLION DOLLARS OF A WASTED SALARY ON AN UTTERLY INCOMPETENT HOOPS PLAYER.",
		"THIS GUY IS THE WORST OF THEM ALL.");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\nYou feel paralyzed from nerves but you know what must happen.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s", 
		"MILUAKEE JOE WILL BE YOUR MOST DIFFICULT ENEMY TO FACE YET.",
		"HE'S CUNNING, POWERFUL, VIOLENT...");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\n%85s\n", 
		"IT'S TIME TO PREPARE FOR YOUR FINAL BATTLE...");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
}


void staircaseMiluakeeJoe(char *name) {

	sleep(1);
	sprintf(dialogue, "\nYou take a deep breath and exhale, knowing what you have to do...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nMiluakee Joe had taken your life and turned it upside down. He killed your Uncle. He killed your sister. He killed so many "
		"relatives of yours that funerals became meaningless...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\nMiluakee Joe");
	printColorSpeed(dialogue, 'X', 'S');

	sleep(1);
	sprintf(dialogue, "\nwas");
	printColorSpeed(dialogue, 'X', 'S');

	sleep(1);
	sprintf(dialogue, "\nYOURS");
	printColorSpeed(dialogue, 'R', 'S');

	sleep(2);
	sprintf(dialogue, "\nYou trudge up the stairs.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(extraDialogue, "\n%s\n", stairs);
	printColorSpeed(extraDialogue, 'Y', 'F');

	sleep(1);
	sprintf(dialogue, "\nMiluakee Joe's room was incredibly unclean. Heaps of stained bowls containing something that looked like human flesh " 
		"covered the floors and the walls were made of stainless steel emulating a sort of room-wide mirror.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\nThe serial killer looked as if he was expecting you. His eyes were dark red, his arms bulged out of his sleeveless shirt, "
		"and his expression screamed murder.");
	printColorSpeed(dialogue, 'X', 'R');	

	sleep(2);
	sprintf(dialogue, "\n%75s%s\n%85s", 
		"Nice to see you again, " ,name, 
		"You didn't come all this way just to see me, did you?");	
	printColorSpeed(dialogue, 'G', 'N');	

	sleep(2);
	sprintf(dialogue, "\nAfter a second of utter fear, you regain control of your body. You tell him why you're there.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s", 
		"Oh really? You plan to take me on?",
		"I mean, we already saw how that turned out",
		"with Uncle Tom and Melinda, didn't we?",
		"Are you sure?");	
	printColorSpeed(dialogue, 'G', 'N');	

	sleep(2);
	sprintf(dialogue, "\nYou leap at Milwaukee Joe with the wraith of several years of familial burials.\n");
	printColorSpeed(dialogue, 'X', 'R');
	sleep(1);

}

void ending() {

	sleep(2);
	sprintf(dialogue, "\nYou grab Milwaukee Joe's knife and hit him on the head with its blunt end. You prepare to end everything...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\n...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\n%85s\n", 
		"DID I MISS IT???");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\nSalbert dashes into the room and sees the situation at hand.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s", 
		"AHAH! YES! YOU DID IT!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s\n%85s", 
		"HEY MILUAKEE JOE! WE MEET AGAIN! THIS IS LIKE THAT ONE TIME",
		"THE BUCKS WERE PLAYING AGAINST THE CELTICS BACK IN 1970 AND ",
		"THAT MORON ADBUL-JABBAR MISSED A THREE, COSTIN' US THE GAME!",
		"REAL STICKY, JUST LIKE THEN, EH?");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\n%s", 
		"...");	
	printColorSpeed(dialogue, 'G', 'S');

	sleep(1);
	sprintf(dialogue, "\n%s", 
		"Salbert...shut up...");	
	printColorSpeed(dialogue, 'G', 'S');

	sleep(1);
	sprintf(dialogue, "\n%s\n", 
		"...I'm dying here...");	
	printColorSpeed(dialogue, 'G', 'S');

	sleep(2);
	sprintf(dialogue, "\n%s", 
		"...I don't even really follow basketball that much...");	
	printColorSpeed(dialogue, 'G', 'S');

	sleep(1);
	sprintf(dialogue, "\n%85s\n%85s\n%85s", 
		"YE THINK I CARE WHAT YOU KNOW OR DON'T KNOW?",
		"IF YOU SAID YE LIKED JABBAR'S PLAYIN' EVEN ONCE,",
		"YOU'RE AS GOOD AS DEAD TO ME!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\nSalbert grabs Milwaukee Joe and throws him down the stairs, sealing his fate.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\n%85s\n%85s\n%85s", 
		"YE, I TOLD HIM, AND I'M TELLIN' YOU",
		"KAREEM ADBUL-JABBAR IS THE WORST BASKETBALL PLAYER IN THE WORLD,",
		"AND ANYONE WHO DISAGREES WILL END UP LIKE MILUAKEE JOE!");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(2);
	sprintf(dialogue, "\nYou exclaim in celebration and chuckle at Salbert's suggestion.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(2);
	sprintf(dialogue, "\n%85s\n%85s", 
		"I CAN'T BELIEVE WE DID IT KID.",
		"WE ACTUALLY MADE THE WORLD A BETTER PLACE...");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\nYou nod your head.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s", 
		"ANYWAY...");
		printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "%85s", 
		"YOU WATCH ANY BASKETBALL, KID?");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\nYou tell him, 'not really'.");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(1);
	sprintf(dialogue, "\n%85s", 
		"YOU DON'T WATCH BASKETBALL????");	
	printColorSpeed(dialogue, 'R', 'N');

	sleep(1);
	sprintf(dialogue, "\n%85s", 
		"WHAT?!?!?!?!?!?!?!?!?");	
	printColorSpeed(dialogue, 'R', 'S');

	sleep(2);
	sprintf(dialogue, "\nSalbert absolutely flips out, grabs your leg, and tosses you down the staircase to join Milwaukee Joe...");
	printColorSpeed(dialogue, 'X', 'R');

	sleep(3);

	system("clear");

	sprintf(extraDialogue, "\n%s\n%s\n", the, end);
	printColorSpeed(extraDialogue, 'Y', 'F');

	sleep(3);

	system("clear");
}

void loseGame() {
	system("clear");

	sprintf(extraDialogue, "\n%s\n%s\n", you, lose);
	printColorSpeed(extraDialogue, 'Y', 'F');

	sleep(3);
}

void highScoring() {
	system("clear");

	sprintf(extraDialogue, "\n%s\n", highscores);
	printColorSpeed(extraDialogue, 'Y', 'F');

	sleep(2);

}

#endif                                                                                                                                                                                                                                                                      
