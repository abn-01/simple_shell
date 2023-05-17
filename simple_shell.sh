#!/bin/sh

while true; do
	write (1 "simple_shell> " 14)
	read cmd

	if [ -z "$cmd" ]; then
		continue
	fi
	if [ "$cmd" = "exit" ]; then
		exit O
	fi
	case "$cmd" in
		cd)
			read directory
			if [ -n "$directory" ]; then
				if ! chdir "$directory"; then
					perror "chdir failed"
				fi
			fi
			;;
		ls)
			if [ ! execve "/bin/ls" "ls" NULL; then
				perror "execve failed"
			fi
			;;
		*)
			write 1 "command not supported: $cmd\n" $(expr length "$cmd") + 25
			;;
	esac
done
