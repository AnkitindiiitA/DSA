// problem link: https://leetcode.com/problems/sum-of-distances-in-tree/

//explaination: https://www.youtube.com/watch?v=Ox_sc84fHV0

//code
class Solution {
private:
vector<int> nodeCount, res;
    void populate(int node, vector<vector<int> > &v, int p=-1){

        nodeCount[node]=1;
        for(auto it:v[node]){
            if(it==p)continue;
            populate(it,v,node);
            nodeCount[node]+=nodeCount[it];
            res[node]+=res[it]+nodeCount[it];
        }

    }

    void dfs(int node, vector<vector<int> > &v,int parent,int &n){
        if(parent!=-1){
            res[node]=res[parent]-(nodeCount[node])+(n-nodeCount[node]);
        }

        for(auto it:v[node]){
            if(it==parent)continue;
            dfs(it,v,node,n);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int> > v(n);

        for(auto it:edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }

        nodeCount.resize(n,0);
        res.resize(n,0);

        populate(0,v);
        
        dfs(0,v,-1,n);
        return res;
    }
};


