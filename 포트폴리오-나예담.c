DJD/*�а�:�߾��߹��а�/�й�:202010122/�̸�:������
�� ���α׷��� C�� �̿��Ͽ� ������ 369�����Դϴ�. */
#define _CRT_NONSTDC_NO_WARNINGS /*��ǥ�� �Լ��� scanf�� ���� �Լ����� ������ �߻��ϴ� ���� �����ϱ� ���� �ۼ��Ѵ�.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> //_getch �Լ��� ����ϱ� ���� �ۼ��Ѵ�.
#include <string.h> //strcpy �Լ��� ����ϱ� ���� �ۼ��Ѵ�.

int main(void)
{
    int player; //369���ӿ� �ʿ��� �������� �����Ѵ�.
    int num = 0;
    int game_369;
    char int_number[10];
    char str_c[10];


    printf("��~369! 369! 369! 369!~�� \n");
    do { /*do~while �ݺ����� ����Ͽ� ���� �Ʒ� ������ ���� �ϵ��� �Ѵ�.(���������� ������ ��� for �ݺ������� �̵��Ѵ�)*/
        printf("���� ���� �����ұ��? (1:��ǻ��, 2:����)\n");
        player = _getch(); //�Է°��� ������� �ʴ� _getch �Լ��� ����Ѵ�.
    } while (player != '1' && player != '2');

    for (num = 1; num <= 100; num++) //1���� 100���� �����ϴ� 369������ �����Ű�� ���� for �ݺ����� ����Ͽ���.
    {
        game_369 = 0; // ������ 0���� �ʱ�ȭ�Ѵ�.

        if (num / 10 > 0) //3, 6, 9�� ������ ���ڸ� �Է��ϸ� �����ϵ��� �ϴ� �ڵ带 �ۼ��Ѵ�.
            if (num / 10 % 3 == 0)
                game_369 = 1;
        if (num % 10 > 0)
            if (num % 10 % 3 == 0)
                game_369 = 1;

        if (game_369 == 1) //if���� ����Ͽ� 3,6,9�� ������ ���ڸ� "¦"���� ����ϵ��� �Ѵ�.
            strcpy(str_c, "¦");
        else
            sprintf(str_c, "%d", num); //������ ���ڴ� num�� ���� ��µǵ��� �Ѵ�.

        if (player == '1') //1�� �Է����� ��� computer�� ���� �����ϵ��� �Ѵ�.
        {
            printf("Computer> %s\n", str_c);
            player = '2';
        }
        else //1�� �������� �ʾ��� ���, User���� �����ϵ��� �Ѵ�.
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
    printf("��WIN��\n");
}