#include "SantasWorkshop.h"

// =======================================================================
// Welcome to Santa's Workshop: East Wing!
// =======================================================================

void soundAlarm() {
	printf("An alarm sounds as smoke fills the room.\nRed lasers scatter across the room and settle on your chest. You run in fear.");
	getchar();
}

void presentKey() {
	if (keyChain.key3) {
		printf("This place looks familiar, as if you've been here before.\n");
	} else {
		printf("In the center of the empty room before you, a treasure chest rises from the floor.\n" \
		"You lift it open to reveal a glimmering key which you quickly pocket before heading back to the main lobby.\n");
		keyChain.key3 = 1;
	}
	getchar();
}

// cdecl (default), cleanup: caller, parameters pushed to stack, right to left
__attribute__((cdecl)) int door1(char btn1, char btn2, char btn3, char btn4) {
	if (btn1 == '5' && btn2 == '7' && btn3 == '1' && btn4 == '8') {
		return 1;
	}	
	return 0;
}

// stdcall, cleanup: callee, parameters pushed to stack, right to left
__attribute__((stdcall)) int door2(char btn1, char btn2, char btn3, char btn4) {
	if(btn1 == '9' && btn2 == '2' && btn3 == '3' && btn4 == '6') {
		return 1;
	}
	return 0;
}

// fastcall, cleanup: callee, first param in ecx, rest on stack, right to left
__attribute__((fastcall)) int door3(char btn1, char btn2, char btn3, char btn4) {
	if(btn1 == '0' && btn2 == '4' && btn3 == '2' && btn4 == '1') {
		return 1;
	}
	return 0;
}

// Key: [door 1: 5718], [door 2: 9236], [door 3: 0421]
void enterEastWing() {
	char pin[6] = { 0 };

	system("cls");
	printf(                                                                     \
	"=======================================================================\n" \
	"                    You Enter the East Wing!                           \n" \
	"       It's as if the entire room was carved from marble.              \n" \
	"                * You realize you're in a bank *                       \n" \
	"    * You see a flashing keypad on one of the vault doors *            \n" \
	"=======================================================================\n" \
	);

	// For more information on calling conventions see:
	// https://destructure.io/posts/x86-calling-conventions/
	printf("Welcome to the North Pole Bank Head Elf Vault.\n"); 
	
	// Door 1: cdecl
	printf("Please enter pin: ");
	fgets(pin, sizeof(pin), stdin);
	if (!door1(pin[0], pin[1], pin[2], pin[3])) {
		soundAlarm();
		return;
	}
	
	// Door 2: stdcall
	printf("The vault door slides open with a hiss.\n" \
	"Chunks of candy cane and whispers of children's giggles tumble from the room beyond.\n" \
	"You skip inside and notice a second, much larger door with a key pad.\n");
	printf("Please enter pin: ");
	fgets(pin, sizeof(pin), stdin);
	if (!door2(pin[0], pin[1], pin[2], pin[3])) {
		soundAlarm();
		return;
	}

	// Door 3: fastcall
	printf("The vault door swings open with a groan.\n" \
	"It's cold inside, or is this outside? It's dark and the ground feels like you're walking in fresh snow.\n" \
	"You can barely make out the faint glow of another keypad across the room.\n" \
	"You reach the door.  You have a good feeling about this one.\n");
	printf("Please enter pin: ");
	fgets(pin, sizeof(pin), stdin);
	if (!door3(pin[0], pin[1], pin[2], pin[3])) {
		soundAlarm();
		return;
	}

	presentKey();
	return;
}

