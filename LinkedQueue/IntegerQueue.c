#include "IntegerQueue.h"
#include "Queue.h"
#include "IntegerDT.h"
#include <stdlib.h>
#include <assert.h>

// On my honor: //
// // - //
// //
// //
// // - //
// //
// // - //
// I have not discussed the C language code in my program with anyone other than my instructor or the teaching assistants assigned to this course.
// I have not used C language code obtained from another student, or any other unauthorized source, either modified or unmodified.
// If any C language code or documentation used in my program
// was obtained from another source, such as a text book or course notes, that has been clearly noted with a proper citation in the comments of my program.
// //
// //
// //
// // Ben Johnston

/* Integer Queue defines an interface suitable for a client who needs to create and manipulate a queue of integer values (int32_t).
 *
 * Integer Queue uses the data wrapper IntegerDT, and the Queue type for the underlying physical structure.
*/

// Initialize empty IntegerQueue.
//
// Pre:  pIQ points to an IntegerQueue object
// Post: pIQ->Q has been initialized to an empty state
//       (see Queue.h for details)
//
void IntegerQueue_Init(IntegerQueue* const pIQ)
{
   Queue_Init(&(*pIQ).Q);
}

// Return whether IntegerQueue is empty.
//
// Pre:  pIQ points to aqn IntegerQueue object
// Returns true if pIQ->Q is empty, false otherwise 
//
bool IntegerQueue_Empty(const IntegerQueue* const pIQ)
{
   return Queue_Empty(&(*pIQ).Q);
}

// Insert K at rear of IntegerQueue.
//
// Pre:  pIQ points to an IntegerQueue object
// Post: An IntegerDT object containing the value K has been inserted 
//       at the rear of pIQ->Q
//
void IntegerQueue_Push(IntegerQueue* const pIQ, int32_t K)
{
   IntegerDT* stuff =  malloc(sizeof(IntegerDT));
   IntegerDT_Init(stuff, K);   
   Queue_Push(&(*pIQ).Q, &(*stuff).node);
}

// Remove and return data value from front of IntegerQueue.
//
// Pre:  pIQ points to a nonempty IntegerQueue object
// Post: The IntegerDT object at the front of pIQ->Q has been removed
// Returns the user data value that was in the IntegerDT object at the 
// front of pIQ->Q
//
int32_t IntegerQueue_Pop(IntegerQueue* const pIQ)
{
   assert(Queue_Empty(&(*pIQ).Q) == false);
   QNode* temp = Queue_Pop(&(*pIQ).Q);
   IntegerDT* stuff = Queue_Entry(temp, IntegerDT, node);
   int32_t val = (*stuff).payload;
   free(stuff);
   return val;
}
