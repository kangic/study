public class QuickUnionUF {
    private int[] parent;  // parent[i] = parent of i
    private int count;     // number of components

    /**
     * Initializes an empty union-find data structure with N isolated components 0 through N-1.
     *
     * @param N the number of objects
     * @throws java.lang.IllegalArgumentException if N < 0
     */
    public QuickUnionUF(int N) {
        parent = new int[N];
        count = N;
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }

    /**
     * Returns the number of components.
     *
     * @return the number of components (between 1 and N)
     */
    public int count() {
        return count;
    }

    /**
     * Returns the component identifier for the component containing site <tt>p</tt>.
     *
     * @param p the integer representing one site
     * @return the component identifier for the component containing site <tt>p</tt>
     * @throws java.lang.IndexOutOfBoundsException unless 0 <= p < N
     */
    public int find(int p) {
        validate(p);
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    // validate that p is a valid index
    private void validate(int p) {
        int N = parent.length;
        if (p < 0 || p >= N) {
            throw new IndexOutOfBoundsException("index " + p + " is not between 0 and " + N);
        }
    }

    /**
     * Are the two sites <tt>p</tt> and <tt>q</tt> in the same component?
     *
     * @param p the integer representing one site
     * @param q the integer representing the other site
     * @return <tt>true</tt> if the sites <tt>p</tt> and <tt>q</tt> are in the same
     * component, and <tt>false</tt> otherwise
     * @throws java.lang.IndexOutOfBoundsException unless both 0 <= p < N and 0 <= q < N
     */
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }


    /**
     * Merges the component containing site<tt>p</tt> with the component
     * containing site <tt>q</tt>.
     *
     * @param p the integer representing one site
     * @param q the integer representing the other site
     * @throws java.lang.IndexOutOfBoundsException unless both 0 <= p < N and 0 <= q < N
     */
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        count--;
    }

    public void print() {
        for(int i=0; i<10; ++i)
            System.out.print(parent[i] + " ");
    }

    /**
     * Reads in a sequence of pairs of integers (between 0 and N-1) from standard input,
     * where each integer represents some object;
     * if the objects are in different components, merge the two components
     * and print the pair to standard output.
     */
    public static void main(String[] args) {
        QuickUnionUF uf = new QuickUnionUF(10);
        uf.union(7, 8);
        uf.union(9, 3);
        uf.union(4, 2);
        uf.union(3, 0);
        uf.union(5, 1);
        uf.union(5, 3);
        uf.union(2, 8);
        uf.union(9, 2);
        uf.union(0, 6);

        System.out.println(uf.count() + " components");
        uf.print();
    }
}