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

	testStarted("test_add_an_element_to_hashmap");
	setup();
		test_add_an_element_to_hashmap();
	tearDown();
	testEnded();
	testStarted("test_add_second_element_to_hashmap_in_same_bucket");
	setup();
		test_add_second_element_to_hashmap_in_same_bucket();
	tearDown();
	testEnded();
	testStarted("test_add_gives_NULL_when_hash_map_is_null");
	setup();
		test_add_gives_NULL_when_hash_map_is_null();
	tearDown();
	testEnded();
	testStarted("test_add_gives_NULL_when_key_is_null");
	setup();
		test_add_gives_NULL_when_key_is_null();
	tearDown();
	testEnded();
	testStarted("test_add_updates_the_value_of_key_if_already_present");
	setup();
		test_add_updates_the_value_of_key_if_already_present();
	tearDown();
	testEnded();
	testStarted("test_get_an_element_from_hashMap");
	setup();
		test_get_an_element_from_hashMap();
	tearDown();
	testEnded();
	testStarted("test_get_gives_NULL_when_key_is_not_present");
	setup();
		test_get_gives_NULL_when_key_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_get_gives_NULL_when_map_is_null");
	setup();
		test_get_gives_NULL_when_map_is_null();
	tearDown();
	testEnded();
	testStarted("test_get_gives_NULL_when_key_is_null");
	setup();
		test_get_gives_NULL_when_key_is_null();
	tearDown();
	testEnded();
	testStarted("test_deletes_the_value_matched_to_given_key");
	setup();
		test_deletes_the_value_matched_to_given_key();
	tearDown();
	testEnded();
	testStarted("test_deletion_failed_when_key_is_not_present");
	setup();
		test_deletion_failed_when_key_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_deleting_element_which_is_not_present");
	setup();
		test_deleting_element_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_deleting_when_key_is_null_gives_NULL");
	setup();
		test_deleting_when_key_is_null_gives_NULL();
	tearDown();
	testEnded();
	testStarted("test_deleting_when_map_is_null_gives_NULL");
	setup();
		test_deleting_when_map_is_null_gives_NULL();
	tearDown();
	testEnded();
	testStarted("test_iterating_over_hash_map");
	setup();
		test_iterating_over_hash_map();
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
