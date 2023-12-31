/* Test C23 variadic functions with no named parameters.  Compilation tests,
   valid code, verify not considered unprototyped functions.  */
/* { dg-do compile } */
/* { dg-options "-std=c23 -pedantic-errors -Wstrict-prototypes -Wold-style-definition" } */

int f (...);
int g (int (...));
int h (...) { return 0; }

typedef int A[];
typedef int A2[2];

A *f1 (...);
A2 *f1 (...);
A *f1 (...) { return 0; }

A2 *f2 (...);
A *f2 (...);
A2 *f2 (...) { return 0; }
typeof (f1) f2;

int t () { return f () + f (1) + f (1, 2) + h () + h (1.5, 2, f1) + g (f); }
