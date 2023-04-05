1. You can use `id` command in Linux terminal to check which groups you are a member of.
2. "$?" will hold the output of the last code run by Linux.
3. The Ctrl + Z key combination does this.
4. `uname -r -n` can do this.
5. In Linux, "." refers to the current directory, and ".." refers to the parent directory of the current directory. "~" is a Linux "shortcut" used to 
represent a user's home directory. Therefore, "~/" is the beginning of the file or directory path under the user's home directory. When / is preceded by 
nothing, it refers to the root directory.
6. PID is a unique identifier given to every process running on Linux. If it is necessary to find the pid of a process, the "ps" command can be used.
7. This command can display the user's name and their default shell: grep username /etc/passwd | awk -F ':' '{print $1 " " $7}'   '
8. The su command will switch directly to the root account, while the sudo command will only execute a command as root.
9. First run the "crontab -e" command, and then add */30 * * * * /path in the editor. (/path needs to be replaced with the file to run). This will run the 
program every thirty minutes.
10. [30] Write a shell script that only prints the even numbered lines of each file in the current directory. 
The output should be filename: line for each even numbered line. You do not need to print line 
numbers.