#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 100
typedef enum {
	plus,minus,times,divide,mod,eos,operand
}priority;

char token_stack[STACK_SIZE];	//postfix 변환용 연산자 스택
int postfix_stack[STACK_SIZE];	//postfix 수식 평가용 스택
char infix[50] = { 0 };		//변환 된 postfix 넣는 스택
int token_top = -1, count = 1,sym_type, pos2=0;		//스택 top, 순번 표시용 count, 수식 평가용 sym_type, read_item() 인덱스용 변수 pos2
void infix_to_postfix();	//postfix로 변환 함수
int eval_postfix();	//postfix 평가 함수
void push(char sym);	//postfix 변환 스택에 추가
int push_postfix(int item);		//수식 평가 스택에 추가
char pop();		//postfix 변환 스택에서 token_top 위치의 원소 반환
int pop_postfix();	//수식 평가 스택에서 token_top 위치의 원소 반환
int precedence(char op);	//postfix 변환 시 연산자 우선순위 반환
void print_stack();		//token_stack 상태 프린트
void print_postfix_stack();		//postfix_stack 상태 프린트
char read_item();	//수식 평가 시 infix 스택에서 item 읽어옴

void main() {
	infix_to_postfix();
	printf("\n");
	eval_postfix();
}
void infix_to_postfix() {
	char expr[50],sym, token;	//수식 입력 받을 expr, expr에서 문자 받아오는 token 변수
	int pos = 0, i = 0;		//인덱스용 변수 pos
	printf("Enter the expression :: ");
	scanf("%s", expr);
	printf("\n--------------- Status of Stack ---------------\n");
	while ((token = expr[pos++]) != '\0') {
		if (isalnum(token)) {	//token 이 피연산자일 때
			infix[i++] = token;		//현재 위치 i에 넣고 한 칸 이동
		}
		else {	//token이 연산자일 때
			if (infix[i - 1] != ' ' && i!=0) {
				infix[i++] = ' ';	//피연산자 입력 후 공백 추가
			}
			if (token == '(') {
				push(token);
				print_stack();	//스택 상태 출력
			}
			else if (token == ')') {
				while ((sym = pop()) != '(') {	//'(' 나오기 전까지 pop하여 infix에 넣음
					infix[i] = sym;
					infix[i + 1] = ' ';		//입력 후 공백 추가
					i += 2;		
				}
				print_stack();
			}
			else {	
				while (precedence(token_stack[token_top]) >= precedence(token) && token_top != -1) {	//연산자 우선순위
					infix[i] = pop();
					infix[i + 1] = ' ';
					i += 2;
				}
				push(token);
				print_stack();
			}
		} 
	}
	if (infix[i - 1] != ' ') {	
		infix[i++] = ' ';
	}
	while (token_top != -1) {	//스택에 남은 원소 받아 넣음
		infix[i] = pop();
		infix[i + 1] = ' ';
		i += 2;
	}
	print_stack();
	printf("\nPostfix = %s", infix);	//변환 결과 출력
}
void push(char sym) {
	if (token_top < STACK_SIZE - 1) {
		token_stack[++token_top] = sym;		//현재 위치에서 한칸 이동 후 넣음
	}
	else	printf("token stack full!\n");
}
int precedence(char op) {
	if (op == '(')	return 0;
	if (op == '+' || op == '-')	return 1;
	if (op == '*' || op == '/' || op == '%')	return 2;
}
char pop() {
	if (token_top >= 0)	
		return token_stack[token_top--];	//현재 위치 원소 반환 후 이동
	printf("token stack empty! \n");
	return ' ';
}
void print_stack() {	//스택 상태 출력
	printf("%2d", count++);		//순번 (스택이 비었을 때, 헷갈려서 넣었음)
	for (int j = 0; j <= token_top; j++)	
		printf("\t%c ", token_stack[j]);	
	printf("\n");
}
int eval_postfix() {
	char sym;	//infix 에서 문자 받아오는 변수
	int op1, op2, pos=0;	//인덱스용 변수 pos
	char stack[50];		//다중 숫자로 바꾸기 위해 넣을 배열	
	printf("\n--------------- Status of Stack ---------------\n");
	sym = read_item();
	while (sym_type != eos) {
		if (sym_type == operand) {	//피연산자일 때
			if (sym != ' ')  //공백이 아닐 때(숫자 일때)
				stack[pos++] = sym;
			else {
				if (stack[0]) {		//stack 배열이 비어있지 않으면
					push_postfix(atoi(stack));	//char 배열을 다중 숫자로 변환하여 push
					print_postfix_stack();
					for (pos = 0; pos < 50; pos++)	stack[pos] = NULL;	//push 후에는 배열 초기화
					pos = 0;
				}
			}
		}
		else {	//연산자일 때
			op2 = pop_postfix();	
			op1 = pop_postfix();	//계산 위해서 postfix_stack에서 원소 가져옴
			switch (sym_type) {
				case plus:		push_postfix(op1 + op2);	break;
				case minus:		push_postfix(op1 - op2);	break;
				case times:		push_postfix(op1 * op2);	break;
				case divide:	push_postfix(op1 / op2);	break;
				case mod:	push_postfix(op1 % op2);	
			}	//계산 해서 스택에 다시 추가
			print_postfix_stack();
		}
		sym = read_item();
	}
	printf("\nEvaluation result = %d\n", pop_postfix());	//마지막으로 남은 원소(결과 값) 출력
	system("pause");
	return 0;
}
int push_postfix(int item) {
	if (token_top < STACK_SIZE - 1) 
		postfix_stack[++token_top] = item;
	else	printf("Stack full\n");
}
int pop_postfix() {
	if (token_top >= 0)	return postfix_stack[token_top--];
	else	printf("Stack empty\n");
}
void print_postfix_stack() {
	for (int j = 0; j <= token_top; j++)
		printf("\t%d ", postfix_stack[j]);
	printf("\n");
}
char read_item() {
	char sym;
	sym = infix[pos2++];
	switch (sym) {
		case '+':	sym_type = plus;
			break;
		case '-':	sym_type = minus;
			break;
		case '*':	sym_type = times;
			break;
		case '/':	sym_type = divide;
			break;
		case '%':	sym_type = mod;
			break;
		case '\0':	sym_type = eos;
			break;
		default:	sym_type = operand;
	}
	return sym;
}