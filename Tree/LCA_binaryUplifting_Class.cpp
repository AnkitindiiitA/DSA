class LCA {  
public:
    
    vector<int> level;
    vector<vector<int> > adjList;
    vector<vector<int> > populate;
    int size;

    void levelCalculation(int node, int parent=-1, int lvl=0){
        level[node]=lvl;
        for(auto &it:adjList[node]){
            if(it==parent)continue;
            populate[0][it]=node;
            levelCalculation(it,node,lvl+1);
        }
    }

    void preComputation(){

        for(int i=1;i<=20;i++){
            for(int j=0;j<=size;j++){
                int node=populate[i-1][j];
                if(node!=-1)node=populate[i-1][node];
                populate[i][j]=node;
            }
        }
    }

    int kthAnc(int node, int k){
        if(k==0)return node;

        int val=(1<<20);
        int ct=20;
        while(k>0){
            if(val>k){
                val>>=1;
                ct--;
                continue;
            }

            node=(node==-1)?-1:populate[ct][node];
            k-=val;
        }

        return node;
    }

    int getLCA(int a, int b){
        if(level[a]>level[b]){
            a=kthAnc(a,level[a]-level[b]);
        }else{
            b=kthAnc(b,level[b]-level[a]);
        }

        if(a==b)return a;

        //logn lca find

        int ct=20;
        while(ct>=0){
            if(populate[ct][a]!=populate[ct][b]){
                a=populate[ct][a];
                b=populate[ct][b];
            }
            ct--;
        }

        return populate[0][a];
    }

    LCA(int n, vector<vector<int> > &newAdj) {
        level.resize(n+1);
        size=n;
        populate.resize(21,vector<int>(n+1,-1));
        int root=0;//change root for 1 indexed root;
        adjList=newAdj;
        levelCalculation(root);//
        preComputation();//

    }
    
    
};
