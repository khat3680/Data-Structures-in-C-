/*

-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-25
-------------------------------------


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "stack_array.h"






Stack* create_stack(int stack_capacity){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(stack_capacity < 1)
	{
		fprintf(stderr,"Error(create_stack): invalid capacity, set to 10\n");
		s->capacity = 10;	}
	else
		s->capacity = stack_capacity;

	s->array = (Data*)malloc(sizeof(Data)*(s->capacity));
	s->top = -1;
	return s;
}

void destroy_stack(Stack **s){
	assert(s != NULL);
	Data *data = NULL;

	while (!(is_empty_stack(*s))){
		data = pop_stack(*s);
		destroy_data(&data);

	}

	free((*s)->array);
	(*s)->array = NULL;
	(*s)->top = 0;
	(*s)->capacity = 0;
	free(*s);
	*s = NULL;

	return;

}
Data* pop_stack(Stack *s){ //O(1) : analysis
	assert(s != NULL);
	Data *d = NULL;

	if(is_empty_stack(s)){
		printf("Error(pop_stack): stack is empty\n");
		return d;
	}
	d = copy_data(&s->array[s->top]);
	Data* temp = &s->array[s->top];
	destroy_data(&temp);
	s->top--;
	return d;

}


int push_stack(Stack*s,Data* d){ // O(1) : analysis
	assert(s != NULL && d!= NULL);
	if(is_full_stack(s)){
		printf("Error(push_stack): stack is full\n");
		return False;
	}
	s->top++;
	s->array[s->top] = *copy_data(d);
	return True;
}

void print_stack(Stack *s){ // O(n) : Analysis
	assert(s != NULL);
	printf("Stack Size = %d\n",len_stack(s));

	if(is_empty_stack(s))
		printf("<empty_stack>\n");

	for(int i = s->top;i>=0;i--)
	{
		print_data(&s->array[i]);
		printf("\n");
	}
}
Data* peek_stack(Stack *s){ // O(1) : Analysis
	assert(s != NULL);
	if(is_empty_stack(s))	{
		printf("Error(peek_stack): stack is empty\n");
		return NULL;
	}
	return copy_data(&(s->array[s->top]));
}

int len_stack(Stack *s) {
	assert(s!=NULL);
	return s->top +1;
}

int is_empty_stack(Stack *s) {
	assert(s!=NULL);
	return(s->top == -1);

}
int is_full_stack(Stack *s) {
	assert(s!=NULL);
	return (s->top == s->capacity - 1);
}
Stack* copy_stack(Stack *s){
	assert(s != NULL);
	Stack *s2 = create_stack(s->capacity);
	int i,size = len_stack(s);
	Data* array = (Data*)malloc(sizeof(Data)*size);

	for(i=0;i<size;i++)
		array[i] = *pop_stack(s);

	for(i=size-1 ;i>=0;i--){
		push_stack(s,&array[i]);
		push_stack(s2,&array[i]);

	}

	free(array);

	return  s2;
}
*/


string: '{"body":{
				"policies":
			[{"detail":
		{"policyInformation":{"policyType":{"code":"AU","description":"Auto"},
																"termEffectiveDate":"20180216","termExpirationDate":"20190216",
																"premiumInformation":null,
																"policyHolders":[{
		"givenName":"STEPHANIEOHZIFV","middleName":null,"surname":"BLUNTOHZIFV","nameSuffix":null,"dob":"19350204","dlNumber":"OB390442","dlState":"OH"}],
		"phoneNumbers":null,"fromDate":null,"toDate":null}



		,"subjects":[{"driverSequenceId":"0","givenName":"STEPHANIEOHZIFV","middleName":null,"surname":"BLUNTOHZIFV","nameSuffix":null,"dob":"19350204","ssn":null,"gender":"F","maritalStatus":"W","dlNumber":"OB390442","dlState":"OH","relationToPolicyHolder":
		{"code":"PP","description":"Primary
		}
        Policyholder"},"relationToInsured":{"code":"I","description":"Insured"},"fromDate":"20180816","toDate":"20190216"}],"
        		"carrier":{"financialAMBEST":"99999","name":"INSURANCE
        SERVICES O","ambest":"99999","naic":"00000"},"mailingAddress":{"fromDate":"20180816","toDate":"20190216","street1":"1417
        Ridgecrest Dr","street2":null,"city":"Cincinnati","stateCode":"OH","zip":"45206","countryCode":"US"},"coverages":[{"coverageType":{"code":"BINJ","description":"Bodily
        Injury"},"individualLimitAmount":"10000","occurrenceLimitAmount":"25000","combinedSingleLimitAmount":"0","fromDate":"20180816","toDate":"20190216"},{"coverageType":{"code":"PINJ","description":"Personal
        Injury"},"individualLimitAmount":"25000","occurrenceLimitAmount":"50000","combinedSingleLimitAmount":"0","fromDate":"20180816","toDate":"20190216"}],"
        		""
        		""
        		""
        		""
        		""vehicles":[{"year":"1991","make":"ACURA","model":"INTEGRA","vin":"C4RV1N3X4MPL30001","classCode":"000000","businessUse":null,"territoryCode":null,"collisionDeductibleAmount":"1000","comprehensiveDeductibleAmount":"500","fromDate":"20180816","toDate":"20190216","collisionIndicator":"N","collisionIndividualLimitAmount":null,"collisionOccurenceLimitAmount":null,"comprehensiveIndicator":"N","comprehensiveIndividualLimitAmount":null,"comprehensiveOccurenceLimitAmount":null,"coverages":[{"coverageType":{"code":"BINJ","description":"Bodily
        Injury"},"individualLimitAmount":"10000","occurrenceLimitAmount":"25000","combinedSingleLimitAmount":"0","fromDate":"20180816","toDate":"20190216"},{"coverageType":{"code":"PINJ","description":"Personal
        Injury"},"individualLimitAmount":"25000","occurrenceLimitAmount":"50000","combinedSingleLimitAmount":"0","fromDate":"20180816","toDate":"20190216"}]}],"
        		""
        		""
        		""garageLocations":null,"financeInformations":null},"history":{"policyInformations":[{"policyType":{"code":"AU","description":"Auto"},"termEffectiveDate":null,"termExpirationDate":null,"premiumInformation":null,"policyHolders":[{"givenName":"STEPHANIEOHZIFV","middleName":null,"surname":"BLUNTOHZIFV","nameSuffix":null,"dob":"19350204","dlNumber":"OB390442","dlState":"OH"}],"phoneNumbers":null,"fromDate":"20170216","toDate":"20180816"}],"subjects":[{"driverSequenceId":"1","givenName":"STEPHANIEOHZIFV","middleName":null,"surname":"BLUNTOHZIFV","nameSuffix":null,"dob":"19350204","ssn":null,"gender":"F","maritalStatus":"W","dlNumber":"OB390442","dlState":"OH","relationToPolicyHolder":{"code":"PP","description":"Primary
        Policyholder"},"relationToInsured":{"code":"I","description":"Insured"},"fromDate":"20180216","toDate":"20180816"},{"driverSequenceId":"1","givenName":"STEPHANIEOHZIFV","middleName":"G","surname":"BLUNTOHZIFV","nameSuffix":null,"dob":"19350204","ssn":null,"gender":"F","maritalStatus":"M","dlNumber":"YB627931","dlState":"OH","relationToPolicyHolder":{"code":"SP","description":"Secondary
        Policyholder"},"relationToInsured":{"code":"S","description":"Spouse"},"fromDate":"20170316","toDate":"20180216"},{"driverSequenceId":"0","givenName":"ANDREWOHZIFV","middleName":"A","surname":"BLUNTOHZIFV","nameSuffix":null,"dob":"19281019","ssn":null,"gender":"M","maritalStatus":"M","dlNumber":"MT216600","dlState":"OH","relationToPolicyHolder":{"code":"PP","description":"Primary
        Policyholder"},"relationToInsured":{"code":"I","description":"Insured"},"fromDate":"20170216","toDate":"20180216"}],"mailingAddresses":[{"fromDate":"20170216","toDate":"20180816","street1":"1816
        Waterford Ln","street2":null,"city":"Cincinnati","stateCode":"OH","zip":"45206","countryCode":"US"}],"coverages":[{"coverageType":{"code":"BINJ","description":"Bodily
        Injury"},"individualLimitAmount":"10000","occurrenceLimitAmount":"25000","combinedSingleLimitAmount":"0","fromDate":"20170216","toDate":"20180816"},{"coverageType":{"code":"PINJ","description":"Personal
        Injury"},"individualLimitAmount":"25000","occurrenceLimitAmount":"50000","combinedSingleLimitAmount":"0","fromDate":"20170216","toDate":"20180816"}],"vehicles":[{"year":"1991","make":"ACURA","model":"INTEGRA","vin":"C4RV1N3X4MPL30001","classCode":"000000","businessUse":null,"territoryCode":null,"collisionDeductibleAmount":"1000","comprehensiveDeductibleAmount":"500","fromDate":"20170216","toDate":"20180816","collisionIndicator":"N","collisionIndividualLimitAmount":null,"collisionOccurenceLimitAmount":null,"comprehensiveIndicator":"N","comprehensiveIndividualLimitAmount":null,"comprehensiveOccurenceLimitAmount":null,"coverages":[{"coverageType":{"code":"BINJ","description":"Bodily
        Injury"},"individualLimitAmount":"10000","occurrenceLimitAmount":"25000","combinedSingleLimitAmount":"0","fromDate":"20170216","toDate":"20180816"},{"coverageType":{"code":"PINJ","description":"Personal
        Injury"},"individualLimitAmount":"25000","occurrenceLimitAmount":"50000","combinedSingleLimitAmount":"0","fromDate":"20170216","toDate":"20180816"}]}],"garageLocations":null,"financeInformations":null,"transactionInformations":[{"transactionType":{"code":"NB","description":"New
        Business"},"effectiveDate":"20170216"},{"transactionType":{"code":"ED","description":"Endorsement"},"effectiveDate":"20170316"},{"transactionType":{"code":"RW","description":"Renewal"},"effectiveDate":"20180216"}]},"policyNumber":"OHVRSK2017112013","policyStatus":"EXPIRED","policyReportedDate":"20180517","inceptionDate":"20170216","lastReportedTermEffectiveDate":"20180216","lastReportedTermExpirationDate":"20190216","numberOfCancellations":"0","numberOfRenewals":"1","cancellationDate":null,"disputeStatement":null,"matchBasisInformation":{"matchScore":"100","searchType":{"code":"P","description":"Person"},"matchReasons":["NAME
        IS IDENTICAL","ADDRESS IS IDENTICAL","ZIP IS IDENTICAL"]}}],"coverageLapseInformation":[{"coverageIntervals":[{"carrier":{"financialAMBEST":"99999","name":"INSURANCE
        SERVICES O","ambest":"99999","naic":null},"startDate":"20170316","endDate":"20190216","numberOfCoverageDays":"702","hasBreakFromPriorCoverage":"NA","numberOfLapseDays":"0"}],"givenName":"StephanieOHZIFV","middleName":null,"surname":"BluntOHZIFV","nameSuffix":null,"inputDriverSequenceNumber":"1","hasPossibleLapse":"N","isCurrentInforceCoverage":"N"}],"customElements":null},"header":{"transactionId":"fd4892a1-660b-4c08-bbf3-d49447ff501b","quoteback":"6556"}}'
    http_version:
  recorded_at: Wed, 05 Feb 2020 22:25:25 GMT


  cut
