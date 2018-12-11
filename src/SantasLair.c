#include "SantasWorkshop.h"

// =======================================================================
// Welcome to Santa's Workshop: Santa's Lair!
// =======================================================================
const char *santasCombatMoves[] = {
	"Santa thorws a right punch!", // first seen at action #3
	"Santa thorws a left punch!", // first seen at action #2
	"Santa comes at you with a right kick!", // first seen at action #1
	"Santa comes at you with a left kick!" // first seen at action #29
};

int combatAction(unsigned int playerAction) {
	unsigned int santaAction = rand()%4;
	printf("%s\n", santasCombatMoves[santaAction]);
	if (playerAction == santaAction) {
		return 1;
	}
	return 0;
}

void enterVault() {
	char name[32] = { 0 };
	int numKeys = countKeys();

	printf("You approach the vault.\n");
	for(int i = 1; i < numKeys; i++) {
		printf("You enter key %d and turn.\n", i);
		Sleep(2000);
	}

	if(numKeys == 5) {
		printf("Your eyes scan to the fifth and final key hole.\n");
		Sleep(2000);
		printf("You turn towards Santa as the horror of what needs to be done sets in.\n");
		Sleep(5000);
		printf("Minuts later Santa's vault wooshes open revealing his list!\nEnter your name: ");
		fgets(name, sizeof(name), stdin);
		name[strcspn(name, "\r\n")] = 0;
		printf("You step back and smile as you read \"%s\" at the top of Santa's list.\n", name);
		Sleep(5000);
		printf("Santa's hand rests upon your sholder. \"HOHOHO! Gagging me with a candy cane to get the key - good one!\"\n");
		Sleep(2000);
		printf("You and Santa high-five!\n");
		Sleep(5000);printf("T");
		Sleep(1000);printf("H");
		Sleep(1000);printf("E");
		Sleep(1000);printf(" ");
		Sleep(1000);printf("E");
		Sleep(1000);printf("N");
		Sleep(1000);printf("D\n");
		Sleep(1000);
	} else {
		printf("You don't seem to have the keys you need to open this vault.\n");
	}
	getchar();
}

// Key: 2,1,0,0,0,1,2,2,0,1,0,2,1,2,0,2,2,0,0,1,2,0,2,0
void enterSantasLair() {
	char userInput[32] = {0};
	unsigned int choice = 0;

	system("cls");

	if (countKeys() < 4) {
		printf("You wander around aimlessly, sensing you need to collect some keys first.\n");
		getchar();
		return;
	}

	srand(1225);

	printf(                                                                     \
	"=======================================================================\n" \
	"                       You Enter Santa's Lair!                         \n" \
	"    *  The hair on the back of your neck begins to stand on end  *     \n" \
	"                \"HHOOOOO HOOOOO HO OH NO YOU DON'T\"	                \n"	\
	"     \"IF YOU WANT MY LIST, YOU'LL HAVE TO GET THROUGH ME FIRST!\"     \n" \
	"     Santa rips a shiny key from around his neck and swallows it.      \n" \
	"                         >> Santa Charges <<                           \n" \
	"=======================================================================\n" \
	);
	
	printf("Action list: \n" \
	"0: Dodge and counter right punch.\n" \
	"1: Dodge and counter left punch.\n" \
	"2: Dodge and counter right kick.\n" \
	"3: Dodge and counter left kick.\n\n" \
	"Santa's so fast, you need to pick your action before he does!\n");

	// Santa fight sequence
	for (int i = 0; i < 24; i++) {
		printf("Action: ");
		fgets(userInput, sizeof(userInput), stdin);
		sscanf(userInput, "%u", &choice);
		if (!combatAction(choice)) {
			// you've lost
			printf("(Attack: %d) Santa connects snd knocks you through the wall right back into the main lobby!\n", i+1);
			getchar();
			return;
		} else {
			printf("(Attack: %d) You counter Santa's combat move and connect with your own! Keep going!\n", i+1);
		}
	}

	// you've won!
	keyChain.key5 = 1;
	enterVault();
}
