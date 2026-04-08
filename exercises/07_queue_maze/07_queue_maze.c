#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROW 5
#define MAX_COL 5

// 迷宫：0=可走，1=墙
int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

// 队列节点（存坐标）
typedef struct {
	int x, y;
} Node;

// 队列（BFS 核心）
Node queue[MAX_ROW * MAX_COL];
int front = 0;
int rear = 0;

// 记录每个点是从哪个点走来的（用于最后回溯路径）
Node pre[MAX_ROW][MAX_COL];

// 四个方向：下、右、上、左
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 入队
void enqueue(int x, int y) {
	queue[rear].x = x;
	queue[rear].y = y;
	rear++;
}

// 出队
Node dequeue() {
	return queue[front++];
}

// 判断队列空
int isEmpty() {
	return front == rear;
}

// 打印最终路径（从终点倒着回溯，再正序输出）
void printPath(int endX, int endY) {
	Node path[MAX_ROW * MAX_COL];
	int len = 0;

	// 从终点往起点回溯
	int x = endX;
	int y = endY;
	while (x != -1 && y != -1) {
		path[len].x = x;
		path[len].y = y;
		len++;

		int px = pre[x][y].x;
		int py = pre[x][y].y;
		x = px;
		y = py;
	}

	// 倒序输出 = 起点到终点
	printf("BFS 最短路径：\n");
	for (int i = len - 1; i >= 0; i--) {
		printf("(%d,%d)", path[i].x, path[i].y);
		if (i > 0) printf("→");
	}
	printf("\n");
}

// BFS 主函数
void bfs(int startX, int startY, int endX, int endY) {
	// 初始化前驱节点为 -1（表示没有前驱）
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			pre[i][j].x = -1;
			pre[i][j].y = -1;
		}
	}

	// 起点入队
	enqueue(startX, startY);
	maze[startX][startY] = 1; // 标记走过

	while (!isEmpty()) {
		Node cur = dequeue();
		int x = cur.x;
		int y = cur.y;

		// 到达终点
		if (x == endX && y == endY) {
			printPath(endX, endY);
			return;
		}

		// 四个方向扩展
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 不越界 + 可走
			if (nx >= 0 && nx < MAX_ROW && ny >= 0 && ny < MAX_COL && maze[nx][ny] == 0) {
				maze[nx][ny] = 1;     // 标记已走
				pre[nx][ny] = cur;    // 记录前驱
				enqueue(nx, ny);      // 入队
			}
		}
	}
	printf("无路径\n");
}

int main(void) {
	bfs(0, 0, 4, 4); // 起点(0,0) 终点(4,4)
	return 0;
}