#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definition of states
enum State{
	q0, 
	q1, 
	q2
};

//Fuction to simulate state transitions
enum State transition(enum State current_state, char input){
	switch(current_state){
		case q0:
			if(input == '1'){
				return q2;
			}else if(input == '0'){
				return q1;
			}else{
				return q0;
			}
		case q1:
			if(input == '1'){
				return q2;
			}else if(input == '0'){
				//loop back to to q1 on input '0'
				return q1;
			}else{
				return q1;
			}
		case q2:
			if(input == '0'){
				return q1;
			}else if(input == '1'){
				//loop back on q2 if input is '1'
				return q2;
			}
			return q2;
		default:
			return q0;	
	}
}

//function to check if the string is accepted by the DFA

bool accept(char *input_string){
	enum State current_state = q0;
	int i;
	for( i = 0; input_string[i] != '\0'; i++){
		current_state = transition(current_state , input_string[i]);
	}
	return current_state == q2;
}

int main(int argc, char *argv[]) {
	char *test_strings[] = {"1", "01", "111", "000", "10011"};
	int i;
	for(i = 0; i < 6; i++){
		char *test_string = test_strings[i];
		if(accept(test_string)){
			printf("%s is accepted.\n",test_string);
		}else{
			printf("%s is rejected.\n",test_string);
		}
	}
	return 0;
}
