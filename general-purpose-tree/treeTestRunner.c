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

	testStarted("test_inserts_a_root_node_into_tree");
	setup();
		test_inserts_a_root_node_into_tree();
	tearDown();
	testEnded();
	testStarted("test_inserts_a_child_of_root_into_tree");
	setup();
		test_inserts_a_child_of_root_into_tree();
	tearDown();
	testEnded();
	testStarted("test_inserts_children_to_different_level");
	setup();
		test_inserts_children_to_different_level();
	tearDown();
	testEnded();
	testStarted("test_gives_iterator_to_check_childrens_data_of_a_given_parent");
	setup();
		test_gives_iterator_to_check_childrens_data_of_a_given_parent();
	tearDown();
	testEnded();
	testStarted("test_searchs_the_given_data_in_list");
	setup();
		test_searchs_the_given_data_in_list();
	tearDown();
	testEnded();
	testStarted("test_search_fails_when_data_is_not_present");
	setup();
		test_search_fails_when_data_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_deletes_the_root_from_the_tree");
	setup();
		test_deletes_the_root_from_the_tree();
	tearDown();
	testEnded();
	testStarted("test_deletion_failed_when_data_is_not_in_tree");
	setup();
		test_deletion_failed_when_data_is_not_in_tree();
	tearDown();
	testEnded();
	testStarted("test_deletes_child_of_root");
	setup();
		test_deletes_child_of_root();
	tearDown();
	testEnded();
	testStarted("test_does_not_delete_node_with_children");
	setup();
		test_does_not_delete_node_with_children();
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
