#include "testUtils.h"
#include "brackets.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_matchs_all_brackets_of_input_string(){
        char* input = "[{(aaa)ddd}]";
        int result;
        result = doesBracketsMatch(input);
        ASSERT(1 == result);
};
void test_2_matchs_all_brackets_of_input_string(){
        char* input = "[{(aaaddd}]";
        int result;
        result = doesBracketsMatch(input);
        ASSERT(0 == result);
};