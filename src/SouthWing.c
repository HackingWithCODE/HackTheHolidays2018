#include "SantasWorkshop.h"

// =======================================================================
// Welcome to Santa's Workshop: South Wing!
// =======================================================================

void turnSentient() {
	printf("The LETTERTRON 2000 begins to weep softly. You get this sense it's starting to feel emotions. You run in fear.");
	getchar();
}

void produceKey() {
	if (keyChain.key2) {
		printf("LETTERTRON 2000 hums softly, as if you two have met before.\n");
	} else {
		printf("BeeBoop! *Rattle Clank Bonk* A key pops out of the machine.\nYou put it in your pocket and rush back to the main lobby.\n");
		keyChain.key2 = 1;
	}
	getchar();
}

// Key: Any sequence of 50 or less ASCII characters adding up to exactly 2000.
void enterSouthWing() {
	char letters[50] = { 0 };
	char command[30] = { 0 };
	char ticketMode = 1;
	char *overrideCommand = "New England Clam Chowder";
	unsigned int letterSum = 0;

	system("cls");
	printf(                                                                     \
	"=======================================================================\n"	\
	"                        You Enter the South Wing!                      \n"	\
	"                  In the center of this otherwise empty  	            \n"	\
	"                      room sits the LETTERTRON 2000                    \n"	\
	"=======================================================================\n"	\
	);

	printf("\"Beep Boop Booooo\" The LETTERTRON 2000 is flashing.\n"  \
	"It begins to speak, \"Now accepting letters!\"\n\n"              \
	"You notice a switch on its side, one setting \"Tickets\", the\n" \
	"other, \"Christmas Keys\". You flip the switch.\n");

	while (ticketMode) {
		printf("ENTER OVERRIDE COMMAND: ");
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\r\n")] = 0; // remove trailing newline
		if (strcmp(command, overrideCommand) == 0) {
			printf("CHRISTMAS KEY MODE ENGAGED!\n");
			ticketMode = 0;
		}
	}

	printf("GIVE ME LETTERS: ");
	fgets(letters, sizeof(letters), stdin);
	letters[strcspn(letters, "\r\n")] = 0; // remove trailing newline

	for (int i = 0; i < strlen(letters); i++) {
		letterSum += letters[i];
	}
	
	if (letterSum == 2000) {
		produceKey();
	} else {
		printf("BeeBoop! *Clank Crack Bzzz* %d IS NOT CORRECT!\n", letterSum);
		turnSentient();
	}
}

