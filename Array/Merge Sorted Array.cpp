// 오름차순으로 정렬된 두 개의 배열을 받음
// nums1.length = m + n;
// nums2.length = n;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> left(m), right(n);
        int leftID = 0;
        int rightID = 0;
        int totalID = 0;
        // nums1과 nums2의 0을 제외한 원소들을 각각 커스텀 배열에 저장함
        for (int i = 0; i < m; i++) {
            left.at(i) = nums1.at(i);
        }
        for (int i = 0; i < n; i++) {
            right.at(i) = nums2.at(i);
        }

        // 더 작은 원소를 오름차순으로 nums1에 저장함.
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

        // left OR right 배열에 남은 요소가 있다면 모두 nums1에 저장함.
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