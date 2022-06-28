## Process Controls
### fork() and wait()

#### fork() 
```
            P0
            /\  
           /  \  fork()
          /    \  
         /      \
       P0        P1
      / |        | \  
     /  |        |  \ fork()
    /   |        |   \
   P0   P2       P1   P3
```	