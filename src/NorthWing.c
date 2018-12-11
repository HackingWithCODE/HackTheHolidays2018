#include "SantasWorkshop.h"

/*
	Note: No one really calls these patterns "steps" or "ladders",
	this is just a convention to differentiate between the two we'll see.
	It's also imporant to know that MinGW produces these patterns, and
	other compilers may optimize the code in a way that breaks the 
	intended patterns. Please see the CO/DE "Hack the Holidays 2018"
	handouts for visual descriptions of the intended patterns!
*/

#define IF_ELSE_STEPS   0
#define IF_ELSE_LADDER  1

#define PATTERN_USED 	IF_ELSE_STEPS

// =======================================================================
// Welcome to Santa's Workshop: North Wing!
// =======================================================================

void sendInTheMuscle() {
	printf("The elf whistles and suddenly the entire room stops and stares. You run in fear.");
	getchar();
}

void welcomeToTheParty() {
	if (keyChain.key1) {
		printf("The elf nods with a sense of mutual understanding, as if you've done this exchange before.");
	} else {
		printf("\"Welcome to the party.\" the elf says, as he slips a key into your coat pocket.");
		keyChain.key1 = 1;
	}
	getchar();
}

// Key: John McClane
int enterNorthWing() {
	char name[20] = { 0 };

	system("cls");
	printf(                                                                     \
	"=======================================================================\n" \
	"                       You Enter the North Wing!                       \n" \
	"             * You sense a themed Christmas party going on! *          \n" \
	"                   Elves are walking around smoking 		            \n"	\
	"              cigarettes with bare feet and blood-soaked               \n" \
	"                            shirts. Strange.				            \n"	\
	"=======================================================================\n" \
	);

	printf("\"Your name, please?\" You look down to see a rather\n"  \
	"tough looking elf with a clipboard and a short fuse.\n\n"       \
	"You'd better give him a name, quick.\n"                         \
	"Name: ");
	fgets(name, sizeof(name), stdin);

	if (strlen(name) < 12) {
		sendInTheMuscle();
		return -1;
	}
	
	#if PATTERN_USED == IF_ELSE_STEPS
		// IF/ELSE Pattern 1
		if (name[0] != 'J') { 
			sendInTheMuscle(); 
			return -1; 
		} else {
			if (name[1] != 'o') { 
				sendInTheMuscle(); 
				return -1; 
			} else {
				if (name[2] != 'h') { 
					sendInTheMuscle(); 
					return -1; 
				} else {
					if (name[3] != 'n') { 
						sendInTheMuscle(); 
						return -1; 
					} else {
						if (name[4] != ' ') { 
							sendInTheMuscle(); 
							return -1; 
						} else {
							if (name[5] != 'M') { 
								sendInTheMuscle(); 
								return -1; 
							} else {
								if (name[6] != 'c') { 
									sendInTheMuscle(); 
									return -1; 
								} else {
									if (name[7] != 'C') { 
										sendInTheMuscle(); 
										return -1; 
									} else {
										if (name[8] != 'l') { 
											sendInTheMuscle(); 
											return -1; 
										} else {
											if (name[9] != 'a') { 
												sendInTheMuscle(); 
												return -1; 
											} else {
												if (name[10] != 'n') { 
													sendInTheMuscle(); 
													return -1; 
												} else {
													if (name[11] != 'e') { 
														sendInTheMuscle(); 
														return -1; 
													} else {
														welcomeToTheParty();
														return 0;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

	#elif PATTERN_USED == IF_ELSE_LADDER
		// IF/ELSE Pattern 2
		if (name[0] == 'J')
		if (name[1] == 'o')
		if (name[2] == 'h')
		if (name[3] == 'n')
		if (name[4] == ' ')
		if (name[5] == 'M')
		if (name[6] == 'c')
		if (name[7] == 'C')
		if (name[8] == 'l')
		if (name[9] == 'a')
		if (name[10] == 'n')
		if (name[11] == 'e') {
			welcomeToTheParty();
			return 0;
		}
		sendInTheMuscle();
		return -1;
	#endif
}
