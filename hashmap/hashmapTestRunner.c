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
	testStarted("test_add_an_element_to_hashmap_and_get_it");
	setup();
		test_add_an_element_to_hashmap_and_get_it();
	tearDown();
	testEnded();
	testStarted("test_gives_NULL_when_key_is_not_present");
	setup();
		test_gives_NULL_when_key_is_not_present();
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
