//
// Created by Laila Nasser ElKoussy 900160812 on 11/19/17.
//

#ifndef ASSIGNMENT_5_STACKT_H
#define ASSIGNMENT_5_STACKT_H

template <class Type>
class Stackt {
public:

    Stackt(int nelements = 128);	// Constructor
    Stackt(const Stackt<Type> &);	// Copy Constructor
    ~Stackt();						// Destructor

    // Member Functions
    void push(Type);				// Push
    void pop(Type &);				// Pop
    void stackTop(Type &) const;	// retrieve top
    bool stackIsEmpty() const;	// Test for Empty stack
    bool stackIsFull() const;		// Test for Full stack

private:
    Type *stack;					// pointer to dynamic array
    int top, MaxSize;

};


#endif //ASSIGNMENT_5_STACKT_H
