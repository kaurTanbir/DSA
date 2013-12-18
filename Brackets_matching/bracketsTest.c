#include "testUtils.h"
#include "brackets.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_bracket_match_with_correct_input(){
        const char* input = "{[()]}";
        ASSERT(1 == doesBracketsMatch(input));
}

// void test_bracket_match_with_one_less_closing_bracket(){
//         const char* input = "{[(()]}";
//         ASSERT(0 == doesBracketsMatch(input));
// }

// void test_bracket_match_with_just_one_bracket(){
//         const char* input = ")";
//         ASSERT(0 == doesBracketsMatch(input));
// }
// void test_bracket_match_with_miss_match_const char*(){
//         const char* input = "){{{[]]";
//         ASSERT(0 == doesBracketsMatch(input));
// }

// void test_bracket_match_with_one_extra_closing_brackets(){
//         const char* input = "{[()])}";
//         ASSERT(0 == doesBracketsMatch(input));
// }
// void test_bracket_match_with_empty_string(){
//         const char* input = "";
//         ASSERT(1 == doesBracketsMatch(input));
// }
// void test_bracket_match_opposite_parenthesis(){
//         const char* input = ")(";
//         ASSERT(0 == doesBracketsMatch(input));
// }
// void test_same_type_of_brackets_closing_and_opening_simultanously(){
//         const char* input = "{}()[]";
//         ASSERT(1 == doesBracketsMatch(input));
// }
// void test_bracket_match(){
//         const char* input = "{()}[]";
//         ASSERT(1 == doesBracketsMatch(input));
// }