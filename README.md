# OS-Interactive-Shell

Assignment for Operating System Concepts
Due: 09-27-2022

Instructions:
Interactive Shell:
Write a C/C++ program to implement an interactive shell in which users can execute commands. Call this program myShell. Create an infinite loop (while(1)) that repeatedly prompts the user to enter a command (see example output and input below). Before executing the command entered by the user, the command must be compared against the list of supported commands shown here:


Windows	
dir	
help
vol	
path
tasklist
notepad	
echo	
color	
ping

Since some commands require more than one argument (e.g. echo, color, ping), you will need to parse the user input into its arguments. Consider using the strtok() function.

Assumptions: Assume arguments within myShell do not contain spaces. In other words, don't worry about parsing out quoted strings in your argument list (e.g.cat a.txt "some file.txt"). You may assume that no more than four arguments will be used on the command line (i.e. similar to argv[0], argv[1], argv[2], and argv[3]).
