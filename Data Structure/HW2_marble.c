#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct node_type *node_ptr;
struct node_type {
	int id;
	char name[10];
	int price;
	int owner;
	node_ptr llink;
	node_ptr rlink;
};	//도시 구조체
struct player_type {
	int id;
	char name;
	int balance;
	int direction;
	int assets;		//자산 변수 추가
	node_ptr node_pos;
}Player[2]; //player 구조체
node_ptr head;
node_ptr append_city(node_ptr target);
void show_info(node_ptr node);
void move_player(int id);	//player id 전달
void show_action_menu(int id);
int p1, p2 = 0;		//player 2명 각각 몇번 순환하였는지 체크하는 변수
void main() {
	node_ptr node1, node2, node3, node4, node5, node6, node7, node8, node9, node10, temp;
	int count = 0, num, i;	//순서 확인을 위한 count 변수, menu 선택 변수 num, for문 변수 i
	head = (node_ptr)malloc(sizeof(struct node_type));	// home 생성
	Player[0].node_pos = (node_ptr)malloc(sizeof(struct node_type));	//node_pos 생성
	Player[1].node_pos = (node_ptr)malloc(sizeof(struct node_type));
	head->price = 0;	//head 노드 입력
	head->owner = -1;
	head->id = 0;
	strcpy_s(head->name, 10, "Home");
	Player[0].id = 0;	//player 구조체 정보 입력
	Player[1].id = 1;
	Player[0].balance = 3000;
	Player[1].balance = 3000;
	Player[0].direction = 1;
	Player[1].direction = 1;
	Player[0].assets = 0;
	Player[1].assets = 0;
	Player[0].node_pos = head;
	Player[1].node_pos = head;
	node1 = append_city(head);	//도시 노드 추가, 링크 연결
	node2 = append_city(node1);
	node3 = append_city(node2);
	node4 = append_city(node3);
	node5 = append_city(node4);
	node6 = append_city(node5);
	node7 = append_city(node6);
	node8 = append_city(node7);
	node9 = append_city(node8);	
	node10 = append_city(node9);	
	head->llink = node10;
	node10->rlink = head;	//헤드노드와 첫, 끝 노드 연결
	for (temp = node1; temp != head; temp = temp->rlink)	temp->owner = -1;	//모든 도시 owner -1로 초기화
	temp = node1;	//도시 id 입력
	for (i = 0; i < 10; i++) {
		temp->id = i+1;
		temp = temp->rlink;
	}
	strcpy_s(node1->name, 10, "Tokyo");	//도시 이름, 가격 정보 입력
	node1->price = 1000;
	strcpy_s(node2->name, 10, "Hanoi");
	node2->price = 1300;
	strcpy_s(node3->name, 10, "HongKong");
	node3->price = 1500;
	strcpy_s(node4->name, 10, "Santiago");
	node4->price = 1700;
	strcpy_s(node5->name, 10, "Seoul");
	node5->price = 2000;
	strcpy_s(node6->name, 10, "NewYork");
	node6->price = 2200;
	strcpy_s(node7->name, 10, "Helsinki");
	node7->price = 2300;
	strcpy_s(node8->name, 10, "London");
	node8->price = 2500;
	strcpy_s(node9->name, 10, "Berlin");
	node9->price = 2700;
	strcpy_s(node10->name, 10, "Paris");
	node10->price = 3000;
	while (1) {
		show_info(head);
		printf("-------------------------------------\n");
		printf("\n1. Throw Dice\n");
		printf("2. Show City Info\n");
		printf("3. Exit\n");
		if (!(count % 2))	printf("\nplayer[0]. Choose a menu : ");
		else	printf("\nPlayer[1]. Choose a menu : ");
		scanf_s("%d", &num);
		if (num == 1)	move_player(Player[count % 2].id);	//move 함수 test용 코드
		else if (num == 2)	show_info(head);
		else	break;
		count++;
		if ((Player[0].balance <= 0) || (Player[1].balance <= 0)) {		//잔고가 0이 되면
			for (temp = node1; temp != head; temp = temp->rlink) {
				if (temp->owner == Player[0].id)		Player[0].assets += temp->price;	
				else if(temp->owner == Player[1].id)	Player[1].assets += temp->price;
			}
			Player[0].assets += Player[0].balance;
			Player[1].assets += Player[1].balance;	//남은 잔고 더해줌
			Player[0].assets > Player[1].assets ? printf("\nGame over!\tPlayer [0] Win!\n") : printf("\nGame over!\tPlayer [1] Win!\n");
			if (Player[0].assets == Player[1].assets)	printf("\nGame over!!\t The game ended in a draw!\n");
			break;
		}
		else if ((p1 == 5) || (p2 == 5)) {		//최대 순환 횟수 5회 
			for (temp = node1; temp != head; temp = temp->rlink) {
				if (temp->owner == Player[0].id)		Player[0].assets += temp->price;
				else if(temp->owner == Player[1].id)	Player[1].assets += temp->price;
			}
			Player[0].assets += Player[0].balance;
			Player[1].assets += Player[1].balance;
			Player[0].assets > Player[1].assets ? printf("\nGame over!\tPlayer [0] Win!\n") : printf("\nGame over!\tPlayer [1] Win!\n");
			if (Player[0].assets == Player[1].assets)	printf("\nGame over!!\t The game ended in a draw!\n");
			break;
		}
	}
	system("pause");
}
node_ptr append_city(node_ptr target){	//target 노드는 추가할 노드 바로 전 노드
	node_ptr node;
	node = (node_ptr)malloc(sizeof(struct node_type));	//새로 추가할 도시 노드 공간 생성
	target->rlink = node;
	node->llink = target;
	return node;
}
void show_info(node_ptr node) {
	int i;
	printf("\nNo.       City  (Owner)  Price  User\n");
	printf("-------------------------------------\n");
	for (i = 0; i < 11; i++) {
		printf("%3d %10s", node->id, node->name);
		if (node->owner == -1)	printf("   (-)");
		else	printf("   (%d)", node->owner);
		printf(" %8d\t", node->price);
		if (Player[0].node_pos == node)	printf("[%d]",Player[0].id);
		if (Player[1].node_pos == node)	printf("[%d]",Player[1].id);
		printf("\n");
		node = node->rlink;
	}
	printf("\nPlayer[0] at [%s]\tbalance (%d)\n",Player[0].node_pos->name,Player[0].balance);	//현재 위치 출력
	printf("Player[1] at [%s]\tbalance (%d)\n", Player[1].node_pos->name, Player[1].balance);
}
void move_player(int id) {
	int dice,i;
	srand((unsigned int)time(0)); //무작위 난수 발생
	dice = rand()%4 + 1;	
	printf("dice = %d\n", dice);
	if (dice != 1) {	//주사위 방향 바꾸지 않을 때
		if (Player[id].direction== 1)	//플레이어 현재 방향이 오른쪽
			for (i = 0; i < dice; i++) {
				Player[id].node_pos = Player[id].node_pos->rlink;
				if (Player[id].node_pos == head) {	//노드 이동 중 중간에 head를 만나거나 head에 도착하면 월급 지급
					printf("\n[ You recieved salary (200). ]\n");
					Player[id].balance += 200;
					if (id == 0)	p1++;
					else	p2++;
				}
			}
		else	//현재 방향 왼쪽
			for (i = 0; i < dice; i++) {
				Player[id].node_pos = Player[id].node_pos->llink;
				if (Player[id].node_pos == head) {
					printf("\n[ You recieved salary (200). ]\n");
					Player[id].balance += 200;
					if (id == 0)	p1++;
					else	p2++;
				}
			}
	}
	else {	//주사위 방향 바뀜
		if (Player[id].direction == 1) {	//현재 방향이 1이면 방향 0으로 바꾸고 왼쪽으로 이동
			Player[id].direction = 0;
			Player[id].node_pos = Player[id].node_pos->llink;
			if (Player[id].node_pos == head) {
				printf("\n[ You recieved salary (200). ]\n");
				Player[id].balance += 200;
				if (id == 0)	p1++;
				else	p2++;
			}
		}
		else {	
			Player[id].direction = 1;	//현재 방향이 0이면 방향 1로 바꾸고 오른쪽으로 이동
			Player[id].node_pos = Player[id].node_pos->rlink;
			if (Player[id].node_pos == head) {
				printf("\n[ You recieved salary (200). ]\n");
				Player[id].balance += 200;
				if (id == 0)	p1++;
				else	p2++;
			}
		}
	}
	printf("\n[Player %d moved to (%s)]\n", id, Player[id].node_pos->name);	//이동 출력
	show_action_menu(Player[id].id);
}
void show_action_menu(int id) {
	int choice;
	if ((Player[id].node_pos->owner == -1)&&(Player[id].node_pos != head)) {	//주인 없는 도시일 때
		if (Player[id].node_pos->price <= Player[id].balance) {	//player의 잔고가 도시 가격 이상일 때
			printf("You can Buy(1) or Pass(2) %s : ", Player[id].node_pos->name);
			scanf_s("%d", &choice);
			if (choice == 1) {	// 도시를 산 경우
				Player[id].node_pos->owner = id;
				Player[id].balance -= Player[id].node_pos->price;
				printf("\nYou bought %s. Your balance is %d\n", Player[id].node_pos->name, Player[id].balance);
			}
			else if (choice == 2)	printf("[You passed.]\n");	//패스
		}
		else	printf("\nYour balance is not enough to buy (%s)", Player[id].node_pos->name);	//잔고부족
	}
	else if (Player[id].node_pos->owner == id) {	//자기가 소유한 도시에 도착
		printf("You can Sell(1) or Pass(2) %s : ", Player[id].node_pos->name);
		scanf_s("%d", &choice);
		if (choice == 1) {
			Player[id].balance += 0.6*Player[id].node_pos->price;	//자기 소유 도시를 팔 경우 도시가격의 60%로 
			Player[id].node_pos->owner = -1;
			printf("\n[You sold the city for %.0lf]\n", (0.6*Player[id].node_pos->price));
		}
		else if (choice == 2)	printf("[You passed.]\n");
	}
	else if (Player[id].node_pos->owner != id && Player[id].node_pos->owner != -1) {	// 상대방 소유 도시에 도착
		printf("[ %s is (%d)'s property. You have to Pay (%.0lf) ]\n", Player[id].node_pos->name, Player[id].node_pos->owner, 0.2*Player[id].node_pos->price);
		Player[id].balance -= (0.2*Player[id].node_pos->price);		//도시가격의 20%
		if(id == 0)	 Player[1].balance += (0.2*Player[id].node_pos->price);		//상대방은 통행료 받음
		else	Player[0].balance += (0.2*Player[id].node_pos->price);
	}
}