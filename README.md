# 42minitalk
A simple client/server implementation in C
The communication is done with UNIX signals. Yes, yes, you know when you do `sigkill -9 <PID>`, that's a UNIX signal. Well, this program sends binary converted characters using two types of UNIX signals, one for 1 and the other for 0.
