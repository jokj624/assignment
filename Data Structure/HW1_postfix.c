#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 100
typedef enum {
	plus,minus,times,divide,mod,eos,operand
}priority;

char token_stack[STACK_SIZE];	//postfix ��ȯ�� ������ ����
int postfix_stack[STACK_SIZE];	//postfix ���� �򰡿� ����
char infix[50] = { 0 };		//��ȯ �� postfix �ִ� ����
int token_top = -1, count = 1,sym_type, pos2=0;		//���� top, ���� ǥ�ÿ� count, ���� �򰡿� sym_type, read_item() �ε����� ���� pos2
void infix_to_postfix();	//postfix�� ��ȯ �Լ�
int eval_postfix();	//postfix �� �Լ�
void push(char sym);	//postfix ��ȯ ���ÿ� �߰�
int push_postfix(int item);		//���� �� ���ÿ� �߰�
char pop();		//postfix ��ȯ ���ÿ��� token_top ��ġ�� ���� ��ȯ
int pop_postfix();	//���� �� ���ÿ��� token_top ��ġ�� ���� ��ȯ
int precedence(char op);	//postfix ��ȯ �� ������ �켱���� ��ȯ
void print_stack();		//token_stack ���� ����Ʈ
void print_postfix_stack();		//postfix_stack ���� ����Ʈ
char read_item();	//���� �� �� infix ���ÿ��� item �о��

void main() {
	infix_to_postfix();
	printf("\n");
	eval_postfix();
}
void infix_to_postfix() {
	char expr[50],sym, token;	//���� �Է� ���� expr, expr���� ���� �޾ƿ��� token ����
	int pos = 0, i = 0;		//�ε����� ���� pos
	printf("Enter the expression :: ");
	scanf("%s", expr);
	printf("\n--------------- Status of Stack ---------------\n");
	while ((token = expr[pos++]) != '\0') {
		if (isalnum(token)) {	//token �� �ǿ������� ��
			infix[i++] = token;		//���� ��ġ i�� �ְ� �� ĭ �̵�
		}
		else {	//token�� �������� ��
			if (infix[i - 1] != ' ' && i!=0) {
				infix[i++] = ' ';	//�ǿ����� �Է� �� ���� �߰�
			}
			if (token == '(') {
				push(token);
				print_stack();	//���� ���� ���
			}
			else if (token == ')') {
				while ((sym = pop()) != '(') {	//'(' ������ ������ pop�Ͽ� infix�� ����
					infix[i] = sym;
					infix[i + 1] = ' ';		//�Է� �� ���� �߰�
					i += 2;		
				}
				print_stack();
			}
			else {	
				while (precedence(token_stack[token_top]) >= precedence(token) && token_top != -1) {	//������ �켱����
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
	while (token_top != -1) {	//���ÿ� ���� ���� �޾� ����
		infix[i] = pop();
		infix[i + 1] = ' ';
		i += 2;
	}
	print_stack();
	printf("\nPostfix = %s", infix);	//��ȯ ��� ���
}
void push(char sym) {
	if (token_top < STACK_SIZE - 1) {
		token_stack[++token_top] = sym;		//���� ��ġ���� ��ĭ �̵� �� ����
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
		return token_stack[token_top--];	//���� ��ġ ���� ��ȯ �� �̵�
	printf("token stack empty! \n");
	return ' ';
}
void print_stack() {	//���� ���� ���
	printf("%2d", count++);		//���� (������ ����� ��, �򰥷��� �־���)
	for (int j = 0; j <= token_top; j++)	
		printf("\t%c ", token_stack[j]);	
	printf("\n");
}
int eval_postfix() {
	char sym;	//infix ���� ���� �޾ƿ��� ����
	int op1, op2, pos=0;	//�ε����� ���� pos
	char stack[50];		//���� ���ڷ� �ٲٱ� ���� ���� �迭	
	printf("\n--------------- Status of Stack ---------------\n");
	sym = read_item();
	while (sym_type != eos) {
		if (sym_type == operand) {	//�ǿ������� ��
			if (sym != ' ')  //������ �ƴ� ��(���� �϶�)
				stack[pos++] = sym;
			else {
				if (stack[0]) {		//stack �迭�� ������� ������
					push_postfix(atoi(stack));	//char �迭�� ���� ���ڷ� ��ȯ�Ͽ� push
					print_postfix_stack();
					for (pos = 0; pos < 50; pos++)	stack[pos] = NULL;	//push �Ŀ��� �迭 �ʱ�ȭ
					pos = 0;
				}
			}
		}
		else {	//�������� ��
			op2 = pop_postfix();	
			op1 = pop_postfix();	//��� ���ؼ� postfix_stack���� ���� ������
			switch (sym_type) {
				case plus:		push_postfix(op1 + op2);	break;
				case minus:		push_postfix(op1 - op2);	break;
				case times:		push_postfix(op1 * op2);	break;
				case divide:	push_postfix(op1 / op2);	break;
				case mod:	push_postfix(op1 % op2);	
			}	//��� �ؼ� ���ÿ� �ٽ� �߰�
			print_postfix_stack();
		}
		sym = read_item();
	}
	printf("\nEvaluation result = %d\n", pop_postfix());	//���������� ���� ����(��� ��) ���
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