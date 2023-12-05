#include <iostream>
#include <cstdlib>

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

struct Cost
{
	int x_;
	int y_;
	int cellCount;
	int heuristic;
	int cost;
};

enum chip
{
	DEFAULT = -1,
	PATH,
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

//6*6のマスを作ります
int main() 
{
	for (int x = 0; x < mapsize; x++) {
		for (int y = 0; y < mapsize; y++) {
			//コストのリセット
			cost[x][y] = DEFAULT;

			switch (map[x][y])
			{
			case PATH:
				cout << "　";
				break;

			case WALL:
				cout << "■";
				break;

			case START:
				cout << "Ｓ";
				//スタート地点のコスト値を０にします
				cost[x][y] = 0;
				sX = x;
				sY = y;

				break;

			case GOAL:
				cout << "Ｇ";

				gX = x;
				gY = y;

				break;
			}
		}
		cout << endl;
	}

	//スタートからゴールの最短はどの値？
	//上下左右進める？
	
	int costCount = 1;
	int X = sX;
	int Y = sY;

	//上は配列外かどうか
	if (Y - costCount >= 0)
	{
		//上に進める？(コスト値はデフォ値-1であり（前に通ったことがない）、壁（1）でない)
		if (cost[X][Y - costCount] == DEFAULT && cost[X][Y - costCount] != WALL)
		{
			cost[X][Y - costCount] = costCount + std::abs(sX - gX) + std::abs((sY - costCount) - gY);
		}
		else if (cost[X][Y - costCount] == WALL)
		{
			cost[X][Y - costCount] = -2;
		}
	}
	

	//下は配列外かどうか
	if (Y + costCount < mapsize)
	{
		if(cost[X][Y + costCount] == -1 && map[X][Y + costCount] || PATH && map[X][Y + costCount] || GOAL)
			cost[X][Y + costCount] = costCount + std::abs(sX - gX) + std::abs(sY - gY);
	}

	//右は配列外かどうか
	if (X - costCount > mapsize)
	{
		if (cost[X - costCount][Y] == -1 && map[X - costCount][Y] || PATH && map[X - costCount][Y] || GOAL)
			cost[X - costCount][Y] = costCount + std::abs(sX - gX) + std::abs(sY - gY);
	}

	//左は配列外かどうか
	if (X + costCount >= 0)
	{
		if (cost[X + costCount][Y] == -1 && map[X + costCount][Y] || PATH && map[X + costCount][Y] || GOAL)
			cost[X + costCount][Y] = costCount + std::abs(sX - gX) + std::abs(sY - gY);
	}

	return 0;
}