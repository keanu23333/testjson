#include "testjson.h"
#include <assert.h> /*assert()*/
#include <stdlib.h> /*NULL*/

#define EXPECT(c,ch)  do{assert(*c->json==(ch));c->json++;}while(0)

typedef struct{
  const char* json;
}test_context;

/* ws=*(%x20 / %x09 / %x0A / %x0D) */
static void test_parse_whitespace(test_context* c){
  const char *p = c->json;
  while(*p == ' '||*p == '\t'||*p == '\n'||*p == '\r')
    p++;
  c->json=p;
}

/* null="null" */
static int test_parse_null(test_parse_context* c,test_value* v){
  EXPECT(c,'n');
  if(c->json[0]!='u'||c->json[1]!='l'||c->json[2]!='l')
    return TEST_PARSE_INVALID_VALUE;
  c->json+=3;
  v->type=TEST_NULL;
  return TEST_PARSE_OK;
}

/*value=null/false/true*/
static int test_parse_value(test_context* c,test_value* v){
  switch(*c->json){
    case 'n':return test_parse_null(c,v);
    case '\0':return TEST_PARSE_EXPECT_VALUE;
    default: return TEST_PARSE_INVALID_VALUE;
  }
}

int json_parse(const_value* v,const char* json){
  test_context c;
  assert(v !=NULL);
  c.json=json;
  v->type=TEST_NULL;
  test_parse_whitespace(&c);
  return test_parse_value(&c,v);
}
