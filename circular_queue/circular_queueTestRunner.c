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

	testStarted("test_inserts_an_Integer_element_in_queue");
	setup();
		test_inserts_an_Integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserts_a_double_element_in_queue_at_rear_end");
	setup();
		test_inserts_a_double_element_in_queue_at_rear_end();
	tearDown();
	testEnded();
	testStarted("test_inserts__characters_in_queue_at_rear_end");
	setup();
		test_inserts__characters_in_queue_at_rear_end();
	tearDown();
	testEnded();
	testStarted("test_inserts_String_elements_in_queue_at_rear_end");
	setup();
		test_inserts_String_elements_in_queue_at_rear_end();
	tearDown();
	testEnded();
	testStarted("test_returns_0_if_trying_to_enqueue_in_a_full_queue");
	setup();
		test_returns_0_if_trying_to_enqueue_in_a_full_queue();
	tearDown();
	testEnded();
	testStarted("test_returns_1_if_enqueued_in_the_stack");
	setup();
		test_returns_1_if_enqueued_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_returns_null_if_trying_to_dequeue_from_an_empty_queue");
	setup();
		test_returns_null_if_trying_to_dequeue_from_an_empty_queue();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
