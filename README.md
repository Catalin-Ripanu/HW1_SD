# HW1_SD

# The Implementation of the Assignment

The assignment was completed in 3 weeks.

The implementation ideas came to me successively.

## Week 1
- In the first week, I conceived the necessary structures and the logic of the entire program.
- I used `while(1)` and `fgets` to obtain data from the file.
- I also implemented the 'save' and 'quit' commands, as they were the most basic.

## Week 2
- In the second week, I performed the 'da', 'd', 'b', 'gl', 'gc' operations.
- This week presented the most obstacles.
- The delete operations generated many errors because it was necessary to traverse the large list (`LIST` is a doubly linked list of lists).
- Approximately 2-3 days of this week were needed for debugging.
- I used `valgrind` and `GDB`. `valgrind` reported the most errors.
- The move operations (`gl`, `gc`) were straightforward.
- The main idea of the program conceived so far is:

```
      NULL
       ^
       |
 NULL<-a-><-a-><-a-><-a-><-a->NULL
       ^
       |
       v
 NULL<-b-><-b-><-b-><-b-><-b->NULL
       ^
       |
       v
 NULL<-c-><-c-><-c-><-c-><-c->NULL
       |
       v
      NULL
```

I represented the text:
```
aaaaa
bbbbb
ccccc
```

This is what I meant when I said "large list" (each line represents a doubly linked list).

The meanings of the following fields:
- `next`: move one character forward.
- `prev`: move one character backward.
- `nextlist`: move to the beginning of the next line.
- Example: If I'm at the beginning of line 2, I'll reach `c` after the `b->nextlist` operation.
- `prevlist`: move to the beginning of the previous line.
- Obviously, the first line is `LIST->HEAD`, and the last line is `LIST->TAIL`; `LIST->HEAD->prevlist -> NULL`, and `LIST->TAIL->nextlist -> NULL`.
- `LIST2` is the list of lists for commands.
- As I said, many errors in this part of the program.

## Week 3
- In the third week, I finalized the assignment.
- The experience gained in the second week saved me from other errors.
- In this week, I performed the remaining commands: `undo`, `redo`, `re`, `ra`, `dl`, etc.
- For `undo`/`redo`, I used a stack, as it was a requirement.
- The `undo` operation for inserting text was straightforward, I used an auxiliary list.
- The `redo` operation for inserting text was trivial, I called the `add` function that takes the large list and a list (line of text).
- Performing the `ra` operation took an entire day. I put the arguments in 2 lists and traversed the large list.
- Conceiving the `re` operation took 2 hours.
- I spent 5 days to devise the `undo` operations (`re`, `ra`, `d`, etc.).
- The `undo` operation for `re` was straightforward, I used the command with the arguments reversed.
- I handled all cases for each command.
- For all `redo` operations, I popped from the stack and used the `goto` statement.
- I also used these `char*` variables (`s1`, `s2`, `s6`, etc.) for memory deallocation (`valgrind`).

In conclusion, this was not a trivial assignment.
