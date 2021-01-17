DJD/*학과:중어중문학과/학번:202010122/이름:나예담
이 프로그램은 C언어를 이용하여 제작한 369게임입니다. */
#define _CRT_NONSTDC_NO_WARNINGS /*비표준 함수와 scanf와 같은 함수에서 에러가 발생하는 것을 방지하기 위해 작성한다.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> //_getch 함수를 사용하기 위해 작성한다.
#include <string.h> //strcpy 함수를 사용하기 위해 작성한다.

int main(void)
{
    int player; //369게임에 필요한 변수들을 지정한다.
    int num = 0;
    int game_369;
    char int_number[10];
    char str_c[10];


    printf("♪~369! 369! 369! 369!~♪ \n");
    do { /*do~while 반복문을 사용하여 먼저 아래 내용을 시행 하도록 한다.(종결조건이 거짓일 경우 for 반복문으로 이동한다)*/
        printf("누가 먼저 시작할까요? (1:컴퓨터, 2:유저)\n");
        player = _getch(); //입력값을 출력하지 않는 _getch 함수를 사용한다.
    } while (player != '1' && player != '2');

    for (num = 1; num <= 100; num++) //1부터 100까지 진행하는 369게임을 진행시키기 위해 for 반복문을 사용하였다.
    {
        game_369 = 0; // 변수를 0으로 초기화한다.

        if (num / 10 > 0) //3, 6, 9를 포함한 숫자를 입력하면 종료하도록 하는 코드를 작성한다.
            if (num / 10 % 3 == 0)
                game_369 = 1;
        if (num % 10 > 0)
            if (num % 10 % 3 == 0)
                game_369 = 1;

        if (game_369 == 1) //if문을 사용하여 3,6,9를 포함한 숫자를 "짝"으로 출력하도록 한다.
            strcpy(str_c, "짝");
        else
            sprintf(str_c, "%d", num); //나머지 숫자는 num을 통해 출력되도록 한다.

        if (player == '1') //1을 입력했을 경우 computer가 먼저 시작하도록 한다.
        {
            printf("Computer> %s\n", str_c);
            player = '2';
        }
        else //1을 선택하지 않았을 경우, User먼저 시작하도록 한다.
        {
            printf("User> ");
            scanf("%s", &int_number);
            if (strcmp(int_number, str_c)) {
                printf("LOSE... \n");
                return 0;
            }
            player = '1';
        }
    }
    printf("★WIN★\n");
}