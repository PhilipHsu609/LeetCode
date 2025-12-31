/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return helper(grid, 0, 0, n);
    }

    Node *helper(const vector<vector<int>> &grid, int i, int j, int n) {
        int val = grid[i][j];
        bool same = true;
        if(n == 1) {
            return new Node(grid[i][j] == 1, true);
        }

        for(int y = i; y < i + n; ++y) {
            for(int x = j; x < j + n; ++x) {
                if(grid[y][x] != val) {
                    same = false;
                    break;
                }
            }
        }

        if(same) {
            return new Node(grid[i][j] == 1, true);
        }

        Node *node = new Node(true, false);
        int m = n / 2;
        node->topLeft = helper(grid, i, j, m);
        node->topRight = helper(grid, i, j + m, m);
        node->bottomLeft = helper(grid, i + m, j, m);
        node->bottomRight = helper(grid, i + m, j + m, m);
        return node;
    }
};