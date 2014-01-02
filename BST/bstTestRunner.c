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

	testStarted("test_insert_root_of_the_tree");
	setup();
		test_insert_root_of_the_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_child_to_root");
	setup();
		test_insert_child_to_root();
	tearDown();
	testEnded();
	testStarted("test_insert_leftchild_and_rightchild_to_root");
	setup();
		test_insert_leftchild_and_rightchild_to_root();
	tearDown();
	testEnded();
	testStarted("test_does_not_insert_duplicate_value_in_tree");
	setup();
		test_does_not_insert_duplicate_value_in_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_multiple_node_to_tree");
	setup();
		test_insert_multiple_node_to_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_multiple_node_to__left_of_tree");
	setup();
		test_insert_multiple_node_to__left_of_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_multiple_node_to__right_of_tree");
	setup();
		test_insert_multiple_node_to__right_of_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_struct_as_root_of_the_tree");
	setup();
		test_insert_struct_as_root_of_the_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_struct_as_child_to_root");
	setup();
		test_insert_struct_as_child_to_root();
	tearDown();
	testEnded();
	testStarted("test_get_child_of_nonexisting_parentData");
	setup();
		test_get_child_of_nonexisting_parentData();
	tearDown();
	testEnded();
	testStarted("test_searching_root_in_tree");
	setup();
		test_searching_root_in_tree();
	tearDown();
	testEnded();
	testStarted("test_search_child_of_existing_parentData");
	setup();
		test_search_child_of_existing_parentData();
	tearDown();
	testEnded();
	testStarted("test_search_in_tree");
	setup();
		test_search_in_tree();
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
