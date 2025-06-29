// https://leetcode.com/problems/construct-quad-tree
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
    Node* helper(vector<vector<int>>& grid, int s_row, int e_row, int s_col, int e_col){
        if(s_row > e_row || s_col > e_col)
            return nullptr;
        if(grid[s_row][s_col] != grid[s_row][e_col] || grid[s_row][e_col] != grid[e_row][e_col] || grid[e_row][e_col] != grid[e_row][s_col]){
            int mid_row = (e_row - s_row)/2 + s_row;
            int mid_col = (e_col - s_col)/2 + s_col;

            Node* node = new Node();
            node->topLeft = helper(grid, s_row, mid_row, s_col, mid_col);
            node->topRight = helper(grid, s_row, mid_row, mid_col+1, e_col);
            node->bottomLeft = helper(grid, mid_row+1, e_row, s_col, mid_col);
            node->bottomRight = helper(grid, mid_row+1, e_row, mid_col+1, e_col);

            return node;
        }else{
            for(int r=s_row; r<=e_row; r++){
                for(int c=s_col; c<=e_col; c++){
                    if(grid[r][c] != grid[s_row][s_col]){
                        int mid_row = (e_row - s_row)/2 + s_row;
                        int mid_col = (e_col - s_col)/2 + s_col;

                        Node* node = new Node();
                        node->topLeft = helper(grid, s_row, mid_row, s_col, mid_col);
                        node->topRight = helper(grid, s_row, mid_row, mid_col+1, e_col);
                        node->bottomLeft = helper(grid, mid_row+1, e_row, s_col, mid_col);
                        node->bottomRight = helper(grid, mid_row+1, e_row, mid_col+1, e_col);

                        return node;
                    }
                }
            }

            Node* node = new Node();
            if(grid[s_row][s_col])
                node->val = true;
            else
                node->val = false;
                
            node->isLeaf = true;
            return node;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        return helper(grid, 0, row-1, 0, col-1);
    }
};
