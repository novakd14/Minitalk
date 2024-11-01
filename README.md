# Minitalk

The purpose of this project is to code a small data exchange program  using UNIX signals.

# Notes

## v1.1

- message is now printing after completly recieving it (first 4 bytes is the size of message)
- removed timestamps from client
- best queueing possible
- Need to add:
	- returning signal once server deals with previous signal to deal with pending (server after recieving signal sends signal back to client to inform it to send next signal)
	- [**NO BONUS!** - for bonus use sa_sigaction to get pid of calling process]

## v1

- Sending and recieving signals using ASCII encoding
- Need to add:
	- proper queueing of signals
	- printing message after, **NOT** during recieving it (send size of message first)
	- **REMOVE** timestamps (leaving them in right now just for info)
	- [**NO BONUS!** - for bonus use sa_sigaction to get pid of calling process]
