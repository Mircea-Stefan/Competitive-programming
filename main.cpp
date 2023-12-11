#include <vector>
struct minHeap {
    std :: vector <int64_t> h{0}, entry{0};
    std :: vector <uint32_t> pos{0};
    void swapNodes(uint32_t u, uint32_t v) {
        std :: swap(h[u], h[v]);
        std :: swap(pos[entry[u]], pos[entry[v]]);
        std :: swap(entry[u], entry[v]);
    }
    void upHeap(uint32_t v) {
        while (1 < v and h[v] < h[v >> 1]) {
            swapNodes(v, v >> 1);
            v >>= 1;
        }
    }
    void Insert(int64_t x) {
        entry.emplace_back(pos.size());
        pos.emplace_back(h.size());
        h.emplace_back(x);
        upHeap(h.size() - 1);
    }
    void eraseMin() {
        swapNodes(1, h.size() - 1);
        h.pop_back();
        entry.pop_back();
        uint32_t v = 1, son;
        while ((v << 1) < h.size()) {
            son = v << 1;
            if ((son | 1) < h.size() and h[son | 1] < h[son])
                son |= 1;
            if (h[v] <= h[son])
                return;
            swapNodes(v, son);
            v = son;
        }
    }
    void Erase(uint32_t k) {
        h[pos[k]] = -1;
        upHeap(pos[k]);
        eraseMin();
    }
    int64_t getMin() {
        return h[1];
    }
};
