class TreeAncestor {
    
public:
    vector<vector<int> > ancestor;
    TreeAncestor(int n, vector<int>& parent) {
        ancestor.push_back(parent);
        
        int ct=2;
        int n1=1;
        while(ct<20){
            
            vector<int> t(n);
            for(int i=0;i<n;i++){
                int tnode=ancestor[n1-1][i];
                tnode=(tnode==-1)?-1:ancestor[n1-1][tnode];
                t[i]=tnode;
            }
            ancestor.push_back(t);
            ct++;
            n1++;
        }

        
    }
    
    int getKthAncestor(int node, int k) {
        int val=(1<<20);
        int ct=20;
        int tnode=node;
        while(k>0){
            
            if(val>k){
                val/=2;
                ct--;
                continue;
            }

            // if(ct<0)break;
            tnode=(tnode==-1)?-1:ancestor[ct][tnode];

            
            k-=val;
            
        }

        return tnode;
    }
};
