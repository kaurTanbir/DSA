#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_search_element_in_integer_array");
	setup();
		test_1_search_element_in_integer_array();
	tearDown();
	testEnded();
	testStarted("test_2_search_last_element_in_integer_array");
	setup();
		test_2_search_last_element_in_integer_array();
	tearDown();
	testEnded();
	testStarted("test_3_search_first_element_in_integer_array");
	setup();
		test_3_search_first_element_in_integer_array();
	tearDown();
	testEnded();
	testStarted("test_4_gives_NULL_if_element_is_not_present");
	setup();
		test_4_gives_NULL_if_element_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_5_search_element_in_double_array");
	setup();
		test_5_search_element_in_double_array();
	tearDown();
	testEnded();
	testStarted("test_6_search_last_element_in_double_array");
	setup();
		test_6_search_last_element_in_double_array();
	tearDown();
	testEnded();
	testStarted("test_7_search_first_element_in_double_array");
	setup();
		test_7_search_first_element_in_double_array();
	tearDown();
	testEnded();
	testStarted("test_8_gives_NULL_if_element_is_not_present");
	setup();
		test_8_gives_NULL_if_element_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_9_search_element_in_char_array");
	setup();
		test_9_search_element_in_char_array();
	tearDown();
	testEnded();
	testStarted("test_10_search_last_element_in_char_array");
	setup();
		test_10_search_last_element_in_char_array();
	tearDown();
	testEnded();
	testStarted("test_11_search_first_element_in_char_array");
	setup();
		test_11_search_first_element_in_char_array();
	tearDown();
	testEnded();
	testStarted("test_12_gives_NULL_if_element_is_not_present");
	setup();
		test_12_gives_NULL_if_element_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_13_search_element_in_char_array");
	setup();
		test_13_search_element_in_char_array();
	tearDown();
	testEnded();
	testStarted("test_14_search_last_element_in_String_array");
	setup();
		test_14_search_last_element_in_String_array();
	tearDown();
	testEnded();
	testStarted("test_15_search_first_element_in_String_array");
	setup();
		test_15_search_first_element_in_String_array();
	tearDown();
	testEnded();
	testStarted("test_16_gives_NULL_if_element_is_not_present");
	setup();
		test_16_gives_NULL_if_element_is_not_present();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
