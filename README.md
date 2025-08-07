# Philosophers

## Introduction

**Philosophers** is a concurrency project based on the classic *Dining Philosophers Problem*. It simulates philosophers sitting around a table, each alternating between thinking, eating and sleeping — but to eat, each one needs two forks, and forks are shared with their neighbors.

The goal is to handle this simulation **without causing deadlocks or race conditions**, using threads and mutexes.

---

## Objective

* Simulate the behavior of philosophers:

  * **Taking forks**
  * **Eating**
  * **Sleeping**
  * **Thinking**
* Prevent problems such as:

  * **Deadlocks** (where no philosopher can eat)
  * **Race conditions** (inconsistent or corrupted data)
* Handle edge cases (e.g., one philosopher)

---

## Allowed Functions

* `pthread_create`, `pthread_join`, `pthread_mutex_*`
* `usleep`, `gettimeofday`
* Standard I/O functions (`write`, `printf`, etc.)
* `malloc`, `free`

---

## Program Behavior

You run the program with specific arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

* **number\_of\_philosophers**: how many philosophers are at the table
* **time\_to\_die** (ms): if a philosopher doesn’t eat within this time, they die
* **time\_to\_eat** (ms): time a philosopher spends eating
* **time\_to\_sleep** (ms): time a philosopher spends sleeping
* **\[optional] number\_of\_times\_each\_philosopher\_must\_eat**: simulation ends when all have eaten this many times

---

## Output Example

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
400 1 is thinking
```

Each line shows:

* Time since simulation start (ms)
* Philosopher number
* Action taken

---

## Concepts Learned

* Multithreading with pthreads
* Mutexes for synchronization
* Timing control using `usleep` and `gettimeofday`
* Preventing deadlocks and starvation

---

## Conclusion

This project strengthens your understanding of **parallelism**, **thread safety**, and **real-time constraints**. It's a great introduction to low-level synchronization and concurrency control in C.
