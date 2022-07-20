// mxn 행렬 mat이 주어졌을 때 행렬의 모든 원소를 대각선 순서로 배열하여 반환한다.
// 대각선은 우상단 방향, 좌하단 방향을 번갈아 가면서 진행한다.
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int lastRowID = mat.size() - 1, lastColID = mat.at(0).size() - 1;
        int rowID = 0, colID = 0;
        int count = 0;
        bool isMovingUpRightDir = true;

        vector<int> result((lastRowID + 1) * (lastColID + 1));

        result.at(count++) = mat.at(0).at(0);

        // 행렬의 우측 최하단(마지막 원소)에 도달하기 전까지 반복
        while (rowID != lastRowID || colID != lastColID) {
            // 우상단 방향 대각선 진행
            if (isMovingUpRightDir) {
                // 현재 열의 위치가 마지막 열이라면 행을 1 증가하고
                // 좌하단 방향으로 대각선 방향 전환
                if (colID == lastColID) {
                    rowID++;
                    isMovingUpRightDir = false;
                }
                // 마지막 열이 아니고 첫번째 행이라면 열을 1 증가하고
                // 좌하단 방향으로 대각선 방향 전환
                else if (rowID == 0) {
                    colID++;
                    isMovingUpRightDir = false;
                }
                // 그 외의 경우 우상단 방향으로 계속 진행
                else {
                    rowID--;
                    colID++;
                }
            }

            // 좌하단 방향 대각선 진행
            else {
                // 현재 행의 위치가 마지막 행이라면 열을 1 증가하고
                // 우상단 방향으로 대각선 방향 전환                
                if (rowID == lastRowID) {
                    colID++;
                    isMovingUpRightDir = true;
                }
                // 마지막 행이 아니고 첫번째 열이라면 행을 1 증가하고
                // 우상단 방향으로 대각선 방향 전환
                else if (colID == 0) {
                    rowID++;
                    isMovingUpRightDir = true;
                }
                // 그 외의 경우 좌하단 방향으로 계속 진행
                else {
                    rowID++;
                    colID--;
                }
            }

            result.at(count++) = mat.at(rowID).at(colID);
        }

        return result;
    }
};