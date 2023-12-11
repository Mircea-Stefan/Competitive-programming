#include <fstream>
#include <vector>
static const uint64_t base = 10;
class BigInt {
public:
    std :: vector <uint64_t> digit;
    BigInt(uint64_t n = 0) {
        do {
            digit.emplace_back(n % base);
            n /= base;
        } while (n != 0);
    }
    BigInt(const BigInt &a) {
        for (uint32_t i = 0; i != a.digit.size(); ++ i)
            digit.emplace_back(a.digit[i]);
    }
    friend bool operator < (BigInt a, BigInt b) {
        if (a.digit.size() < b.digit.size())
            return true;
        if (a.digit.size() > b.digit.size())
            return false;
        int32_t i;
        for (i = a.digit.size() - 1; i != -1; -- i)
            if (a.digit[i] != b.digit[i])
                return a.digit[i] < b.digit[i];
        return false;
    }
    friend bool operator > (BigInt a, BigInt b) {
        if (a.digit.size() > b.digit.size())
            return true;
        if (a.digit.size() < b.digit.size())
            return false;
        int32_t i;
        for (i = a.digit.size() - 1; i != -1; -- i)
            if (a.digit[i] != b.digit[i])
                return a.digit[i] > b.digit[i];
        return false;
    }
    friend bool operator == (BigInt a, BigInt b) {
        if (a.digit.size() != b.digit.size())
            return false;
        int32_t i;
        for (i = a.digit.size() - 1; i != -1; -- i)
            if (a.digit[i] != b.digit[i])
                return false;
        return true;
    }
    friend bool operator != (BigInt a, BigInt b) {
        if (a.digit.size() != b.digit.size())
            return true;
        int32_t i;
        for (i = a.digit.size() - 1; i != -1; -- i)
            if (a.digit[i] != b.digit[i])
                return true;
        return false;
    }
    BigInt operator = (uint64_t a) {
        digit.clear();
        do {
            digit.emplace_back(a % base);
            a /= base;
        } while (a != 0);
        return *this;
    }
    BigInt operator = (BigInt a) {
        digit.clear();
        for (uint32_t i = 0; i != a.digit.size(); ++ i)
            digit.emplace_back(a.digit[i]);
        return *this;
    }
    friend BigInt operator + (BigInt a, uint64_t b) {
        BigInt ans;
        ans.digit.clear();
        uint32_t i;
        uint64_t carry = b;
        for (i = 0; i != a.digit.size(); ++ i) {
            carry += a.digit[i];
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        while (carry != 0) {
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        return ans;
    }
    friend BigInt operator + (BigInt a, BigInt b) {
        BigInt ans;
        ans.digit.clear();
        if (a.digit.size() > b.digit.size())
            std :: swap(a, b);
        uint32_t i;
        uint64_t carry = 0;
        for (i = 0; i != a.digit.size(); ++ i) {
            carry += a.digit[i] + b.digit[i];
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        for (i = a.digit.size(); i != b.digit.size(); ++ i) {
            carry += b.digit[i];
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        while (carry != 0) {
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        return ans;
    }
    friend BigInt operator - (BigInt a, BigInt b) {
        if (a < b)
            std :: swap(a, b);
        BigInt ans;
        ans.digit.clear();
        uint32_t i, j;
        for (i = 0; i != a.digit.size(); ++ i)
            if (a.digit[i] >= b.digit[i])
                ans.digit.emplace_back(a.digit[i] - b.digit[i]);
            else {
                for (j = i + 1; a.digit[j] == 0; ++ j)
                    a.digit[j] = base - 1;
                -- a.digit[j];
                ans.digit.emplace_back(base - b.digit[i] + a.digit[i]);
            }
        while (!ans.digit.empty() and ans.digit.back() == 0)
            ans.digit.pop_back();
        if (ans.digit.empty())
            ans.digit.emplace_back(0);
        return ans;
    }
    friend BigInt operator - (BigInt a, uint64_t b) {
        BigInt ans(b);
        if (a < ans)
            std :: swap(a, ans);
        ans = ans - a;
        return ans;
    }
    friend BigInt operator * (BigInt a, uint64_t b) {
        uint64_t carry = 0;
        uint32_t i;
        BigInt ans;
        ans.digit.clear();
        for (i = 0; i != a.digit.size(); ++ i) {
            carry += a.digit[i] * b;
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        while (carry != 0) {
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        while (!ans.digit.empty() and ans.digit.back() == 0)
            ans.digit.pop_back();
        if (ans.digit.empty())
            ans.digit.emplace_back(0);
        return ans;
    }
    friend BigInt operator * (BigInt a, BigInt b) {
        BigInt ans;
        ans.digit.clear();
        uint32_t i, j;
        for (i = 0; i != a.digit.size() + b.digit.size(); ++ i)
            ans.digit.emplace_back(0);
        for (i = 0; i != a.digit.size(); ++ i)
            for (j = 0; j != b.digit.size(); ++ j)
                ans.digit[i + j] += a.digit[i] * b.digit[j];
        uint64_t carry = 0;
        for (i = 0; i != ans.digit.size(); ++ i) {
            carry += ans.digit[i];
            ans.digit[i] = carry % base;
            carry /= base;
        }
        while (carry != 0) {
            ans.digit.emplace_back(carry % base);
            carry /= base;
        }
        while (!ans.digit.empty() and ans.digit.back() == 0)
            ans.digit.pop_back();
        if (ans.digit.empty())
            ans.digit.emplace_back(0);
        return ans;
    }
    friend BigInt operator / (BigInt a, uint64_t b) {
        BigInt ans;
        ans.digit.clear();
        uint64_t carry = 0;
        int32_t i;
        for (i = 0; i != a.digit.size(); ++ i)
            ans.digit.emplace_back(0);
        for (i = a.digit.size() - 1; i != -1; -- i) {
            carry *= base;
            carry += a.digit[i];
            ans.digit[i] = carry / b;
            carry %= b;
        }
        while (!ans.digit.empty() and ans.digit.back() == 0)
            ans.digit.pop_back();
        if (ans.digit.empty())
            ans.digit.emplace_back(0);
        return ans;
    }
    friend BigInt operator / (uint64_t a, BigInt b) {
        BigInt ans(a);
        ans = a / b;
        return ans;
    }
    friend uint64_t operator % (BigInt a, uint64_t b) {
        uint64_t carry = 0;
        int32_t i;
        for (i = a.digit.size() - 1; i != -1; -- i) {
            carry *= base;
            carry += a.digit[i];
            carry %= b;
        }
        return carry;
    }
    friend BigInt operator % (uint64_t a, BigInt b) {
        BigInt ans(a);
        ans = ans % b;
        return ans;
    }
    friend std :: ostream& operator << (std :: ostream& o, BigInt a) {
        for (int32_t i = a.digit.size() - 1; i != -1; -- i)
            o << a.digit[i];
        return o;
    }
    ~BigInt() {
        digit.clear();
    }
};
