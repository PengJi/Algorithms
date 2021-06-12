// 二分算法

// 将区间[l, r]划分成[l, mid]和[mid + 1, r]时，其更新操作是r = mid或者l = mid + 1;，计算mid时不需要加1。
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r >> 1;
    if (arr[mid] < target) l = mid + 1;
    else r = mid;
}
if (arr[l] != x) cout << "not found" << endl;

// 将区间[l, r]划分成[l, mid - 1]和[mid, r]时，其更新操作是r = mid - 1或者l = mid;，此时为了防止死循环，计算mid时需要加1。
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r + 1 >> 1;
    if (arr[mid] < target) l = mid;
    else r = mid - 1;
}
if (arr[l] != x) cout << "not found" << endl;


// 前缀和
const int N = 100010;

int n, m;
int a[N], s[N];

scanf("%d%d", &n, &m);
for(int i = 1; i <= n; i++) scanf("%d", &a[i]);  // 初始化数组

for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];  // 初始化前缀和

while(m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", s[r] - s[l - 1]);  // 计算区间和
}

return 0;
