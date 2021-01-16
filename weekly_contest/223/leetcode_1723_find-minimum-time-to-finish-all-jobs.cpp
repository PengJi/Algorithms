/**
 * 1723. 完成所有工作的最短时间
 * https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/
 */

class Solution {
public:
    int N;
    // https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/solution/c-er-fen-fwt-ji-bai-100-by-zzucy1999-6xyl/
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int l=0,r=0;
        int n=jobs.size();
        N=(1<<n);
        int zhi[1<<jobs.size()];
        for(int i=0;i<jobs.size();i++){
            zhi[1<<i]=jobs[i];
        }
        long long val[1<<n];
        memset(val,0,sizeof(val));
        for(int i=1;i<(1<<n);i++){
            val[i]=(((val[i-(i&(-i))]>>30)+zhi[i&(-i)])<<30)+i;
        }
        sort(val+1,val+(1<<n));
        l=1,r=(1<<n)-1;
        vector<pair<int,int> > v;
        while(l<r){
            int mid=(l+r)>>1;
            short a[N];memset(a,0,sizeof(a));
            a[0]=1;
            for(int i=1;i<=mid;i++){
                a[val[i]&((1<<30)-1)]=1;
            }
            FWT_or(a,1);
            for(int i=0;i<N;i++){
                a[i]=powmod(a[i],k);
            }
            FWT_or(a,-1);
            if(a[N-1]) r=mid;
            else l=mid+1;
        }
        return (int)(val[l]>>30);
    }

    void FWT_or(short *a,int opt)
    {
        for(int i=1;i<N;i<<=1)
            for(int p=i<<1,j=0;j<N;j+=p)
                for(int k=0;k<i;++k)
                    if(opt==1)a[i+j+k]=(a[j+k]+a[i+j+k]);
                    else a[i+j+k]=(a[i+j+k]-a[j+k]);
    }
    
    int powmod(int a,int b){
        int ans=1;
        while(b){
            if(b&1) ans=1ll*ans*a;
            a=1ll*a*a;
            b>>=1;
        }
        return ans;
    }
};
