#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int sX;
int sY;

int gX;
int gY;

const int mapsize = 6;
int map[mapsize][mapsize] =
	{0,0,0,0,0,0,
	 0,0,0,0,1,0,
	 0,0,0,2,1,0,
	 0,1,1,1,1,0,
	 0,0,0,1,0,0,
	 0,0,0,0,0,3};

int cost[mapsize][mapsize];

enum chip
{
	PATH = 0,
	WALL,
	START,
	GOAL
};

enum Move
{
	UP = 0,
	RIGHT,
	DOWN,
	LEFT,
	MAX
};

//6*6�̃}�X�����܂�
int main() 
{
	for (int x = 0; x < mapsize; x++) {
		for (int y = 0; y < mapsize; y++) {
			//�R�X�g�̃��Z�b�g
			cost[x][y] = -1;

			switch (map[x][y])
			{
			case PATH:
				cout << "�@";
				break;

			case WALL:
				cout << "��";
				break;

			case START:
				cout << "�r";
				//�X�^�[�g�n�_�̃R�X�g�l���O�ɂ��܂�
				cost[x][y] = 0;
				sX = x;
				sY = y;

				break;

			case GOAL:
				cout << "�f";

				gX = x;
				gY = y;

				break;
			}
		}
		cout << endl;
	}

	//�X�^�[�g����S�[���̍ŒZ�͂ǂ̒l�H

	return 0;
}