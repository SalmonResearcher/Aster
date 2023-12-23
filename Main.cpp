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
	int x;      //X座標
	int y;      //Y座標
	int f;      
	int cost;      //ゴールまでのコスト
	int h;      //ヒューリスティック値
    Node* parent;//親ノード（つかえるかな？）
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

//マップにデータはあるか（配列外じゃないかどうか）
bool isValid(int x, int y, int numRows, int numCols) {
    return x >= 0 && x < numRows && y >= 0 && y < numCols;
}

//ヒューリスティック関数(|終点x - 始点x| + |終点y - 始点y|)
int calculateHeuristic(int x, int y, int targetX, int targetY) {
    return abs(targetX - x) + abs(targetY - y);
}

//Astarアルゴリズム
vector<vector<int>> AStarAlgorithm(vector<vector<WallPath>>& map, int startX, int startY, int targetX, int targetY) {
    //マップの外にスタート、ゴールを設定しないように検索用の変数
    int numRows = map.size();
    int numCols = map[0].size();

    //マップのスタート地点とゴール地点はふさわしいか
    if (!isValid(startX, startY, numRows, numCols) || !isValid(targetX, targetY, numRows, numCols)) {
        cout << "ゴールの座標かスタート地点の座標が配列外を指定しています" << endl;
        return {};
    }

    //スタート地点やゴール地点が壁だった時
    if (map[startX][startY] == W || map[targetX][targetY] == W) {
        cout << "スタート地点かゴール地点がふさがれています" << endl;
        return {};
    }

    //通ったところを記録する変数
    vector<Node*> openNodes;

    //場所のコスト値を持つ
    vector<vector<int>> costs;
    
    //スタート地点、スタートからゴールまでのマス数を持つ
    Node* startNode = new Node(startX, startY, 0, calculateHeuristic(startX, startY, targetX, targetY), nullptr);

    //現在地をプッシュします、現在地のコストを0にします
    //現在地、プッシュできません！
    openNodes.push(startNode);
    costs[startX][startY] = 0;

    //移動用
    vector<int> moveX { -1,0,1,0 };
    vector<int> moveY { 0,1,0,-1 };

    while (!openNodes.empty())
    {
        //なんこれなんでダメ？
        Node* currentNode = openNodes.begin();
    }

}