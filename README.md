# assignment

A graph traversal program as part of a programming test.

All relevant code is contained within assignment_redo.cpp

I was only able to complete 2 out of the 5 questions, as I wasted a lot of time at the start stressing over what type of data structure to use and how to make it efficient. I ended up just hardcoding the graph values as it simplified the actual solution without having to worry about the data structure. In retrospect, it would have been better to use the Bellman-Ford algorithm instead of Dijkstra's because Dijkstra doesn't work very well with negative numbers, which might be the reason why q2a. is not correct.

I also took the liberty of changing the representation of the nodes from a,b,c,d,e to 0,1,2,3,4.
