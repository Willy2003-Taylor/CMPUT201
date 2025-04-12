#ifndef MYLIST_H_
#define MYLIST_H_
// Forward declaration of a struct.
// We promise the compiler there will be a struct
// named List, but don't worry about its implementation
struct List;
// Since the client programmer will not know the size of
// struct List, they cannot place Lists on the stack.
// In this case, we're okay with that. If we did desire them
// to be able to put our datatype on the stack (or, for the same
// reason, in arrays) then we would provide them the definition here.

// Create a new empty list.
struct List *createList();

// Adds an element to the front of the list
void addToFront(struct List *l, int elem);

// Remove an item from a list, returns
// the removed item
int pop(struct List *l, int i);

// Returns the length of the list
int len(struct List *l);

// Destroys a list, must be called
// on a list created with createList.
// Must be called on lists when finished
// with them, or else you will have memory
// leaks. Returns NULL. So proper
// usage of this, given list *myList is:
// myList = destroy(myList);
// Then guaranteed list is freed
// and your pointer is assigned to null
struct List *destroy(struct List *l);

// Returns the ith element of the list
int ith(struct List *l, int i);

// Sets the ith elment of the list to
// elem
void setIth(struct List *, int i, int elem);

#endif // MYLIST_H_
