#ifndef __ASSERT_H_
#define __ASSERT_H_

void assertEquals (int a, int b);

void assertFloatEquals (float a, float b);

void assertStrEquals (char *a, char *b);

void assertNotNull (void* notNullable);

void assertNull (void* nullable);

void print_test_results ();

#endif
