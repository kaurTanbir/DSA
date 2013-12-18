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

	testStarted("test_push_new_element_in_integer_stack");
	setup();
		test_push_new_element_in_integer_stack();
	tearDown();
	testEnded();
	testStarted("test_increment_of_the_length_of_stack_if_stack_is_full");
	setup();
		test_increment_of_the_length_of_stack_if_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_adds_the_given_Strings_at_the_top_of_the_stack");
	setup();
		test_adds_the_given_Strings_at_the_top_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_the_top_most_element_of_stack");
	setup();
		test_pop_the_top_most_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_the_element_of_empty_stack");
	setup();
		test_pop_the_element_of_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_the_element_from_a_string_stack");
	setup();
		test_pop_the_element_from_a_string_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_most_element_of_stack");
	setup();
		test_gives_the_top_most_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_most_element_of_stack_String");
	setup();
		test_gives_the_top_most_element_of_stack_String();
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
