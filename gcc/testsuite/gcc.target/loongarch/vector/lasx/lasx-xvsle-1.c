/* { dg-do run } */
/* { dg-options "-mlasx -w -fno-strict-aliasing" } */
#include "../simd_correctness_check.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_op0, __m256i_op1, __m256i_op2, __m256i_out, __m256i_result;
  __m256 __m256_op0, __m256_op1, __m256_op2, __m256_out, __m256_result;
  __m256d __m256d_op0, __m256d_op1, __m256d_op2, __m256d_out, __m256d_result;

  int int_op0, int_op1, int_op2, int_out, int_result, i = 1, fail;
  long int long_op0, long_op1, long_op2, lont_out, lont_result;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000460086;
  *((unsigned long *)&__m256i_op0[2]) = 0x00000000007f0079;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000f30028;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000df00ff;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffff0000ffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xbf28b0686066be60;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffff00ffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffff00ff00;
  *((unsigned long *)&__m256i_result[1]) = 0x00000000ffff0000;
  *((unsigned long *)&__m256i_result[0]) = 0x00ff00ffffff00ff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x1000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x1000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0101010101010101;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0101010101010101;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x00ffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x00ffffffffffffff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x1c1b1a191c1b1a19;
  *((unsigned long *)&__m256i_op0[2]) = 0x1c1b1a191c1b1a19;
  *((unsigned long *)&__m256i_op0[1]) = 0x1c1b1a191c1b1a19;
  *((unsigned long *)&__m256i_op0[0]) = 0x1c1b1a191c1b1a19;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xb70036db12c4007e;
  *((unsigned long *)&__m256i_op0[2]) = 0xb7146213fc1e0049;
  *((unsigned long *)&__m256i_op0[1]) = 0x000000fefe02fffe;
  *((unsigned long *)&__m256i_op0[0]) = 0xb71c413b199d04b5;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffff00ff00ffff00;
  *((unsigned long *)&__m256i_result[2]) = 0xff000000ff00ff00;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffff00ffff;
  *((unsigned long *)&__m256i_result[0]) = 0xff00000000ff00ff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0001000000010000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0001000000010000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xff00ffffff00ffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xff00ffffff00ffff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xff00ff0000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0xffbfffa0ffffff80;
  *((unsigned long *)&__m256i_op0[1]) = 0xff00ff0000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0xffbfffa0ffffff80;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0xbfffa004fffd8000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0xbfffa004fffd8000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x00ff00ffff0000ff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x00ff00ffff0000ff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0a0a000000000a0a;
  *((unsigned long *)&__m256i_op0[2]) = 0x0a0a0a0a00000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0a0a000000000a0a;
  *((unsigned long *)&__m256i_op0[0]) = 0x0a0a0a0a00000000;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000ffff0000ffee;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000ffff0000ffee;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffff0000ffff0000;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffff0000ffff0000;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000001fff000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000001fff000;
  *((unsigned long *)&__m256i_op1[3]) = 0xffdfff80ffdfff80;
  *((unsigned long *)&__m256i_op1[2]) = 0xffdfff80ffdfff80;
  *((unsigned long *)&__m256i_op1[1]) = 0xffdfff80ffdfff80;
  *((unsigned long *)&__m256i_op1[0]) = 0xffdfff80ffdfff80;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x000000000000ff00;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x000000000000ff00;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x001fffffffe00000;
  *((unsigned long *)&__m256i_op0[2]) = 0x7fffffffffffffff;
  *((unsigned long *)&__m256i_op0[1]) = 0x001fffffffe00000;
  *((unsigned long *)&__m256i_op0[0]) = 0x7fffffffffffffff;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xff00ffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x00ffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xff00ffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x00ffffffffffffff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0xffff010100000001;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffff010100000001;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000ffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000ffffffffffff;
  __m256i_out = __lasx_xvsle_b (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0001000100010001;
  *((unsigned long *)&__m256i_op1[2]) = 0x0001000100010001;
  *((unsigned long *)&__m256i_op1[1]) = 0x0001000100010001;
  *((unsigned long *)&__m256i_op1[0]) = 0x0001000100010001;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_op0[2]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_op0[1]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_op0[0]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_op1[3]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_op1[2]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_op1[1]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_op1[0]) = 0x0a0a0a0a7f0a0a0a;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x7fef7fef7fef7fef;
  *((unsigned long *)&__m256i_op0[2]) = 0x7fef7fef7fef7fef;
  *((unsigned long *)&__m256i_op0[1]) = 0x7fef7fef7fef7fef;
  *((unsigned long *)&__m256i_op0[0]) = 0x7fef7fef7fef7fef;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000ff0000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000ff0000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0xffff000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0xffff000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xfffefffefffefffe;
  *((unsigned long *)&__m256i_op0[2]) = 0xfffefffefffefffe;
  *((unsigned long *)&__m256i_op0[1]) = 0xfffefffefffefffe;
  *((unsigned long *)&__m256i_op0[0]) = 0xfffefffefffefffe;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x7fffffffffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x7fffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x2aaaaa85aaaaaa85;
  *((unsigned long *)&__m256i_op1[2]) = 0x2aaa48f4aaaa48f4;
  *((unsigned long *)&__m256i_op1[1]) = 0x2aaaaa85aaaaaa85;
  *((unsigned long *)&__m256i_op1[0]) = 0x2aaa48f4aaaa48f4;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffff0000ffff;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffff0000ffff;
  __m256i_out = __lasx_xvsle_h (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000001a00000001;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000900000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000001a00000001;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000900000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x00000000ffffffff;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000083f95466;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0101010100005400;
  *((unsigned long *)&__m256i_op1[3]) = 0x007f00f8ff7fff80;
  *((unsigned long *)&__m256i_op1[2]) = 0x00000000fff6a9d8;
  *((unsigned long *)&__m256i_op1[1]) = 0x007f00f8ff7fff80;
  *((unsigned long *)&__m256i_op1[0]) = 0x00000000fff6a9d8;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffff00000000;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffff00000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000fe0100000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000fe0100000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x00000000007f0000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x00000000007f0000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x00000000ffffffff;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000100000001;
  *((unsigned long *)&__m256i_op1[2]) = 0x00197d3200197d56;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000100000001;
  *((unsigned long *)&__m256i_op1[0]) = 0x00197d3200197d56;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000fff000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000fff000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x00000000ffffffff;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x7ffe0001fffe0001;
  *((unsigned long *)&__m256i_op0[2]) = 0x7ffe0001fffeffff;
  *((unsigned long *)&__m256i_op0[1]) = 0x7fffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000fdfdfe;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffff8000;
  *((unsigned long *)&__m256i_op1[2]) = 0x7efefefe80ffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x7efefefe80ffffff;
  *((unsigned long *)&__m256i_result[3]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffff00000000;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_w (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000100000001;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000100000001;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_d (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0xff01ff01ff01ff01;
  *((unsigned long *)&__m256i_op1[2]) = 0xff01ff01ff01ff01;
  *((unsigned long *)&__m256i_op1[1]) = 0xff01ff01ff01ff01;
  *((unsigned long *)&__m256i_op1[0]) = 0xff01ff01ff01ff01;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_d (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x00f7000000f70007;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x00f7000000f70007;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_d (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_d (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xff01fffe00000001;
  *((unsigned long *)&__m256i_op0[2]) = 0xfffffffe00000001;
  *((unsigned long *)&__m256i_op0[1]) = 0xff01fffe00000001;
  *((unsigned long *)&__m256i_op0[0]) = 0xfffffffe00000001;
  *((unsigned long *)&__m256i_op1[3]) = 0x800080ff800080ff;
  *((unsigned long *)&__m256i_op1[2]) = 0x800080ff800080ff;
  *((unsigned long *)&__m256i_op1[1]) = 0x800080ff800080ff;
  *((unsigned long *)&__m256i_op1[0]) = 0x800080ff800080ff;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsle_d (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x000000000000002d;
  *((unsigned long *)&__m256i_op0[2]) = 0xc02dc02dc02dc02d;
  *((unsigned long *)&__m256i_op0[1]) = 0x000000000000002d;
  *((unsigned long *)&__m256i_op0[0]) = 0xc02dc02dc02dc02d;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffffffff;
  __m256i_out = __lasx_xvsle_d (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  return 0;
}
