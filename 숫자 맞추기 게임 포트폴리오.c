/*학과:중어중문학과/학번:202010122/이름:나예담
이 프로그램은 UP과 DOWN을 이용해 유저가 컴퓨터에서 랜덤으로 지정한 숫자를 추리하여 맞추는 게임입니다.
유저가 숫자 입력을 할 때마다 컴퓨터에서 랜덤으로 지정한 숫자보다 높으면 높은 숫자라고 출력하고, 낮으면 낮은 숫자라고 출력하여 범위를 좁혀 숫자를 맞추며,
한번 입력 할 때마다 시도횟수가 증가하여 최종적으로 숫자를 맞췄을 시 시도횟수가 함께 출력되며 게임은 끝납니다.*/

#define _CRT_SECURE_NO_WARNINGS /*scanf와 같은 함수에서 에러가 발생하는 것을 방지하기 위해 작성한다.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomint(int max) { //숫자가 랜덤으로 지정되도록 하는 랜덤함수를 만든다.
	srand(time(NULL)); //srand(time(NULL))를 이용해 숫자가 매번 다르게 나오도록 한다.
	return rand() % max + 1;
}

int readNum(void) { /*readNum함수를 호출한 후, temp라는 변수를 설정한다. 이 temp변수에 값을 입력하면 return을 통해 temp 값이 반환되도록 한다.*/
	int temp;
	scanf("%d", &temp);
	return temp;
}

int main(void) {
	printf("1부터 100사이의 숫자를 맞추는 게임입니다!\n");

	int answer = randomint(100);
	int guess;
	int tries = 0; //시도횟수를 세는 변수

	do { //do~while 문을 이용해 컴퓨터가 제시한 숫자와 유저가 입력한 숫자가 같을 때까지 반복하도록 한다.(readNum에 scanf함수가 들어있어 유저가 숫자를 입력할 수 있다.)
		printf("숫자를 입력하세요. : ");
		guess = readNum();
		tries++;

		if (guess > answer)	printf("입력한 숫자가 높습니다.\n"); //if문을 사용해 컴퓨터가 제시한 숫자보다 입력한 숫자가 높을 경우, 낮을 경우를 출력하도록 한다.
		if (guess < answer)	printf("입력한 숫자가 낮습니다.\n");
	} while (answer != guess); //설정된 숫자와 입력한 숫자가 같을 시 종결하도록 한다.

	printf("★Congratulation!★\n 시도횟수 = %d", tries);  //컴퓨터가 제시한 숫자와 유저가 입력한 숫자가 같아지면 시도횟수와 함께 축하메세지를 출력하도록 한다.

	return 0;
}