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

	testStarted("test_sorts_array_of_Integers_odd_");
	setup();
		test_sorts_array_of_Integers_odd_();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_of_Integers_even_");
	setup();
		test_sorts_array_of_Integers_even_();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_of_doubles");
	setup();
		test_sorts_array_of_doubles();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_of_Characters");
	setup();
		test_sorts_array_of_Characters();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_of_String");
	setup();
		test_sorts_array_of_String();
	tearDown();
	testEnded();
	testStarted("test_sorts_Accounts_according_to_account_number");
	setup();
		test_sorts_Accounts_according_to_account_number();
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
