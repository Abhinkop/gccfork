/* Test DFP macros defined in <float.h> with DFP support.  TS 18661-2
   feature test macro causes same macros to be defined as for C23.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */

#define __STDC_WANT_IEC_60559_DFP_EXT__

#include "c23-float-dfp-1.c"
