/*
/   Name: Riley Nadwodny
/   Date: 12/9/2020
/   ID: #010817007
/   Description: Producer-Consumer Bounded Buffer problem using semaphores and mutexes.
/   Producers and consumers exchange the semaphores and mutex in order to read and consume
/   from the bounded buffer and add and produce to the bounded buffer.
/   Solution involves using a linked list as the bounded buffer type as the linked list
/   java.util already has methods for adding and removing items.
*/

import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.LinkedList;

class Buffer {
    LinkedList<Integer> buffer = new LinkedList<>();
    Random rand = new Random();
    Semaphore full = new Semaphore(0);
    Semaphore empty = new Semaphore(5);
    Semaphore mutex = new Semaphore(1);

    public Buffer() {
    }

    public void insertItem() throws InterruptedException {
        buffer.add(rand.nextInt(10000));
        System.out.println("Producer produced " + buffer.getLast());
    }

    public int removeItem() throws InterruptedException {
        int item = buffer.removeFirst();
        return item;
    }
}

class Producer implements Runnable {
    private Buffer b;
    Random rand = new Random();

    public Producer(Buffer b) {
        this.b = b;
    }

    public void run() {
        for (int i = 0; i < 100; i++) {
            try {
                b.empty.acquire();
                b.mutex.acquire(); 
                b.insertItem();
                b.mutex.release();
                b.full.release();
                Thread.sleep(rand.nextInt(500));
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
        }
    }

}

class Consumer implements Runnable 
{
    private Buffer b;
    Random rand = new Random();

    public Consumer(Buffer b) 
    {
        this.b = b;
    }

    public void run() {
        for (int i = 0; i < 100; i++) {
            try {
                b.full.acquire();
                b.mutex.acquire();
                System.out.println("Consumer consumed " + b.removeItem());
                b.mutex.release();
                b.empty.release();
                Thread.sleep(rand.nextInt(500));
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
        }
    }
}

public class ProducerConsumer 
{
    static int time;
    static int producers;
    static int consumers;

    public static void main(String[] args) throws InterruptedException 
    {
        Buffer b = new Buffer();
        time = (Integer.parseInt(args[0]) * 1000);
        producers = Integer.parseInt(args[1]);
        consumers = Integer.parseInt(args[2]);
        long start = System.currentTimeMillis();
        long end = start + time;

        // While the time is less than the specified time, run the program.
        // If time runs over, interrupt and join threads
        while (System.currentTimeMillis() < end) {

            if (args.length == 3) 
            {

                System.out.println("Using arguments from command line");
                System.out.println("Sleep time = " + Integer.parseInt(args[0]) + "s");
                System.out.println("Producer threads = " + producers);
                System.out.println("Consumer threads = " + consumers);

                // Create and start threads for producers, let them run.
                Thread[] threadProducers = new Thread[producers];
                for (int i = 0; i < producers; i++) 
                {
                    threadProducers[i] = new Thread(new Producer(b));
                    threadProducers[i].start();
                }

                // Create and start threads for consumers.
                Thread[] threadConsumers = new Thread[consumers];
                for (int i = 0; i < consumers; i++) 
                {
                    threadConsumers[i] = new Thread(new Consumer(b));
                    threadConsumers[i].start();
                }

                // Sleep main for " " seconds
                Thread.sleep(time);

                // If the program runs over the specified time,
                // interrupt and join the threads to end the program.
                if (System.currentTimeMillis() >= end) {
                    // Join the consumer threads
                    for (int i = 0; i < consumers; i++) 
                    {
                        if (threadConsumers[i].getState() == Thread.State.WAITING || (threadConsumers[i].getState() == Thread.State.TIMED_WAITING))
                        {
                            threadConsumers[i].interrupt();
                            threadConsumers[i].join();
                            System.out.println("Consumer " + i + " joined");
                        }
                    }

                    // Join the producer threads
                    for (int i = 0; i < producers; i++) 
                    {
                        if (threadProducers[i].getState() == Thread.State.WAITING || (threadProducers[i].getState() == Thread.State.TIMED_WAITING))
                        {
                            threadProducers[i].interrupt();
                            threadProducers[i].join();
                            System.out.println("Producer " + i + " joined");
                        }
                    }
                }

                // Join the consumer threads
                for (int i = 0; i < consumers; i++) 
                {
                    if (threadConsumers[i].getState() == Thread.State.WAITING || (threadConsumers[i].getState() == Thread.State.TIMED_WAITING))
                    {
                        threadConsumers[i].interrupt();
                        threadConsumers[i].join();
                        System.out.println("Consumer " + i + " joined");
                    }
                }

                // Join the producer threads
                for (int i = 0; i < producers; i++) 
                {
                    if (threadProducers[i].getState() == Thread.State.WAITING || (threadProducers[i].getState() == Thread.State.TIMED_WAITING))
                    {
                        threadProducers[i].interrupt();
                        threadProducers[i].join();
                        System.out.println("Producer " + i + " joined");
                    }
                }
            }
        }
    }
}