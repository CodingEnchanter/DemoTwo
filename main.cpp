#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int main(void) {
	int hero_x = 5; // ��ʼλ��
	int hero_y = 20; // ��ʼλ��
	char input; // �������
	bool is_fired = false; // �Ƿ񿪻�
	int enemy_x = 10;
	int enemy_speed_x = 1;
	int enemy_spedd_y = 1;
	int is_enemy = true;

	while (1) {
		system("cls"); // �����Ļ

		// ��������
		if (is_enemy) {
			for (int j=0; j<enemy_x; j++) {
				printf(" ");
			}
			printf("+\n");
		}

		// �жϿ���
		if (!is_fired) {
			// ѭ����ʼλ��	
			for (int i=0; i<hero_y; i++) {
				printf("\n");
			}
		} else {
			for (int i=0; i<hero_y; i++) {
				for (int j=0; j<hero_x; j++) {
					printf(" ");
				}
				printf("  |\n");
			}
			if (hero_x+2 == enemy_x) {
				is_enemy = false;
			}
			is_fired = false;
		}

		// ���ɻ�
		for (int j=0; j<hero_x; j++) {
			printf(" ");
		}
		printf("  *\n");
		for (int j=0; j<hero_x; j++) {
			printf(" ");
		}
		printf("*****\n");
		for (int j=0; j<hero_x; j++) {
			printf(" ");
		}
		printf(" * *");

		//scanf("%c", &input);
		input = getch();
		switch (input) {
		case 's': // ��
			hero_y++;
			break;
		case 'w': // ��
			hero_y--;
			break;
		case 'a': // ��
			hero_x--;
			break;
		case 'd':
			hero_x++;
			break;
		case ' ':
			is_fired = true;
			if (!is_enemy) { // ���а��ĺ�, ����ͻ��ٴλ�������
				enemy_x = 20;
				is_enemy = true;
			}
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}