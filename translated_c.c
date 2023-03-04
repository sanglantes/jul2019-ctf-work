#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printHelp() {
	puts("This function has not been implemented yet");
}

void vuln() {
	// Variables
	char user_input_string[1024];
	char help_string[] = "help\n";
	
	//int count = 126;
	//void var_408;
	//void* rdi = &var_408;
	//for (; count != 0; count--) { // What does this function do?
	//	*rdi = 0;
	//	rdi = rdi + 9;
	//}

	memset(user_input_string, 0, 1024);
	
	puts("Welcome to echo service");
	puts("Type help for help");
	while(1) {
		puts("Echo:");
		fgets(user_input_string, 1000, stdin);

		if (strcmp(user_input_string, help_string) != 0) {
			printf("%s", user_input_string);
			putchar(0xa);
		}
		
		else {
			printHelp();
		}
	}

}

int main() {
	setvbuf(stdout, NULL, 2, 0);
	setvbuf(stdin, NULL, 2, 0);
	vuln();
	return 0;
}
