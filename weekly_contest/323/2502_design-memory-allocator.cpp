class Allocator {
private:
    int n;
    vector<int> mark;

public:
    // 暴力枚举
    Allocator(int n) {
        mark.resize(n, 0);
        this->n = n;
    }

    int allocate(int size, int mID) {
        int st = 0;

        for (int i = 0; i < n && i - st < size; i++)
            if (mark[i] > 0)
                st = i + 1;

        if (st + size > n)
            return -1;

        for (int i = st; i < st + size; i++)
            mark[i] = mID;


        return st;
    }

    int free(int mID) {
        int tot = 0;

        for (int i = 0; i < n; i++)
            if (mark[i] == mID) {
                tot++;

                mark[i] = 0;
            }

        return tot;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */