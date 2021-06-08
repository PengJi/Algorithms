// 二分算法
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r >> 1;
    if (arr[mid] < target) l = mid + 1;
    else r = mid;
}
if (arr[l] != x) cout << "not found" << endl;
