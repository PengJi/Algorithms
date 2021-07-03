/**
 * 5783. 设计电影租借系统
 * https://leetcode-cn.com/problems/design-movie-rental-system/
 */

// https://www.acwing.com/activity/content/code/content/1386744/

const int N = 10010;
struct Node {
    int shop, movie, price;
    bool operator< (const Node& t) const {
        if (price != t.price) return price < t.price;
        if (shop != t.shop) return shop < t.shop;
        return movie < t.movie;
    }
};
set<Node> mv[N];
set<Node> nodes;
map<pair<int, int>, int> pr;

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i = 0; i < N; i ++ ) mv[i].clear();
        nodes.clear();
        pr.clear();

        for (auto& e: entries) {
            int shop = e[0], movie = e[1], price = e[2];
            mv[movie].insert({shop, movie, price});
            pr[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        for (auto& e: mv[movie]) {
            res.push_back(e.shop);
            if (res.size() >= 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        auto it = mv[movie].find({shop, movie, pr[{shop, movie}]});
        nodes.insert(*it);
        mv[movie].erase(it);
    }

    void drop(int shop, int movie) {
        auto it = nodes.find({shop, movie, pr[{shop, movie}]});
        mv[movie].insert(*it);
        nodes.erase(it);
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto& e: nodes) {
            res.push_back({e.shop, e.movie});
            if (res.size() >= 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
