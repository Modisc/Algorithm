// mxn ��� mat�� �־����� �� ����� ��� ���Ҹ� �밢�� ������ �迭�Ͽ� ��ȯ�Ѵ�.
// �밢���� ���� ����, ���ϴ� ������ ������ ���鼭 �����Ѵ�.
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int lastRowID = mat.size() - 1, lastColID = mat.at(0).size() - 1;
        int rowID = 0, colID = 0;
        int count = 0;
        bool isMovingUpRightDir = true;

        vector<int> result((lastRowID + 1) * (lastColID + 1));

        result.at(count++) = mat.at(0).at(0);

        // ����� ���� ���ϴ�(������ ����)�� �����ϱ� ������ �ݺ�
        while (rowID != lastRowID || colID != lastColID) {
            // ���� ���� �밢�� ����
            if (isMovingUpRightDir) {
                // ���� ���� ��ġ�� ������ ���̶�� ���� 1 �����ϰ�
                // ���ϴ� �������� �밢�� ���� ��ȯ
                if (colID == lastColID) {
                    rowID++;
                    isMovingUpRightDir = false;
                }
                // ������ ���� �ƴϰ� ù��° ���̶�� ���� 1 �����ϰ�
                // ���ϴ� �������� �밢�� ���� ��ȯ
                else if (rowID == 0) {
                    colID++;
                    isMovingUpRightDir = false;
                }
                // �� ���� ��� ���� �������� ��� ����
                else {
                    rowID--;
                    colID++;
                }
            }

            // ���ϴ� ���� �밢�� ����
            else {
                // ���� ���� ��ġ�� ������ ���̶�� ���� 1 �����ϰ�
                // ���� �������� �밢�� ���� ��ȯ                
                if (rowID == lastRowID) {
                    colID++;
                    isMovingUpRightDir = true;
                }
                // ������ ���� �ƴϰ� ù��° ���̶�� ���� 1 �����ϰ�
                // ���� �������� �밢�� ���� ��ȯ
                else if (colID == 0) {
                    rowID++;
                    isMovingUpRightDir = true;
                }
                // �� ���� ��� ���ϴ� �������� ��� ����
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