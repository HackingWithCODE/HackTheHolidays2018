#include "SantasWorkshop.h"

struct KEYS keyChain = {0};

// =======================================================================
// Mistletoes and things
// =======================================================================
void readyTheElves() {
	const char *elves[] = {
		"An Elf named Bugsy comes out swinggin' licorice whips! You run in fear.",
		"An Elf named Mugsy comes out snapping his fingers like it's West Side Story! You run in fear.",
		"An Elf named Buddy comes out. He's the biggest elf you've ever seen! You run in fear.",
	};
	srand(time(NULL));
	printf("%s\n", elves[rand()%3]);
}

unsigned int countKeys() {
	unsigned int count = 0;
	count += keyChain.key1;
	count += keyChain.key2;
	count += keyChain.key3;
	count += keyChain.key4;
	count += keyChain.key5;
	return count;
};

// =======================================================================
// Welcome to Santa's Workshop!
// =======================================================================
int main(int argc, char *argv[])
{
	char userInput[32] = {0};
	unsigned int choice = 0;

	// UI loop
	while (1)
    {
		system("cls");
		choice = 0;
		printf(                                                                     \
		"=======================================================================\n" \
		"                      Welcome to Santa's Workshop!                     \n" \
		"            * You marvel at the grandeur of the Main Lobby *           \n" \
		"           * You count the keys in your pocket. You have %d. *         \n" \
		"=======================================================================\n" \
		"Please select a wing to visit:\n" \
		"  1. The North Wing\n" \
		"  2. The South Wing\n" \
		"  3. The East Wing\n" \
		"  4. The West Wing\n" \
		"Selection: ", countKeys());
		fgets(userInput, sizeof(userInput), stdin);
		sscanf(userInput, "%u", &choice);

		// Main lobby, switch statements
		switch (choice) {
			case 1:
				// if/else patterns
				enterNorthWing();
				break;
			case 2:
				// for & while loops
				enterSouthWing();
				break;
			case 3:
				// x86 calling conventions 
				enterEastWing();
				break;
			case 4:
				// dynamic memory (malloc/free), stack vs. heap, read from a file
				enterWestWing();
				break;
			case 25:
				// prng (The Lava Lamps That Help Keep The Internet Secure: https://www.youtube.com/watch?v=1cUUfMeOijg)
				enterSantasLair();
				break;
			default:
				// modulo, dynamic pointer dereference
				readyTheElves();
				return -1;
		}
	}

	return 0;
}