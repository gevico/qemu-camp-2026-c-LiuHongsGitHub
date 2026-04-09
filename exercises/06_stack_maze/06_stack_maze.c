#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

typedef struct {
    int x;
    int y;
} Node;

Node stack[MAX_ROW * MAX_COL];
int top = -1;
int visited[MAX_ROW][MAX_COL] = {0};

void push(int x, int y) {
    if (top >= MAX_ROW * MAX_COL - 1) {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top].x = x;
    stack[top].y = y;
}

void pop() {
    if (top < 0) {
        printf("Stack underflow!\n");
        return;
    }
    top--;
}

int isEmpty() {
    return top == -1;
}

Node topNode() {
    if (top < 0) {
        printf("Stack is empty!\n");
        Node dummy = {0, 0};
        return dummy;
    }
    return stack[top];
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void maze_dfs_stack(int startX, int startY, int endX, int endY) {
    push(startX, startY);
    visited[startX][startY] = 1;

    while (!isEmpty()) {
        Node cur = topNode();
        int x = cur.x;
        int y = cur.y;

        // Reach the end
        if (x == endX && y == endY) {
            
            for (int i = top; i >= 0; i--) {
                printf("(%d, %d)\n", stack[i].x, stack[i].y);
            }
            return;
        }

        // Four directions to find the next one
        int found = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Legal: not out of bounds + walkable + not visited
            if (nx >= 0 && nx < MAX_ROW && ny >= 0 && ny < MAX_COL &&
                maze[nx][ny] == 0 && !visited[nx][ny]) {
                push(nx, ny);
                visited[nx][ny] = 1;
                found = 1;
                break;
            }
        }

        // No path found, backtrack by popping from the stack
        if (!found) {
            pop();
        }
    }

    // Handle the case where no path is found
    printf("未找到路径。\n");
}

int main(void) {
    memset(visited, 0, sizeof(visited));
    maze_dfs_stack(0, 0, MAX_ROW - 1, MAX_COL - 1);
    return 0;
}
