# Excercise explanations

## Notes on EX1

Each time the program runs, a parent and a child is created by ```  fork() ``` and in ex2.sh we run program 10 times; hence it makes 10 childs and 10 parents => 20 processes. 

```
****************************************
DATA APPENDED FROM   AHURATUS TERMINAL
>RIGHTS RESERVED FOR    EHSAN SHAGHAEI <
****************************************
* Hello from parent [1272 - 23]
* Hello from child [0 - 23]
* Hello from parent [1274 - 23]
* Hello from child [0 - 23]
* Hello from parent [1276 - 23]
* Hello from child [0 - 23]
* Hello from parent [1278 - 23]
* Hello from child [0 - 23]
* Hello from parent [1280 - 23]
* Hello from child [0 - 23]
* Hello from child [0 - 23]
* Hello from parent [1282 - 23]
* Hello from parent [1284 - 23]
* Hello from child [0 - 23]
* Hello from child [0 - 23]
* Hello from parent [1286 - 23]
* Hello from parent [1288 - 23]
* Hello from child [0 - 23]
* Hello from parent [1290 - 23]
* Hello from child [0 - 23]
```


## Notes on EX2

> For n = 3 ; System creates overall 2^3 = 8 processes

```
****************************************
DATA APPENDED FROM   AHURATUS TERMINAL
>RIGHTS RESERVED FOR    EHSAN SHAGHAEI <
****************************************
init-+-init---init-+-bash---tmux: client
     |             `-tmux: server-+-bash---vim
     |                            `-bash-+-ex2-+-ex2-+-ex2-+-2*[ex2]
     |                                   |     |     |     `-ex2---ex2
     |                                   |     |     |-ex2---2*[ex2]
     |                                   |     |     `-2*[ex2]
     |                                   |     |-ex2-+-ex2---2*[ex2]
     |                                   |     |     |-ex2---ex2
     |                                   |     |     `-ex2
     |                                   |     `-3*[ex2]
     |                                   `-pstree
     `-{init}
```
> For n = 5 ; System creates overall 2^5 = 32 processes

```
****************************************
DATA APPENDED FROM   AHURATUS TERMINAL
>RIGHTS RESERVED FOR    EHSAN SHAGHAEI <
****************************************
init-+-init---init-+-bash---tmux: client
     |             `-tmux: server-+-bash---vim
     |                            `-bash-+-ex2-+-ex2-+-ex2-+-ex2-+-ex2---ex2
     |                                   |     |     |     |     `-ex2
     |                                   |     |     |     |-ex2---ex2
     |                                   |     |     |     `-ex2
     |                                   |     |     |-ex2-+-ex2---ex2
     |                                   |     |     |     `-ex2
     |                                   |     |     |-ex2---ex2
     |                                   |     |     `-ex2
     |                                   |     |-ex2-+-ex2-+-ex2---ex2
     |                                   |     |     |     `-ex2
     |                                   |     |     |-ex2---ex2
     |                                   |     |     `-ex2
     |                                   |     |-ex2-+-ex2---ex2
     |                                   |     |     `-ex2
     |                                   |     |-ex2---ex2
     |                                   |     `-ex2
     |                                   `-pstree
     `-{init}
```

