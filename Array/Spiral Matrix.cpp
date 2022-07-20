#include <iostream>
using namespace std;

// �־��� �Է� ��� matrix�� ù��° ���Һ��� �ð�������� ȸ���Ͽ� 
// ������ �迭�� �����ϰ� ����� ��ȯ�϶�
class Solution {

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int lastTopID = 1, lastBottomID = matrix.size() - 1, lastRightID = matrix[0].size() - 1, lastLeftID = 0;
        int rowID = 0, colID = 0;
        enum dir {
            right = 0,
            down = 1,
            left = 2,
            up = 3
        };
        int currDir = right;
        int count = 0;
        vector<int> result((lastBottomID + 1) * (lastRightID + 1));

        // matrix ��� ���� ������ŭ �ݺ����� ����.
        while (count < (matrix.size() * matrix[0].size())) {
            result[count++] = matrix[rowID][colID];
            switch (currDir) {
            case right:
                if (colID == lastRightID) {
                    rowID++;
                    lastRightID = colID - 1;
                    currDir = down;
                }
                else {
                    colID++;
                }
                break;
            case left:
                if (colID == lastLeftID) {
                    rowID--;
                    lastLeftID = colID + 1;
                    currDir = up;
                }
                else {
                    colID--;
                }
                break;
            case up:
                if (rowID == lastTopID) {
                    colID++;
                    lastTopID = rowID + 1;
                    currDir = right;
                }
                else {
                    rowID--;
                }
                break;
            case down:
                if (rowID == lastBottomID) {
                    colID--;
                    lastBottomID = rowID - 1;
                    currDir = left;
                }
                else {
                    rowID++;
                }
                break;
            }
        }
        return result;

    }
};