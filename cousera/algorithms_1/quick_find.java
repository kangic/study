class quickFind {

    private int [] id;
    private int length;

    public void QuickFindUF (int N){
        id = new int [N];
        for(int i = 0; i< N; i++){
            id[i]=i;
        }
        length = N;
    }
    public boolean connected(int p, int q){
        return id[p] == id[q];
    }

    public void union(int p, int q){
        int pid = id[p];
        int qid = id[q];
        for(int i =0; i<id.length; i++){
            if(id[i] == pid){
                id[i] = qid;
            }
        }
    }

    public void print() {
        for(int i = 0; i < length; ++i) {
            System.out.print(id[i] + " ");
        }
    }
}

class quick_find {
    static public void main(String[] arg) {
        quickFind q = new quickFind();
        q.QuickFindUF(10);
        q.union(4, 9);
        q.union(7, 2);
        q.union(0, 2);
        q.union(5, 6);
        q.union(9, 1);
        q.union(7, 3);

        q.print();
    }
}