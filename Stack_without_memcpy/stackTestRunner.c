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

	testStarted("test_creates_a_stack_for_with_given_length");
	setup();
		test_creates_a_stack_for_with_given_length();
	tearDown();
	testEnded();
	testStarted("test_adds_the_given_integer_to_the_stack");
	setup();
		test_adds_the_given_integer_to_the_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_the_given_doubles_to_the_stack");
	setup();
		test_adds_the_given_doubles_to_the_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_the_given_characters_to_the_stack");
	setup();
		test_adds_the_given_characters_to_the_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_the_given_Strings_at_the_top_of_the_stack");
	setup();
		test_adds_the_given_Strings_at_the_top_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_doubles_the_length_of_stack_if_stack_is_full");
	setup();
		test_doubles_the_length_of_stack_if_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_removes_the_topmost_integer_from_the_stack");
	setup();
		test_removes_the_topmost_integer_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_removes_the_top_most_double_element_from_the_stack");
	setup();
		test_removes_the_top_most_double_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_removes_the_top_most_character_from_the_stack");
	setup();
		test_removes_the_top_most_character_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_returns_null_when_deleted_from_empty_stack");
	setup();
		test_returns_null_when_deleted_from_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_most_integer");
	setup();
		test_gives_the_top_most_integer();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_most_double");
	setup();
		test_gives_the_top_most_double();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_most_character");
	setup();
		test_gives_the_top_most_character();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_most_element_from_the_stack_Strings");
	setup();
		test_gives_the_top_most_element_from_the_stack_Strings();
	tearDown();
	testEnded();
	testStarted("test_returns_null_when_trying_access_the_element_if_top_is_zero");
	setup();
		test_returns_null_when_trying_access_the_element_if_top_is_zero();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_empty");
	setup();
		test_tells_the_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_not_empty");
	setup();
		test_tells_the_stack_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_full_integers");
	setup();
		test_tells_the_stack_is_full_integers();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_not_full");
	setup();
		test_tells_the_stack_is_not_full();
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
