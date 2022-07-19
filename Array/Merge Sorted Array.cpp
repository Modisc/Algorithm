// ������������ ���ĵ� �� ���� �迭�� ����
// nums1.length = m + n;
// nums2.length = n;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> left(m), right(n);
        int leftID = 0;
        int rightID = 0;
        int totalID = 0;
        // nums1�� nums2�� 0�� ������ ���ҵ��� ���� Ŀ���� �迭�� ������
        for (int i = 0; i < m; i++) {
            left.at(i) = nums1.at(i);
        }
        for (int i = 0; i < n; i++) {
            right.at(i) = nums2.at(i);
        }

        // �� ���� ���Ҹ� ������������ nums1�� ������.
        while (leftID < m && rightID < n) {
            if (left.at(leftID) <= right.at(rightID))
            {
                nums1.at(totalID) = left.at(leftID);
                leftID++;
            }
            else
            {
                nums1.at(totalID) = right.at(rightID);
                rightID++;
            }
            totalID++;
        }

        // left OR right �迭�� ���� ��Ұ� �ִٸ� ��� nums1�� ������.
        while (leftID < m) {
            nums1.at(totalID) = left.at(leftID);
            leftID++; totalID++;
        }

        while (rightID < n) {
            nums1.at(totalID) = right.at(rightID);
            rightID++; totalID++;
        }

    }
};