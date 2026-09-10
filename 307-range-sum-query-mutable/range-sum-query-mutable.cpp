class NumArray {
public:
vector<int> tree;
int n;

    void build(vector<int> &arr,int start,int end,int node){
        // leaf node
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid=(start+end)/2;
        build(arr,start,mid,2*node+1);
        build(arr,mid+1,end,2*node+2);
        tree[node]=tree[2*node+1] +tree[2*node+2];
    }
    void update(int start ,int end,int node,int idx,int val){
        if(start==end){
            tree[node]=val;
            return ;
        }
        int mid=(start+end)/2;
        if(idx<=mid){// go left subtree
            update(start,mid,2*node+1,idx, val);
        }else{
            update(mid+1,end,2*node+2,idx,val);
        }
        // recalculate parent
        tree[node]=tree[2*node+1] + tree[2*node+2];
    }
    int query(int start,int end,int node,int ql,int qr){
        // if(start==end){
        //     tree[node]=
        // }// sum main ye chiz nahi hai
        // yaha per nooverlap,complete overlap,partial overlap hai

        // no overlap
        if(start>qr || end<ql){
            return 0;
        } 
        // complete overlap
        if(ql<=start && end<=qr){
            return tree[node];
        }
        // partial overlap
        int mid=(start+end)/2;
        int left=query(start,mid,2*node+1,ql,qr);
        int right=query(mid+1,end,2*node+2,ql,qr);
        return left+right;
    }
    NumArray(vector<int>& arr) {// constructor
        n=arr.size();
        tree.resize(4*n);
        // call the build function
        build(arr,0,n-1,0);
    }
    
    void update(int index, int val) {
        update(0,n-1,0,index,val);// third index is node that is node 0
    }
    
    int sumRange(int left, int right) {
       return query(0,n-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */