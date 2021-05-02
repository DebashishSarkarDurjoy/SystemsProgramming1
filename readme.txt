(a)
Name: Debashish Sarkar Durjoy
Student ID: 19902470

(b)
to compile: cc main.c -o main
then: ./main

(c)
1. The main() calls the displayMenu().
2. The displayMenu() shows the menu and also takes user input which is returned to the switch statement;
3. Based on the user input the following functions are called:
    if 0 is chosen: then 0 is returned by the main(), so the entire program closes.
    if 1 is chosen: then the list is built by calling the function buildList().
    if 2 is chosen: then the list is sorted using the function sortList().
    if 3 is chosen: then the list is displayed using the function displayList().

The functions are described more in detail here:
buildList(): takes head as argument and builds a list using the following pseudo-code:
             create first node using the malloc function and set the attribute values according to the requirements,
             make the head point to the first node,
             make a loop to make the other nodes:
                perform the loop using a current node pointer which will point to the current node,
                make each current node to point to the next new node,
                make each new node base priority a random value.
             at the end of the loop make the last node to point to NULL.

sortList(): takes the pointer to a header pointer and the pointer to the function priComp(),
            there are three possible scenarios (continue the loop as long as the list is not sorted):
              if there is misplacement at the head of the list:
                perform appropriate changing of links.
              if there is misplacement at the end of the list:
                perform appropriate changing of the links.
              if there is misplacement in the middle of the list:
                perform appropriate changing of the links.

displayList(): takes the header pointer as an argument,
               creates a current pointer which initially points to the header pointer,
               then loops until current is not NULL,
                and displays the contents of the IORB nodes.

priComp(): takes in an integer argument and return integer,
           the returned integer (scheduling algorithm) is simply the addition of the first and last digit of the base_pri

isSorted(): checks if any element in the list is out of order,
            returns false for minimum one out of order,
            return true if none are out of order.


(d)
checking if the file executes without error: cc main.c -o main
      if executes without error then the main is clear of any syntax errors.

checking if there is any run-time error (by running the main): ./main
      enter 1, builds list (no error)
      enter 3, displays the list (no error)
      enter 2, sorts the list (no error)
      enter 3, displays the sorted list (no error)

Doing the same thing as above only changing the srand() argument.


(e)
I wanted to store the description of the nodes into the IORB filler attribute
but that requires the conversion of int to char and using the strcat and strcpy.
Because implementing that is very tricky, instead I stored the i/o request number
into the filler[0] for each of the nodes and displayed the other information
separately using the printf() function within the displayList() function.
