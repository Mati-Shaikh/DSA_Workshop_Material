#include "pch.h"
//#include "Header.h"
// Include your header file here

/*
	Question 2 Test Cases
*/

/*
	INFIX TO POSTFIX (using Double Linked List)
	Functions: 
	- infix_to_postfix_A
		Parameters:
		- Infix string
		- Output stack
		- Operator stack (Double Linked List)
		Return:
		- Position (length/size of the output stack)

	Note as operator stack is also checked in the next test case, do pass it by reference.
	If there are any operators remaining in the operator stack, they will be appended to the postfix string.
*/

TEST(Question2, Part_A_1) {
	DoubleLinkedList operator_stack; // Operator stack
	char output_stack[30] = {}; // Output stack
	string infix = "(A*(B/C-D)^E)+(E/F/(G+H))"; // Equation to convert from infix to postfix
	int pos = infix_to_postfix_A(infix, output_stack, operator_stack);
	// This is to empty stack contents and append it to the output string one by one
	while (!operator_stack.is_empty()) {
		string temp = operator_stack.pop();
		output_stack[pos++] = temp[0];
	}
	char expected_output[] = "ABC/D-*E^EF/GH+/+";
	for (int i = 0; output_stack[i]; i++) {
		EXPECT_EQ(output_stack[i], expected_output[i]);
	}
}

TEST(Question2, Part_A_2) {
	DoubleLinkedList operator_stack; // Operator stack
	char output_stack[30] = {}; // Output stack
	string infix = "HABCE/F/G-(H^J^K)ABCD"; // Equation to convert from infix to postfix
	int pos = infix_to_postfix_A(infix, output_stack, operator_stack);
	// First, compare the remaining operators left in the operator stack
	string expected_operators[] = { "ABC", "-" };
	for (int i = 0; !operator_stack.is_empty(); i++) {
		EXPECT_EQ(operator_stack.top(), expected_operators[i]);
		string op = operator_stack.pop();
		if (op == "ABC") {
			output_stack[pos++] = op[0];
			output_stack[pos++] = op[1];
			output_stack[pos++] = op[2];
		}
		else {
			output_stack[pos++] = op[0];
		}
	}
	// Then, compare the output string after popping the operator stack into the output stack
	char expected_output[] = "HEABCF/G/HJ^K^DABC-";
	for (int i = 0; expected_output[i]; i++) {
		EXPECT_EQ(output_stack[i], expected_output[i]);
	}
}

/*
	INFIX TO POSTFIX (using Linked List-based Queue)
	Function:
	- infix_to_postfix_B
		Parameters:
		- Infix string
		- Postfix string
		- Queue operator stack (Linked list based Queue)
		- Second Queue object
		Return:
		- None
	- second_queue_evaluator
		Parameters:
		- Infix string
		- Postfix string
		Return:
		- Queue array (size of infix string)

	Postfix string and Queue operator stack are being passed by reference in "infix_to_postfix_B".
	Postfix string is being passed by reference in "second_queue_evaluator".
*/


TEST(Question2, Part_B_1) {
	string infix = "(A+B)%C^D/(E+(F+(G-H))/I)", postfix = "";
	Queue queue_operator_stack, second_queue;
	infix_to_postfix_B(infix, postfix, queue_operator_stack, second_queue);
	while (!queue_operator_stack.is_empty()) {
		char op = queue_operator_stack.dequeue();
		EXPECT_EQ(op, '/');
		postfix += op;
	}
	string expected_output = "AB+CD^%EFGH-+I/+/";
	EXPECT_EQ(postfix, expected_output);
}

TEST(Question2, Part_B_2) {
	string infix = "(A/B)*(C*(D^E/F)-(G+H))", postfix = "";
	Queue queue_operator_stack, second_queue;
	infix_to_postfix_B(infix, postfix, queue_operator_stack, second_queue);
	while (!queue_operator_stack.is_empty()) {
		postfix += queue_operator_stack.dequeue();
	}
	EXPECT_EQ(queue_operator_stack.dequeue(), '\0');
	string expected_output = "AB/CDE^F/*GH+-*";
	EXPECT_EQ(postfix, expected_output);
}

TEST(Question2, Part_B_3) {
	string infix = "L/M+N-O*P%Q/R/S", postfix = "";
	string expected_output = "LM/N+OP*Q%R/S/-";
	/*
	The function's purpose is almost the same as "infix_to_postfix_B" - perform Infix to Prefix operation
	by using Queues. However, you also have to retrieve information about what goes in the second queue
	in each operation. That means while performing the push operation of an element, when all values of
	Queue 1 are pushed into values of Queue 2, Queue 2 is saved in an array of Queues.
	In other words, while performing Infix to Postfix, save the information of the reversed operator stack
	contained within Queue 2 (while pushing) at each step.
	*/
	Queue* second_queue_operations = second_queue_evaluator(infix, postfix);
	Queue specified_stack_1 = second_queue_operations[infix.length() - 5];
	char expected_operators_1[] = { '/', '-' };
	for (int i = 0; !specified_stack_1.is_empty(); i++) {
		EXPECT_EQ(specified_stack_1.dequeue(), expected_operators_1[i]);
	}
	Queue specified_stack_2 = second_queue_operations[infix.length() - 8];
	char expected_operators_2[] = { '*', '-' };
	for (int i = 0; !specified_stack_2.is_empty(); i++) {
		EXPECT_EQ(specified_stack_2.dequeue(), expected_operators_2[i]);
	}
}

/*
	INFIX TO PREFIX 
	Functions:
	- infix_reversal
		Parameters:
		- Infix string
		Return:
		- Reversed infix string
*/

TEST(Question2, Part_C_1) {
	string infix = "(M/N+O/P*(Q^R&S))%T", postfix = "";
	string reversed_infix = infix_reversal(infix); // This function allows for conversion from infix to postfix, and vice-versa
	EXPECT_EQ("T%((S&R^Q)*P/O+N/M)", reversed_infix);
	Queue queue_operator_stack, second_queue; // Same as in Part B, pass the reversed string to the Queue infix to postfix converter
	infix_to_postfix_B(reversed_infix, postfix, queue_operator_stack, second_queue);
	string prefix = infix_reversal(postfix);
	EXPECT_EQ("+/MN/O*P&^QRST", prefix);
}

TEST(Question2, Part_C_2) {
	string infix = "(((A/B/C)^(D%E))+F)%G", postfix = "";
	string reversed_infix = infix_reversal(infix);
	EXPECT_EQ("G%(F+((E%D)^(C/B/A)))", reversed_infix);
	Queue queue_operator_stack, second_queue;
	infix_to_postfix_B(reversed_infix, postfix, queue_operator_stack, second_queue);
	while (!queue_operator_stack.is_empty()) {
		EXPECT_EQ('%', queue_operator_stack.peek_front());
		postfix += queue_operator_stack.dequeue();
	}
	string prefix = infix_reversal(postfix); // Reverse the postfix to obtain the prefix
	EXPECT_EQ("%+^/A/BC%DEFG", prefix);
}
/*
	POSTFIX EVALUATOR
	Functions:
	- postfix_evaluation
		Parameters:
		- Postfix string
		- Array of variables (int[])
		Return:
		- Answer of computed string in integer
*/

TEST(Question2, Part_D_1) {
	string postfix = "AB+CD^%EFGH-+I/+/";
	// Assume that the values in the array below correspond in the order of appeared alphabet.
	// For instance, A = 7, B = 3, C = 2, and so on.
	int values[] = { 7, 3, 2, 5, 3, 8, 4, 5, 4 };
	int answer = postfix_evaluation(postfix, values);
	EXPECT_EQ(2, answer);
}

TEST(Question2, Part_D_2) {
	string postfix = "ABC/DE^F/GH%-%+";
	int values[] = { 4, 2441, 2, 3, 6, 5, 193, 54 };
	int answer = postfix_evaluation(postfix, values);
	EXPECT_EQ(84, answer);
}
