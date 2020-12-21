==========================================
README.TXT FILE FOR PRODUCERCONSUMER.JAVA
WRITTEN BY RILEY NADWODNY
ID: 010817007
==========================================

==========================================
BUFFER CLASS
==========================================
The buffer class contains a Linked List buffer. Linked List was
chosen because java.util.LinkedList already has built-in commands
and works well as a FIFO system.

The buffer is declared with a Random variable in order to generate
the random number to put into the buffer. It also contains a
semaphore full of size 0, semaphore empty of size 5 (the size of the buffer),
and a semaphore mutex of size 1 to behave as a mutex for the buffer.

The insertItem method adds a new random integer between 0 and 10000
to the buffer. The item added to the buffer is then printed out.

The removeItem method removes the first item in the buffer.
The removed item is returned to the consumer to print out
the item that has been removed.


==========================================
PRODUCER CLASS
==========================================
The producer class contains a copy of the buffer and
a Random variable in order to generate random numbers
to sleep the thread.

The producer constructor sets its own buffer equal to
the buffer passed in from main.

The producer run method begins with a for loop to do
100 operations, as specified in the homework instructions.
It implements a try-catch block in order to catch any exceptions
and perform an interrupt in the event the thread needs to be interrupted
and joined. The producer first asks for an empty semaphore and the mutex.
It then inserts an items into the buffer, prints out what is produced,
and then releases the mutex and a full semaphore. The thread then sleeps
for anywhere between 0 - 0.5 seconds.


==========================================
CONSUMER CLASS
==========================================
The producer class contains a copy of the buffer and
a Random variable in order to generate random numbers
to sleep the thread.

The producer constructor sets its own buffer equal to
the buffer passed in from main.

The producer run method begins with a for loop to do 100
operations, as specified. It imeplements a try-catch block
in order to catch any exceptions and perform an interrupt
in the event the thread needs to be interrupted and joined.
The consumer first asks for any empty semaphore and the mutex.
It then consumes the first item from the buffer and prints
out what is consumed. It then releases the mux and an empty
semaphore. The thread then sleeps for some time between
0 - 0.5 seconds.

==========================================
PRODUCERCONSUMER CLASS
==========================================
The ProcuderConsumer class contains three variables to start;
int time, int producers, and int consumers.
Inside of main, a new buffer is created. Time is assigned
args[0] from the command line * 1000 to get the correct time,
producers is assigned args[1], and consumers is assigned args[2].
A long start and long end variables are declared as well in order
to keep track of run time to terminate the program if it
runs over the specified time from args[0].
While the System.currentTimMillis() is less than the end time,
the program runs. If args.length == 3, the program continues to run,
otherwise it errors out. The command line arguments are printed
back to the user for verification. A new array of threads for
producers is declared and initialized to an array of threads, 
with the size being the same value as producers. The
array of threads are then initialized in a for loop
and started. The same declaration and initialization is done
with an array for consumer threads, as well as a for
loop to create and run the threads. Main is then
slept for the specified amount of time from the user.
If the current system time is greater than the
calculated end time, the program then interrupts and
joins the consumer and producers threads to end the program.
However, if the system time is less than the calculated
end time and the program finishes in time, the consumer
and producer threads are ended properly and joined
back to main in order to finish the program. The program
then ends once all of the producers and consumers
are joined.