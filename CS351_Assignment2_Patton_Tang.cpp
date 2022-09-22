/* <sum>
* Course: CS 351 - Operating System Concepts
* Student: Patton Tang
* Contact: pattontanges@csu.fullerton.edu / pattontanges@gmail.com
* Date: 09/15/2022, due 09/27/2022
* Assignment Name: CS351_Assignment2_Patton_Tang.cpp
*
* Assignment 2 - Create an Interactive Shell in C/C++
* "Write a C/C++ program to implement an interactive shell in which users can execute commands.
* Call this program myShell. Create an infinite loop (while(1)) that repeatedly prompts the user to enter a command
* (see example output and input below)."
*
* Windows:
* dir help vol path tasklist notepad echo color ping
* Since some commands require more than one argument (e.g. echo, color, ping), you will need to parse the user input into its arguments.
* Consider using the strtok() function.
*
* If the command in argument[0] is in the list above, your program must execute the command in a child thread via CreateThread().
* In other words, create a child thread that executes the command.  You do not need to actually write code to execute each command. 
* Simply pass the command into the system call, system() and let the operating system handle the processing for you.
* The parent thread waits for the child to terminate. If the user types exit or quit, your shell should simply terminate.
*
* Assumptions:
* Assume arguments within myShell do not contain spaces.
* In other words, don't worry about parsing out quoted strings in your argument list (e.g.cat a.txt "some file.txt").
* You may assume that no more than four arguments will be used on the command line
* (i.e. similar to argv[0], argv[1], argv[2], and argv[3]).
</sum> */

/* <par>
* External Resources Referenced:
* https://cplusplus.com/reference/cstdlib/system/
* https://stackoverflow.com/questions/266168/simple-example-of-threading-in-c
* https://stackoverflow.com/questions/8032225/c-passing-char-array-to-function
* https://cplusplus.com/reference/thread/thread/
</par> */

// System File Headers
#include<iostream>
#include<stdlib.h>
#include<string>
#include<thread>
#include<map>
#include <fstream>
#include <sstream>
using namespace std;

// Premature declaration for readability
void executeCommand(char cmd[]);

int main() {
	char cmd[25];
	char input[25];

	// An array instead of a Map
	string validCommandList[9];
	validCommandList[0] = "dir";
	validCommandList[1] = "help";
	validCommandList[2] = "vol";
	validCommandList[3] = "path";
	validCommandList[4] = "tasklist";
	validCommandList[5] = "notepad";
	validCommandList[6] = "echo";
	validCommandList[7] = "color";
	validCommandList[8] = "ping";

	// Infinite Loop, breaks upon "Quit" or "Exit"
	while (1) {
		cout << "> ";
		cin.getline(input, 25);

		// Check for Exit Sequence
		if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
			cout << "Thank you for using Windows...";
			break;
		}

		// Isolate initial argument to check against validCommandList
		char argv0[9] = "";
		for (int i = 0; i < (sizeof(input) / sizeof(input[0])); i++) {
			// ASCI 32 is Whitespace
			if (i >= 9) {
				break;
			}
			else if ((input[i] != 32)){
				argv0[i] = input[i];
			}
		}

		// Check for Valid Command, then execute via child
		bool isValidCommand = 0;
		for (int i = 0; i < (sizeof(validCommandList) / sizeof(validCommandList[0])); i++) {
			if (argv0 == "" || argv0 == " ")
			{
				break;
			}
			else if (validCommandList[i] == argv0)
			{
				isValidCommand = 1;

				// Exit Searching
				break;
			}
		}

		if (isValidCommand == 0) {
			cout << "Invalid command, please try again...\n\n";
		}
		else // with Valid Command
		{
			// Copies latter string to former character array
			strcpy_s(cmd, input);

			// Create a thread and execute it via a child thread
			thread process1(executeCommand, cmd);

			// Other processes

			// Wait for process to finish before resuming
			process1.join();
		}
	}
	return 0;
}

void executeCommand(char cmd[])
{
	system(cmd);
}
