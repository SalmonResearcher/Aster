#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
	int x;      //X���W
	int y;      //Y���W
	int f;      
	int cost;      //�S�[���܂ł̃R�X�g
	int h;      //�q���[���X�e�B�b�N�l
    Node* parent;//�e�m�[�h�i�����邩�ȁH�j
    Node(int x, int y, int cost, int h, Node* parent) : x(x), y(y), cost(cost), h(h), parent(parent) {
        f = cost + h;
    }
};

enum WallPath {
	P = 0,
	W
};

int main(){
    vector<vector<WallPath>> map = {
    {P,P,P,P,W,P},
    {P,W,P,W,W,P},
    {P,P,P,P,P,P},
    {P,W,W,W,W,P},
    {P,P,P,W,P,P},
    {P,W,P,P,P,P}
    };

	int startX = 0;
	int startY = 0;
	int goalX = 6;
	int goalY = 6;

    vector<vector<int>> path = AStarAlgorithm(map, startX, startY, goalX, goalY);
}

//�}�b�v�Ƀf�[�^�͂��邩�i�z��O����Ȃ����ǂ����j
bool isValid(int x, int y, int numRows, int numCols) {
    return x >= 0 && x < numRows && y >= 0 && y < numCols;
}

//�q���[���X�e�B�b�N�֐�(|�I�_x - �n�_x| + |�I�_y - �n�_y|)
int calculateHeuristic(int x, int y, int targetX, int targetY) {
    return abs(targetX - x) + abs(targetY - y);
}

//Astar�A���S���Y��
vector<vector<int>> AStarAlgorithm(vector<vector<WallPath>>& map, int startX, int startY, int targetX, int targetY) {
    //�}�b�v�̊O�ɃX�^�[�g�A�S�[����ݒ肵�Ȃ��悤�Ɍ����p�̕ϐ�
    int numRows = map.size();
    int numCols = map[0].size();

    //�}�b�v�̃X�^�[�g�n�_�ƃS�[���n�_�͂ӂ��킵����
    if (!isValid(startX, startY, numRows, numCols) || !isValid(targetX, targetY, numRows, numCols)) {
        cout << "�S�[���̍��W���X�^�[�g�n�_�̍��W���z��O���w�肵�Ă��܂�" << endl;
        return {};
    }

    //�X�^�[�g�n�_��S�[���n�_���ǂ�������
    if (map[startX][startY] == W || map[targetX][targetY] == W) {
        cout << "�X�^�[�g�n�_���S�[���n�_���ӂ�����Ă��܂�" << endl;
        return {};
    }

    //�ʂ����Ƃ�����L�^����ϐ�
    vector<Node*> openNodes;

    //�ꏊ�̃R�X�g�l������
    vector<vector<int>> costs;
    
    //�X�^�[�g�n�_�A�X�^�[�g����S�[���܂ł̃}�X��������
    Node* startNode = new Node(startX, startY, 0, calculateHeuristic(startX, startY, targetX, targetY), nullptr);

    //���ݒn���v�b�V�����܂��A���ݒn�̃R�X�g��0�ɂ��܂�
    //���ݒn�A�v�b�V���ł��܂���I
    openNodes.push(startNode);
    costs[startX][startY] = 0;

    //�ړ��p
    vector<int> moveX { -1,0,1,0 };
    vector<int> moveY { 0,1,0,-1 };

    while (!openNodes.empty())
    {
        //�Ȃ񂱂�Ȃ�Ń_���H
        Node* currentNode = openNodes.begin();
    }

}