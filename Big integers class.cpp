#include <fstream>
#include <vector>
static const uint64_t base = 10;
class BigInt {
private:
    std :: vector <uint64_t> digit;
public:
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
    int8_t comp(BigInt a, uint64_t b) {
        BigInt aux(b);
        if (a.digit.size() < aux.digit.size())
            return -1;
        if (a.digit.size() > aux.digit.size())
            return 1;
        int32_t i;
        for (i = a.digit.size() - 1; i != -1; -- i) {
            if (a.digit[i] < aux.digit[i])
                return -1;
            if (a.digit[i] > aux.digit[i])
                return 1;
        }
        return 0;
    }
    int8_t comp(BigInt a) {
        if (digit.size() < a.digit.size())
            return -1;
        if (digit.size() > a.digit.size())
            return 1;
        int32_t i;
        for (i = digit.size() - 1; i != -1; -- i) {
            if (digit[i] < a.digit[i])
                return -1;
            if (digit[i] > a.digit[i])
                return 1;
        }
        return 0;
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
    BigInt diff(BigInt a) {
        BigInt ans;
        ans.digit.clear();
        uint32_t i, j;
        for (i = 0; i != digit.size(); ++ i)
            if (digit[i] >= a.digit[i])
                ans.digit.emplace_back(digit[i] - a.digit[i]);
            else {
                for (j = i + 1; digit[j] == 0; ++ j)
                    digit[j] = base - 1;
                -- digit[j];
                ans.digit.emplace_back(base - a.digit[i] + digit[i]);
            }
        while (!ans.digit.empty() and ans.digit.back() == 0)
            ans.digit.pop_back();
        if (ans.digit.empty())
            ans.digit.emplace_back(0);
        return ans;
    }
    BigInt diff(uint64_t a) {
        BigInt ans(a);
        ans = diff(ans);
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
    BigInt div(uint64_t a) {
        BigInt ans;
        ans.digit.clear();
        uint64_t carry = 0;
        int32_t i;
        for (i = 0; i != digit.size(); ++ i)
            ans.digit.emplace_back(0);
        for (i = digit.size() - 1; i != -1; -- i) {
            carry *= base;
            carry += digit[i];
            ans.digit[i] = carry / a;
            carry %= a;
        }
        while (!ans.digit.empty() and ans.digit.back() == 0)
            ans.digit.pop_back();
        if (ans.digit.empty())
            ans.digit.emplace_back(0);
        return ans;
    }
    BigInt mod(uint64_t a) {
        uint64_t carry = 0;
        int32_t i;
        for (i = digit.size() - 1; i != -1; -- i) {
            carry *= base;
            carry += digit[i];
            carry %= a;
        }
        return carry;
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
