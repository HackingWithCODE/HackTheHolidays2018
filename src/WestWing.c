#include "SantasWorkshop.h"

// =======================================================================
// Welcome to Santa's Workshop: West Wing!
// =======================================================================
void unwrapToy(char *contents) {
	if (keyChain.key4) {
		printf("* WRAPWRAPWRAP * A perfectly wrapped present appears before you.\nYou open it revealing a lump of coal.\n");
	} else {
		printf("* WRAPWRAPWRAP * A perfectly wrapped present appears before you.\nYou open it revealing a key in the shape of a %s.\n", contents);
		keyChain.key4 = 1;
	}
	getchar();
}

void crushBox() {
	printf("* CRUSH * The box collapsed on itself and vanished.\n");
	getchar();
}

void enterWestWing() {
	FILE *file;
	unsigned short boxSize = 32;
	char *toy = NULL;

	system("cls");
	printf(                                                                     \
	"=======================================================================\n" \
	"                       You Enter the West Wing!                        \n" \
	"            * It looks like a magical toy assembly line! *             \n" \
	"             Boxes are materializing out of thin air, and              \n" \
	"         vanishing before you can read what's written on them          \n" \
	"=======================================================================\n" \
	);

	printf("* POOF * A box appears next to your head.\n");

	file = fopen("toybox.txt", "r");
	if(!file)
	{
		crushBox();
		free(toy);
		return;
	} else {
		toy = malloc(boxSize);
		memset(toy, 0, boxSize);

		if (fread(toy, 1, boxSize, file) > 0) {
			unwrapToy(toy);
		} else {
			crushBox();
		}

		fclose(file);
		free(toy);
	}

	return;
}
