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

	testStarted("test_1_creates_a_queue_of_integers");
	setup();
		test_1_creates_a_queue_of_integers();
	tearDown();
	testEnded();
	testStarted("test_2_creates_a_queue_of_doubles");
	setup();
		test_2_creates_a_queue_of_doubles();
	tearDown();
	testEnded();
	testStarted("test_3_creates_a_queue_of_characters");
	setup();
		test_3_creates_a_queue_of_characters();
	tearDown();
	testEnded();
	testStarted("test_4_creates_a_queue_of_strings");
	setup();
		test_4_creates_a_queue_of_strings();
	tearDown();
	testEnded();
	testStarted("test_5_inserts_an_Integer_element_in_queue");
	setup();
		test_5_inserts_an_Integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_6_inserts_an_double_element_in_queue");
	setup();
		test_6_inserts_an_double_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_7_inserts__characters_in_queue_at_rear_end");
	setup();
		test_7_inserts__characters_in_queue_at_rear_end();
	tearDown();
	testEnded();
	testStarted("test_8_inserts_String_elements_in_queue_at_rear_end");
	setup();
		test_8_inserts_String_elements_in_queue_at_rear_end();
	tearDown();
	testEnded();
	testStarted("test_9_returns_0_if_trying_to_enqueue_in_a_full_queue");
	setup();
		test_9_returns_0_if_trying_to_enqueue_in_a_full_queue();
	tearDown();
	testEnded();
	testStarted("test_10_returns_1_if_enqueued_in_the_stack");
	setup();
		test_10_returns_1_if_enqueued_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_11_if_queue_is_full_returns_1");
	setup();
		test_11_if_queue_is_full_returns_1();
	tearDown();
	testEnded();
	testStarted("test_12_if_queue_is_not_full_returns_0");
	setup();
		test_12_if_queue_is_not_full_returns_0();
	tearDown();
	testEnded();
	testStarted("test_13_if_rear_and_front_are_coresponding_to_eachother_queue_is_full");
	setup();
		test_13_if_rear_and_front_are_coresponding_to_eachother_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_14_dequeues_the_first_element_of_queue_of_integers");
	setup();
		test_14_dequeues_the_first_element_of_queue_of_integers();
	tearDown();
	testEnded();
	testStarted("test_15_dequeues_the_first_element_of_queue_of_doubles");
	setup();
		test_15_dequeues_the_first_element_of_queue_of_doubles();
	tearDown();
	testEnded();
	testStarted("test_16_dequeues_the_first_element_of_queue_of_characters");
	setup();
		test_16_dequeues_the_first_element_of_queue_of_characters();
	tearDown();
	testEnded();
	testStarted("test_17_dequeues_the_first_element_of_queue_of_strings");
	setup();
		test_17_dequeues_the_first_element_of_queue_of_strings();
	tearDown();
	testEnded();
	testStarted("test_18_returns_null_if_trying_to_dequeue_from_an_empty_queue");
	setup();
		test_18_returns_null_if_trying_to_dequeue_from_an_empty_queue();
	tearDown();
	testEnded();
	testStarted("test_19_if_queue_is_empty_returns_1");
	setup();
		test_19_if_queue_is_empty_returns_1();
	tearDown();
	testEnded();
	testStarted("test_20_if_queue_is_not_empty_returns_0");
	setup();
		test_20_if_queue_is_not_empty_returns_0();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
