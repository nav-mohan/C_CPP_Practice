### fork()
[https://man7.org/linux/man-pages/man2/fork.2.html]

````
            P0
            /\  
           /  \    fork()
          /    \
         /      \  
        /        \
      P0          P1
     / |          | \  
    /  |          |  \   fork()
   /   |          |   \
  P0   P2         P1   P3

```