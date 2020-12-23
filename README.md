# Assignment   
### 학부 과제 정리

- Data Structure 
	1. Infix to Postfix 
		- 다중 숫자 Infix 수식을 입력 받아 Postfix로 변환한 후 계산
		- 각 변환 과정에서 스택의 상태 출력
	2. Mini Marble
		- Circular Doubly Linked List 로 구현한 미니 마블   
- Introduce To Programming
	1. Tower of Hanoi
		- 원판이 5개인 하노이 탑 게임 
		- 5개의 원판을 왼쪽에서 모두 오른쪽 기둥으로 옮기면 끝   
- Algorithm
	1. Programming Assignment #1 (PA1) -> Merge Sort
		- 수열에서 inversion의 개수 구하기 
		- 수열의 a[0], a[1], ... , a[n-1] 이 주어져있을 때, 0 <= i < j < n, a[i] > a[j] 인 순서쌍 (i, j) 개수 구하기   
	2. Programming Assignment #2 (PA2) -> Quick Sort
		- 좌표평면에 있는 유한 개의 점들 중 최단거리인 쌍 구하기
		- 유한 개의 점 P0, P1, ... , Pn-1 이 있을 때 이들 중 가장 거리가 가까운 두 점 Pi, Pj 를 찾아 두 점의 거리를 반환하기    
	3. Programming Assignment #3 (PA3) -> Counting Sort 
	   	- 단어들 중 일부들만을 이용해서 문장 만들기 
		- 우선순위를 나타내는 음이 아닌 정수와 단어로 구성되어 있는 순서쌍 n개가 주어질 때 (A1, A2, ... , An-1, Ai = (pi, wi)), 규칙에 따라 문장 만들기 
		- 규칙 1 : 각 단어들은 한 칸씩 띄어서 출력
		- 규칙 2 : pi < pj 이면 wi가 wj 보다 먼저 출력 (pi - 우선 순위, wi = 단어)
		- 규칙 3 : pi = pj, i < j 이면 wi가 wj 보다 먼저 출력
		- 규칙 4 : i < floor(n/2) 이면 wi 대신 '-' 하이픈 출력
	4. Programming Assignment #4 (PA4)  -> Dynamic Programming
		- 여러 주머니에서 최대한 돈을 많이 가져가기 위한 방법 구하기
		- 일렬로 놓여 있는 주머니 n 개에 각각 돈이 들어있을 때 일련의 규칙을 따르면서 돈을 최대한 많이 가져가는 방법 구하기 
		- 규칙 1 : 주머니를 선택했으면, 그 주머니 안에 든 돈을 모두 가져간다. 
		- 규칙 2 : 연속으로 놓여 있는 주머니 3개를 모두 가져갈 수는 없다.
		- Top-down 으로 programming 하기   
	5. Programming Assignment #5 (PA5) -> Top-down Programming
		- 격자에서 길찾기 경우의 수 구하기
		- n x n 격자에서 (0, 0) 부터 (n, n) 까지 격자선을 따라 갈 수 있는 모든 경우의 수 구하기 (단, 한번 간 점은 또 다시 방문하지 않는다.)
		
