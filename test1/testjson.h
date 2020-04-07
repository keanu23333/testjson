#ifndef TESTJSON_H
#define TESTJSON_H

typedef enum { TEST_NULL, TEST_FALSE, TEST_TRUE, TEST_NUMBER, TEST_STRING, TEST_ARRAY, TEST_OBJECT } test_type;

typedef struct {
  test_type type;
}test_value;

enum{
  TEST_PARSE_OK = 0,
  TEST_PARSE_EXPECT_VALUE,
  TEST_PARSE_INVALID_VALUE,
  TEST_PARSE_ROOT_NOT_SINGULAR
};

int test_parsr(test_value* v, const char* json);

test_type test_get_type(const test_value* v);

#endif /*TESTJSON_H__*/
