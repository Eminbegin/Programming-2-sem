#ifndef POLY_HPP
#define POLY_HPP
#include <cmath>

template <int ...arguments>
class Poly {
private:
    const static constexpr int size = sizeof ...(arguments);
    const static constexpr int coefs[size] = {arguments...};
public:
    constexpr Poly() = default;
    [[nodiscard]] constexpr int findValue(const int x) const {
        if (size == 0) {
            return 0;
        }

        if (x == 0) {
            return coefs[0];
        }

        int a = 0;
        for (int i = size - 1; i >= 0; --i) {
            a *= x;
            a += coefs[i];
        }
        return a;
    }
    friend std::ostream& operator<< (std::ostream& out, Poly& p) {
        bool flag = true;
        for (int i = 0; i < size; ++i){
            if (i == 0){
                if (coefs[i] != 0) {
                    out << coefs[i];
                    flag = false;
                }
            }
            else if (i == 1) {
                if (!flag){
                    if (coefs[i] > 0) {
                        if (coefs[i] != 1)
                            out << " + " << coefs[i] << "x";
                        else
                            out << " + " << "x";
                    }
                    if (coefs[i] < 0) {
                        if (coefs[i] != -1)
                            out << " - " << fabs(coefs[i]) << "x";
                        else
                            out << " - " << "x";
                    }

                }
                if (flag){
                    if (coefs[i] > 0){
                        if (coefs[i] != 1){
                            out << coefs[i] << "x";
                            flag = false;
                        }
                        else {
                            out << "x";
                            flag = false;
                        }
                    }
                    if (coefs[i] < 0){
                        if (coefs[i] != -1) {
                            out << "- " << fabs(coefs[i]) << "x";
                            flag = false;
                        }
                        else {
                            out << "- " << "x";
                            flag = false;
                        }

                    }
                }

            }
            else if (!flag) {
                if (coefs[i] > 0) {
                    if (coefs[i] != 1)
                        out << " + " << coefs[i] << "x^" << i;
                    else
                        out << " + " << "x^" << i;
                }
                if (coefs[i] < 0 )
                    if (coefs[i] != -1)
                        out << " - " << fabs(coefs[i]) << "x^" << i;
                    else
                        out << " - " << "x^" << i;
            }
            else if (flag) {
                if (coefs[i] > 0) {
                    if (coefs[i] != 1) {
                        out << coefs[i] << "x^" << i;
                        flag = false;
                    }
                    else {
                        out << "x^" << i;
                        flag = false;
                    }
                }
                if (coefs[i] < 0) {
                    if (coefs[i] != -1) {
                        out << "- " << fabs(coefs[i]) << "x^" << i;
                        flag = false;
                    }
                    else {
                        out << "- " << "x^" << i;
                        flag = false;
                    }
                }
            }
        }
        if (flag)
            out << 0;
        return out;
    }
};

#endif