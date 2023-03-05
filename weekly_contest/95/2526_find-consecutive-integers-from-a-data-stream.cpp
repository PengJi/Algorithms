class DataStream {
private:
    int value, k, tot;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;

        tot = 0;
    }

    bool consec(int num) {
        if (num == value) tot++;
        else tot = 0;

        return tot >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
