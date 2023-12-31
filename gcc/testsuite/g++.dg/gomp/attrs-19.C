// { dg-do compile { target c++11 } }

void foo1 ();

void
foo ()
{
  [[omp::decl (declare variant (foo1) match (construct={parallel,for}))]]
  extern void foo2 ();
  [[omp::sequence (directive (parallel), directive (for))]]
  for (int i = 0; i < 5; i++)
    foo2 ();
  [[omp::decl (declare simd simdlen(4) linear(l) aligned(p:4) uniform(p) inbranch),
    omp::directive (declare simd simdlen(8) notinbranch)]]
  extern int foo3 (int l, int *p);
  [[omp::directive (declare simd simdlen(4) linear(l) aligned(p:4) uniform(p) inbranch),
    omp::decl (declare simd simdlen(8) notinbranch)]]
  extern int foo4 (int l, int *p);
  [[omp::decl (declare simd simdlen(4) linear(l) aligned(p:4) uniform(p) inbranch),
    omp::decl (declare simd simdlen(8) notinbranch)]]
  extern int foo5 (int l, int *p);
}

void bar1 ();

void
bar ()
{
  [[using omp : decl (declare variant (bar1), match (construct={parallel,for}))]]	// { dg-warning "attribute using prefix only available with" "" { target c++14_down } }
  extern void bar2 ();
  [[using omp : sequence (directive (parallel), directive (for))]]			// { dg-warning "attribute using prefix only available with" "" { target c++14_down } }
  for (int i = 0; i < 5; i++)
    bar2 ();
  [[omp::decl (declare simd, simdlen(4), linear(l), aligned(p:4),uniform(p),inbranch),
    omp::directive (declare simd simdlen(8) notinbranch)]]
  extern int bar3 (int l, int *p);
  [[using omp : directive (declare simd,simdlen(4),linear(l),aligned(p:4),uniform(p),inbranch),	// { dg-warning "attribute using prefix only available with" "" { target c++14_down } }
    decl (declare simd, simdlen(8), notinbranch)]]
  extern int bar4 (int l, int *p);
  [[omp::decl (declare simd, simdlen(4), linear(l), aligned(p:4), uniform(p), inbranch),
    omp::decl (declare simd, simdlen(8), notinbranch)]]
  extern int bar5 (int l, int *p);
}

struct S { S (); ~S (); int s; };

[[omp::decl (threadprivate)]] int t1, t2;
int x1, t3 [[omp::decl (threadprivate)]], x2, t4 [[omp::decl (threadprivate)]] [5];
[[maybe_unused, omp::decl (threadprivate)]] int t5, t6;
[[using omp : decl (threadprivate)]] S t7, t8;	// { dg-warning "attribute using prefix only available with" "" { target c++14_down } }
[[using omp : decl (declare target enter device_type (host))]] int d1, d2, d3 (int, int), d4;	// { dg-warning "attribute using prefix only available with" "" { target c++14_down } }
int x3, d5 [[omp::decl (declare target, enter, device_type (any))]], d6 [[omp::decl (declare target link)]], x4;
int d7 [[omp::decl (declare target)]];
[[using omp : decl (declare target), decl (declare target)]] int d8, d9;	// { dg-warning "attribute using prefix only available with" "" { target c++14_down } }

void
baz ()
{
  [[omp::decl (threadprivate)]] static int t1, t2;
  static int x1, t3 [[omp::decl (threadprivate)]], x2, t4 [[omp::decl (threadprivate)]] [5];
  [[maybe_unused, omp::decl (threadprivate)]] extern int t5, t6;
  [[using omp : decl (declare target enter)]] extern int d1, d2, d3 (int, int), d4;		// { dg-warning "attribute using prefix only available with" "" { target c++14_down } }
  static int x3, d5 [[omp::decl (declare target, enter, device_type (any))]], d6 [[omp::decl (declare target link)]], x4;
  ++t1; ++t2;
  ++t3; ++t4[2];
  ++t5; ++t6;
  ++d1;
}
