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

	testStarted("test_gives_an_Doubly_link_list_with_head_NULL");
	setup();
		test_gives_an_Doubly_link_list_with_head_NULL();
	tearDown();
	testEnded();
	testStarted("test_create_node");
	setup();
		test_create_node();
	tearDown();
	testEnded();
	testStarted("test_inserts_an_element_at_begining_of_list");
	setup();
		test_inserts_an_element_at_begining_of_list();
	tearDown();
	testEnded();
	testStarted("test_inserts_element_at_the_end_of_linkList");
	setup();
		test_inserts_element_at_the_end_of_linkList();
	tearDown();
	testEnded();
	testStarted("test_adds_element_in_middle_of_linkList");
	setup();
		test_adds_element_in_middle_of_linkList();
	tearDown();
	testEnded();
	testStarted("test_deletes_first_element_in_list");
	setup();
		test_deletes_first_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_deletes_last_element_in_the_list");
	setup();
		test_deletes_last_element_in_the_list();
	tearDown();
	testEnded();
	testStarted("test_deletes_element_in_between_the_list");
	setup();
		test_deletes_element_in_between_the_list();
	tearDown();
	testEnded();
	testStarted("test_hasnext_of_getiterator_gives_true_if_list_not_empty");
	setup();
		test_hasnext_of_getiterator_gives_true_if_list_not_empty();
	tearDown();
	testEnded();
	testStarted("test_hasnext_of_getiterator_gives_false_if_list_not_empty");
	setup();
		test_hasnext_of_getiterator_gives_false_if_list_not_empty();
	tearDown();
	testEnded();
	testStarted("test_next_of_getiterator_gives_next_data");
	setup();
		test_next_of_getiterator_gives_next_data();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
