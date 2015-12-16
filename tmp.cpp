struct ab
{
    int l,r,i;
}a[200001];
#define blocks 450
bool cmp(ab a1,ab a2)
{
    if(a1.l/blocks!=a2.l/blocks)
        return a1.l/blocks<a2.l/blocks;
    return a1.r<a2.r;
}
int parent[200001],sol[200001],parent1[200009] ,ans ; 
// make find(parent) and find1(parent1) function for finding the parent. 
int main()
{
    wl(t)
    {
        v.clear();
        int q;
        S2(n,m);
        S(q);
        fl(i,m)
        {
            S2(j,k);
            v.push_back(make_pair(j,k));
        }
        fl(i,q)
        {
            S2(j,k);
            j--;
            k--;
            a[i].l=j; a[i].r=k; a[i].i=i;
        }
        sort(a,a+q,cmp);
        i=0;
        for(int b=0;b*blocks<=m;b++)
        {
            fil(k,0,n+2)
            {
                parent1[k]=k;
                parent[k]=k;
            }
            ans=0;
            int curr_start=b*blocks;
            int curr_end=(b+1)*blocks-1;
            int pos=curr_end+1;
            while(i<q&&a[i].l<=curr_end)
            {
                v1.clear();
                int tempans=0;
                int l=a[i].l;
                int r=a[i].r;
                for(;pos<=r;pos++)
                {
                    int p=v[pos].first;
                    int q=v[pos].second;
                    p=find(p);
                    q=find(q);
                    if(p!=q)
                    {
                        parent[p]=q;
                        ans++;
                    }
                }
                for(j=min(curr_end,r);j>=l;j--)
                {
                    int p=v[j].first;
                    int q=v[j].second;
                    int p1=find(p);
                    int q1=find(q);
                    if(p1!=q1)
                    {
                        p1=find1(p1);
                        q1=find1(q1);
                        if(p1!=q1)
                        {
                            tempans++;
                            parent1[p1]=q1;
                            v1.push_back(p1);
                        }
                    }
                }
                sol[a[i].i]=n-(tempans+ans);
                for(int op=0;op<v1.size();op++)
                    parent1[v1[op]]=v1[op];
                i++;
            }
        }
        fl(i,q)
        P(sol[i]);
    }
    
    return 0;
}

// fast flow

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(int u, int v, int c) {
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    int st, en, i, u, v;
    SET(dist);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en) {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=next[i]) {
            v = to[i];
            if(flow[i] < cap[i] && dist[v]==-1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=next[e]) {
        v = to[e];
        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
            df = dfs(v, min(cap[e]-flow[e], fl));
            if(df>0) {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

i64 dinitz() {
    i64 ret = 0;
    int df;
    while(bfs()) {
        for(int i=1; i<=nNode; i++) pro[i] = fin[i];
        while(true) {
            df = dfs(src, INF);
            if(df) ret += (i64)df;
            else break;
        }
    }
    return ret;
}

int main() {
    int n, e, u, v, c, i;
    scanf("%d%d", &n, &e);
    init(1, n, n);
    for(i=0; i<e; i++) {
        scanf("%d%d%d", &u, &v, &c);
        if(u!=v) add(u, v, c);
    }
    printf("%lld\n", dinitz());
    return 0;
}


// tarjan algo
int end;int cost[100001],time1[100001];bool visited[100001];
void dfs(int i)
{
    visited[i]=1;
    int j;
    fl(j,v2[i].size())
    {
        int p=v2[i][j];
        if(!visited[p])
            dfs(p);
    }
    time1[i]=++end;
    return ;
}
int lead;
void dfs1(int i)
{
    visited[i]=1;
    leader[i]=lead;
    int j;
    fl(j,v1[i].size())
    {
        int p=v1[i][j];
        if(!visited[p])
            dfs1(p);
    }
    return;
}
int main()
{
    //std::ios_base::sync_with_stdio(false);
    int t;
    int n,i,j,k,m,l;
    S(n);
    fl(i,n)
    S(cost[i]);  
    S(m);
    wl(m)
    {
        S2(j,k);
        v1[j].push_back(k);
        v2[k].push_back(j);
    } 
    fil(i,1,n+1)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    fil(i,1,n+1)
    {
        v3.push_back(make_pair(time1[i],i));
    }
    sort(v3.rbegin(),v3.rend());
    mem(visited,0);
    fl(i,n+1)
    leader[i]=i;
    fil(i,0,n)
    {
        if(!visited[v3[i].second])
        {
            lead=v3[i].second;
            dfs1(v3[i].second);
        }
    }
    fil(i,1,n+1)
        v4[leader[i]].push_back(cost[i-1]);
    ll ways=1,money=0;
    fil(i,1,n+1)
    {
        sort(v4[i].begin(), v4[i].end());
        if(v4[i].size())
        {
            money=money+v4[i][0];
            int ans=0;
            j=0;
            while(j<v4[i].size()&&v4[i][j]==v4[i][0])
            {
                j++;
                ans++;
            }
            ways=(ways*ans)%MOD;
        }
    }
    cout<<money<<" "<<ways<<endl;
    return 0;
}
