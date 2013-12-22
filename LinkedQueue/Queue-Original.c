#include "Queue.h"

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
// Initialize QNode pointers to NULL.
//
// Pre:  pN points to a QNode object
// Post: pN->prev and pN->next are NULL
//
void QNode_Init(QNode* pN)
{
   pN->next = NULL;
   pN->prev = NULL;
}

// Initialize Queue to empty state.
//
// Pre:  pQ points to a Queue object
// Post: *pQ has been set to an empty state (see preceding comment
//
void Queue_Init(Queue* pQ)
{
   (*pQ).front.next = &(*pQ).rear;
   (*pQ).front.prev = NULL;
   (*pQ).rear.prev = &(*pQ).front;
   (*pQ).rear.next = NULL;
}

// Return whether Queue is empty.
//
// Pre:  pQ points to a Queue object
// Returns true if *pQ is empty, false otherwise
//
bool Queue_Empty(const Queue* const pQ)
{
   if((*pQ).front.next == &(*pQ).rear)
   {
      return true;
   }
   return false;
}

// Insert *pNode as last interior element of Queue.
//
// Pre:  pQ points to a Queue object
//       pNode points to a QNode object
// Post: *pNode has been inserted at the rear of *pQ
//
void Queue_Push(Queue* const pQ, QNode* const pNode)
{
   (*pNode).prev = (*pQ).rear.prev;
   (*pQ).rear.prev = pNode;
   (*pNode).next = &(*pQ).rear;
   (*(*pNode).prev).next = pNode; 
}

// Remove first interior element of Queue and return it.
//
// Pre:  pQ points to a Queue object
// Post: the interior QNode that was at the front of *pQ has been removed
// Returns pointer to the QNode that was removed, NULL if *pQ was empty
//
QNode* const Queue_Pop(Queue* const pQ)
{
   if(Queue_Empty(pQ) == false)
   {
      QNode* temp = (*pQ).front.next;
      (*pQ).front.next = (*temp).next;
      (*temp).prev = NULL;
      (*(*temp).next).prev = &(*pQ).front;
      (*temp).next = NULL;
      return temp;
   }
   return NULL;
}

// Return first interior element, if any.
//
// Pre:  pQ points to a Queue object
// Returns pointer first interior QNode in *pQ, NULL if *pQ is empty
//
QNode* const Queue_Front(Queue* const pQ)
{
   if (Queue_Empty(pQ))
   {
      return NULL;
   }
   return (*pQ).front.next;
}

// Return last interior element, if any.
//
// Pre:  pQ points to a Queue object
// Returns pointer last interior QNode in *pQ, NULL if *pQ is empty
//
QNode* const Queue_Back(Queue* const pQ)
{
   if (Queue_Empty(pQ))
   {
      return NULL;
   }
   return (*pQ).rear.prev;
}
