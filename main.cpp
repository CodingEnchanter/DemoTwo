#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int main(void) {
	int hero_x = 5; // 初始位置
	int hero_y = 20; // 初始位置
	char input; // 输入控制
	bool is_fired = false; // 是否开火
	int enemy_x = 10;
	int enemy_speed_x = 1;
	int enemy_spedd_y = 1;
	int is_enemy = true;

	while (1) {
		system("cls"); // 清除屏幕

		// 画出敌人
		if (is_enemy) {
			for (int j=0; j<enemy_x; j++) {
				printf(" ");
			}
			printf("+\n");
		}

		// 判断开火
		if (!is_fired) {
			// 循环初始位置	
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

		// 画飞机
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
		case 's': // 下
			hero_y++;
			break;
		case 'w': // 上
			hero_y--;
			break;
		case 'a': // 左
			hero_x--;
			break;
		case 'd':
			hero_x++;
			break;
		case ' ':
			is_fired = true;
			if (!is_enemy) { // 击中靶心后, 开火就会再次画出靶心
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