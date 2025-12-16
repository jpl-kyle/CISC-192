I mismanaged my time, so I will work with what I have.

# Reflection

### 1. Differences between:
   - pointer to stack memory  
   - pointer to heap memory  

The pointer to stack memory is quick because the information it points to is sequential. Meanwhile, the pointer to heap memory allows you to allocate memory non-sequentially, which means the information it can store is more dynamic, but it has to be deleted to free up memory.

### 2. Where and why `delete` was used.  

Delete was used in the exit switch case because I do not want to `return 0;` before I delete the dynamic array, so I am able to delete it while in the switch statement.

### 3. Explanation of ownership in each design.  

A lot of the stuff I wrote for this assignment came from my past assignments, and because of my time crunch, I put very few comments, especially on part B

I created guidelines for myself to remember how the pointers interacted with the memory addresses of each task, for getID(), getDescription(), isCompleted(), I treated them as setters. For completeTask() and print task, I went back to my habit of using if-else statements because I am more comfortable with them. For Part B, I kept the design mostly the same, except printTask() acts more like listTask(), and I also had more time so I heavily relied on youtube videos and the lessons you gave in the class so I can fulfill my vision of the program. It is a little bit messy with its implementation because I focused more on functionality than structure. If I could, I would have definitely given myself the whole week to work on this project rather than the weekend.

### 4. Which pointer method is safest and why.
Based on what I have done for this assignment, the pointer to stack memory is safest and more efficient. Because I gave the heap memory code a set size, it was much more predictable and easy to manage.
