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
if [ ! -x "$(command -v "$cmd")" ]; then
write (1 "$cmd: command not found\n" $(expr length "$cmd") + 19)
continue
fi
"$cmd"
done
