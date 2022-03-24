struct node{
    char lc,rc;
    int llen,rlen;
    int mx;
};
class Solution {
    node tree[100005 * 4];
    string S;
    int n;
public:
    void mg(int v,int l,int r,int mid) {
        tree[v].lc = tree[v+v].lc;
        tree[v].rc = tree[v+v+1].rc;
        tree[v].mx = max(tree[v+v].mx,tree[v+v+1].mx);
        if (tree[v+v].rc==tree[v+v+1].lc) tree[v].mx = max(tree[v].mx, tree[v+v].rlen+tree[v+v+1].llen);
        
        if (tree[v+v].llen==mid-l+1 && tree[v+v].rc == tree[v+v+1].lc) {
            tree[v].llen = tree[v+v].llen + tree[v+v+1].llen;
        }
        else tree[v].llen = tree[v+v].llen;
        
        if (tree[v+v+1].rlen==r-mid && tree[v+v+1].lc == tree[v+v].rc) {
            tree[v].rlen = tree[v+v+1].rlen + tree[v+v].rlen;
        }
        else tree[v].rlen = tree[v+v+1].rlen;
    }
    void build(int v,int l,int r) {
        // cout<<l<<" "<<r<<endl;
        if (l==r) {
            tree[v].lc = tree[v].rc = S[l-1];
            tree[v].llen = tree[v].rlen=1;
            tree[v].mx = 1;
            return;
        }
        int mid=(l+r) / 2;
        build(v+v,l,mid);
        build(v+v+1,mid+1,r);
        mg(v,l,r,mid);
    }
    void upd(int v,int l,int r,char c,int x) {
        if (l==r) {
            tree[v].lc = tree[v].rc = c;
            tree[v].llen = tree[v].rlen=1;
            tree[v].mx = 1;
            return;
        }
        int mid=(l+r) / 2;
        if (x<=mid) upd(v+v,l,mid,c,x);
        else upd(v+v+1,mid+1,r,c,x);
        mg(v,l,r,mid);
    }
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        S = s;
        n = S.size();
        build(1,1,n);
        vector<int> ret;
        ret.clear();
        for(int i=0;i<qi.size();i++) {
            upd(1,1,n,qc[i],qi[i]+1);
            ret.push_back(tree[1].mx);
        }
        return ret;
    }
};
