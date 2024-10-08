# Minitalk

The purpose of this project is to code a small data exchange program  using UNIX signals.

# Notes

## v1

+ Sending and recieving signals using ASCII encoding
+ Need to add:
	+ proper queueing of signals
	+ printing message after, **NOT** during recieving it (send size of message first)
	+ **REMOVE** timestamps (leaving them in right now just for info)
	+ [**NO BONUS!** - for bonus use sa_sigaction to get pid of calling process]
