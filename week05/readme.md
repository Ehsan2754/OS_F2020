# Lab Excersise Notes

## Excersise 1

### Part1
using the function ```pthread_create(arg1,arg2)``` I create and pass my data to my thread routine.
the output is as follows for N = 5 : 
```UNIX
$./ex1 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@ AHURATHUS Thread CREATOR @@@@@@
@@@@@ OS-Fall2020 @@@@@@ B19-03 @@@@@@
@@@@@@@@@@@@@@@@ EHSAN SHAGHAEI @@@@@@
Enter number of threads to be created!
N=?(N is an INT)5
Creating Thread #1 ...
   >>Thread #1 created!
Creating Thread #2 ...
   >>Thread #2 created!
Creating Thread #3 ...
   >>Thread #3 created!
Creating Thread #4 ...
   >>Thread #4 created!
Creating Thread #5 ...
     -> Hello From Thread #4!
     -> Hello From Thread #5!
     -> Hello From Thread #3!
     -> Hello From Thread #1!
     -> Hello From Thread #2!
   >>Thread #5 created!
```
As we see, 5 threads gets created in the process and each of them ends in a different time depending in the current OS workload and scheduling.

### Part2
using the function ```pthread_join(arg1,arg2)``` I wait untill the created pthread ```thread``` terminates and exits then let's the rest of program run. so the program output would be the following for N = 5:
```UNIX
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@ AHURATHUS Thread CREATOR @@@@@@
@@@@@ OS-Fall2020 @@@@@@ B19-03 @@@@@@
@@@@@@@@@@@@@@@@ EHSAN SHAGHAEI @@@@@@
Enter number of threads to be created!
N=?(N is an INT)5
Creating Thread #1 ...
   >>Thread #1 created!
     -> Hello From Thread #1!
*>EXIT AND Thread #1 TERMINATED!
Creating Thread #2 ...
   >>Thread #2 created!
     -> Hello From Thread #2!
*>EXIT AND Thread #2 TERMINATED!
Creating Thread #3 ...
   >>Thread #3 created!
     -> Hello From Thread #3!
*>EXIT AND Thread #3 TERMINATED!
Creating Thread #4 ...
   >>Thread #4 created!
     -> Hello From Thread #4!
*>EXIT AND Thread #4 TERMINATED!
Creating Thread #5 ...
   >>Thread #5 created!
     -> Hello From Thread #5!
*>EXIT AND Thread #5 TERMINATED!
```
