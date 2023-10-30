#include <bits/stdc++.h>

using namespace std;

struct SegementTree {
    vector<int> st; 
    int n;

    void init(int n) {
        this->n = n; 
        st.resize(4 * this->n, 0);
    }

    void build(int start, int end, int node, vector<int> &v) {
        if(start == end) {
            this->st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        // left sub tree building.
        build(start, mid, 2 * node + 1, v);
        // left sub tree building.
        build(mid + 1, end, 2 * node + 2, v);
        this->st[node] = this->st[2 * node + 1] + this->st[2 * node + 2];
    }

    void build(vector<int> &v) {
        build(0, v.size() - 1, 0, v);
    }

    int query(int start, int end, int l, int r, int node) {
        if(start > r or end < l) {
            return 0;
        }
        if(start >= l and end <= r) {
            return this->st[node];
        }
        int mid = (start + end) / 2; 
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return q1 + q2;
    }

    int query(int l, int r) {
        return query(0, this->n - 1, l, r, 0);
    }

    void update(int start,int end, int node, int index, int value) {
        if(start == end) {
            this->st[node] = value;
            return;
        }
        
        int mid = (start + end) / 2; 
        if(index <= mid) {
            update(start, mid, 2 * node + 1, index, value);
        } else {
            update(mid + 1, end, 2 * node + 2, index, value);
        }
        this->st[node] = this->st[2 * node + 1] + this->st[2 * node + 2];
    }


    void update(int x, int y) {
        update(0, this->n - 1, 0, x, y);
    }

};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8}; 
    SegementTree st; 
    st.init(v.size());
    st.build(v); 
    st.update(4, 10);
    cout << st.query(0, 4) << endl;

    return 0;
}
