#include <iostream>
const uint64_t maxVal = 1e19;
template <typename type> class segTree {
private:
    struct node {
        type val = 0, lazy = 0;
    }*aint;
    uint32_t sz;
    void build(uint32_t crrNode, type v[], uint32_t l, uint32_t r) {
        if (l == r)
            aint[crrNode].val = v[l];
        else {
            uint32_t mid = (l + r) >> 1;
            build(crrNode << 1, v, l, mid);
            build((crrNode << 1) + 1, v, mid + 1, r);
            aint[crrNode].val = std :: min(aint[crrNode << 1].val, aint[(crrNode << 1) + 1].val);
        }
    }
    void propagate(uint32_t crrNode) {
        aint[crrNode].val += aint[crrNode].lazy;
        aint[crrNode << 1].lazy += aint[crrNode].lazy;
        aint[(crrNode << 1) + 1].lazy += aint[crrNode].lazy;
        aint[crrNode].lazy = 0;
    }
    type query(uint32_t crrNode, uint32_t l, uint32_t r, uint32_t ll, uint32_t rr) {
        if (r < ll or rr < l)
            return maxVal;
        if (l == r or (ll <= l and r <= rr))
            return aint[crrNode].val + aint[crrNode].lazy;
        propagate(crrNode);
        uint32_t mid = (l + r) >> 1;
        return std :: min(query(crrNode << 1, l, mid, ll, rr), query((crrNode << 1) + 1, mid + 1, r, ll, rr));
    }
    void update(uint32_t crrNode, uint32_t l, uint32_t r, uint32_t ll, uint32_t rr, uint32_t val) {
        if (r < ll or rr < l)
            return;
        if (l == r or (ll <= l and r <= rr))
            aint[crrNode].lazy += val;
        else {
            propagate(crrNode);
            uint32_t mid = (l + r) >> 1;
            update(crrNode << 1, l, mid, ll, rr, val);
            update((crrNode << 1) + 1, mid + 1, r, ll, rr, val);
            aint[crrNode].val = std :: min(aint[crrNode << 1].val + aint[crrNode << 1].lazy, aint[(crrNode << 1) + 1].val + aint[(crrNode << 1) + 1].lazy);
        }
    }
public:
    segTree(uint32_t n, type v[]) {
        aint = new node[n << 2];
        sz = n;
        build(1, v, 1, n);
    }
    ~segTree() {
        delete[] aint;
        sz = 0;
    }
    void reInit(uint32_t n, type v[]) {
        delete[] aint;
        aint = new node[n << 2];
        sz = n;
        build(1, v, 1, n);
    }
    void update(uint32_t l, uint32_t r, uint32_t val) {
        update(1, 1, sz, l, r, val);
    }
    type query(uint32_t l, uint32_t r) {
        return query(1, 1, sz, l, r);
    }
};
