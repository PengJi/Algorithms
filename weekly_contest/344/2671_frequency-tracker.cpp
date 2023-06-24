/**
 * 2671. 频率跟踪器
 * https://leetcode.cn/problems/frequency-tracker/
*/
const int N = 200010;

class FrequencyTracker {
private:
    int f[N], c[N];

public:
    FrequencyTracker() {
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
    }

    void add(int number) {
        --f[c[number]];
        ++f[++c[number]];
    }

    void deleteOne(int number) {
        if (c[number] == 0)
            return;

        --f[c[number]];
        ++f[--c[number]];
    }

    bool hasFrequency(int frequency) {
        return f[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
