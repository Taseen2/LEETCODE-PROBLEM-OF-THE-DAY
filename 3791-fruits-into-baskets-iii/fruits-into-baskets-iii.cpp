class SegmentTree {
    int n;
    vector<long long> st;
public:
    SegmentTree(const vector<int>& A) {
        n = A.size();
        st.resize(4*n);
        build(1, 0, n-1, A);
    }
    
    void build(int p, int l, int r, const vector<int>& A) {
        if (l == r) {
            st[p] = A[l];
        } else {
            int m = (l+r)/2;
            build(p<<1,   l,   m, A);
            build(p<<1|1, m+1, r, A);
            st[p] = max(st[p<<1], st[p<<1|1]);
        }
    }
    
    // Find leftmost index in [L..R] with value >= x, or return -1
    int query_first(int p, int l, int r, long long x) {
        if (st[p] < x) return -1;            // no candidate in this segment
        if (l == r) return l;                // leaf, and st[p] >= x
        int m = (l+r)/2;
        // check left child first
        int res = query_first(p<<1, l, m, x);
        if (res != -1) 
            return res;
        return query_first(p<<1|1, m+1, r, x);
    }
    
    // Point update: set A[idx] = value
    void update(int p, int l, int r, int idx, long long value) {
        if (l == r) {
            st[p] = value;
        } else {
            int m = (l+r)/2;
            if (idx <= m) update(p<<1,   l,   m, idx, value);
            else         update(p<<1|1, m+1, r, idx, value);
            st[p] = max(st[p<<1], st[p<<1|1]);
        }
    }
    
    // Wrappers
    int find_first(long long x) {
        return query_first(1, 0, n-1, x);
    }
    void remove(int idx) {
        update(1, 0, n-1, idx, -1); // mark as used (all baskets[i]>=1)
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree seg(baskets);
        int unplaced = 0;
        
        for (auto f : fruits) {
            int j = seg.find_first(f);
            if (j == -1) {
                ++unplaced;
            } else {
                seg.remove(j);
            }
        }
        return unplaced;
    }
};
