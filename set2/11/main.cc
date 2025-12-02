#include "main.ih"


int main()
{
    catchByRef();
    std::cout << '\n';
    catchByVal();
    std::cout << '\n';
    catchRethrow();
}

// Annotated output:
// Showcase catch by ref:
// Obj with ident 1 constructed
// copy no. 1 made for obj w/ ident 1
// Caught by ref
// Caught Copy no. 1

// Showcase catch by val:
// Obj with ident 1 constructed
// copy no. 1 made for obj w/ ident 1
// copy no. 2 made for obj w/ ident 1
// Caught by val
// Caught Copy no. 2

// Showcase rethrow
// Obj with ident 1 constructed
// copy no. 1 made for obj w/ ident 1
// Caught throw by ref in rethrow
// Caught Copy no. 1
// Caught rethrow by ref
// Caught Copy no. 1