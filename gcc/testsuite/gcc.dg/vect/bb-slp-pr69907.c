/* { dg-do compile } */
/* Disable for vectorization using partial vectors since it would have only
   one iteration left, consequently BB vectorization won't happen.  */
/* { dg-additional-options "-O3 --param=vect-partial-vector-usage=0" } */
/* { dg-require-effective-target vect_unpack } */

#include "tree-vect.h"

#if VECTOR_BITS > 512
#define N (VECTOR_BITS * 10 / 16)
#else
#define N 320
#endif

void foo(unsigned *p1, unsigned short *p2)
{
  int n;
  for (n = 0; n < N; n++)
    p1[n] = p2[n * 2];
}

/* Disable for SVE because for long or variable-length vectors we don't
   get an unrolled epilogue loop.  Also disable for AArch64 Advanced SIMD,
   because there we can vectorize the epilogue using mixed vector sizes.
   Likewise for AMD GCN and RVV.  */
/* { dg-final { scan-tree-dump "BB vectorization with gaps at the end of a load is not supported" "slp1" { target { { ! aarch64*-*-* } && { { ! amdgcn*-*-* } && { ! riscv_v } } } } } } */
