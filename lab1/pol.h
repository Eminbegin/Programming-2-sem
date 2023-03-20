#include <vector>
#include <math.h>
#include <iostream>

#include <string>
#include <map>
#include <exception>

void zero_clean(std::map<int, double>& dc) {
    for (auto it = dc.begin(); it != dc.end();) {
                if (it->second == 0) {
                    it = dc.erase(it);
                } else {
                    ++it;
                }     
            }
            if (dc.empty())
                dc[0] += 0;
}
class Polynom{
    public:
        std::map<int, double> degs_coeffs;
        
        Polynom() {
            degs_coeffs[0] = 0;
        }

        Polynom(const std::map<int, double> &coeff) {
            degs_coeffs = coeff;
            zero_clean(degs_coeffs); 
            }

        Polynom(const std::vector<double> &coeff) {
            for (int i = 0; i < coeff.size(); i++)
                if (coeff[i] != 0) 
                    degs_coeffs[i] = coeff[i];
            if (degs_coeffs.empty())
                degs_coeffs[0] = 0;
            zero_clean(degs_coeffs);
        }

        Polynom(const Polynom &other): degs_coeffs(other.degs_coeffs) {}

        ~Polynom() = default;
        
        Polynom& operator= (const Polynom &other) {
            degs_coeffs = other.degs_coeffs;
            return *this;
        }

        bool operator== (const Polynom &other) const {
            return degs_coeffs == other.degs_coeffs;
        }
        
        bool operator!= (const Polynom &other) const {
            return degs_coeffs != other.degs_coeffs;
        }

        Polynom& operator+= (const Polynom &other) {
            for (const auto& p: other.degs_coeffs)
                degs_coeffs[p.first] += p.second;
            zero_clean(degs_coeffs);
            return *this;
        }

        Polynom& operator-= (const Polynom &other) {
            for (const auto& it: other.degs_coeffs)
                degs_coeffs[it.first] -= it.second;
            zero_clean(degs_coeffs);
            return *this;
        }
        
        friend Polynom operator+ (const Polynom &other1, const Polynom &other2) {
            Polynom temp = other1;
            temp += other2;
            return temp;
        }
        
        friend Polynom operator- (const Polynom &other1, const Polynom &other2) {
            Polynom temp = other1;
            temp -= other2;
            return temp;
        }
        
        friend Polynom operator- (const Polynom &other){
            Polynom temp;
            for (const auto& iter: other.degs_coeffs)
                temp.degs_coeffs[iter.first] = (-1) * iter.second;
            return temp;
        } 
    
        Polynom &operator*= (double num) {
            for (const auto& iter: degs_coeffs)
                degs_coeffs[iter.first] *= num;
            zero_clean(degs_coeffs);
            return *this;
        }

        friend Polynom operator* (const Polynom polynom1,const double num) {
            Polynom pol_a;
            pol_a = polynom1;
            pol_a *= num;
            return pol_a;
        }

        friend Polynom operator* (const double num, const Polynom polynom1) {
            Polynom pol_a;
            pol_a = polynom1;
            pol_a *= num;
            return pol_a;
        }
        
        Polynom &operator/= (double num) {
            if (num == 0){
                throw std::invalid_argument("division by zero");
            }
            else
                for (const auto& iter: degs_coeffs)
                    degs_coeffs[iter.first] /= num;
            return *this;
        }

        Polynom defferentiation() const {
            Polynom defpol;
            for (const auto& iter: degs_coeffs)
                if (iter.first != 0)
                    defpol.degs_coeffs[iter.first - 1] = iter.second * iter.first;
            zero_clean(defpol.degs_coeffs); 
            return defpol;       
        }

        Polynom integration(double constant = 0) const {
            Polynom defpol;
            for (const auto& iter: degs_coeffs)
                defpol.degs_coeffs[iter.first + 1] = iter.second / (iter.first + 1);
            defpol.degs_coeffs[0] = constant;
            zero_clean(defpol.degs_coeffs); 
            return defpol;       
        }

        Polynom& operator*= (const Polynom& other) {
            Polynom save;
            for (const auto& iter1: degs_coeffs)
                for (const auto& iter2: other.degs_coeffs)
                    save.degs_coeffs[iter1.first + iter2.first] += iter2.second * iter1.second;
            *this = save;
            zero_clean(degs_coeffs);
            return *this;
        }

        friend Polynom operator* (const Polynom& other1, const Polynom& other2) {
            Polynom pol_a;
            pol_a = other1;
            pol_a *= other2;
            return pol_a;
        }
        
        double operator[] (const int& num){
            if (!degs_coeffs.count(num))
                return 0;
            return degs_coeffs[num];
        }
        
        friend std::ostream& operator << (std::ostream &out, const Polynom &other) {
            bool flag = true;
            for (const auto& it:other.degs_coeffs){
                if (it.first == 0)
                    if (it.second != 0) {
                        out << it.second;
                        flag = false;
                }
                else if (it.first == 1) {
                    if (!flag){
                        if (it.second > 0) {
                            if (it.second != 1)
                                out << " + " << it.second << "x";
                            else
                                out << " + " << "x";
                        }
                        if (it.second < 0) {
                            if (it.second != -1)
                                out << " - " << fabs(it.second) << "x";
                            else
                                out << " - " << "x";
                        }
                            
                    }
                    if (flag){
                        if (it.second > 0){
                            if (it.second != 1){
                                out << it.second << "x";
                                flag = false;
                            }
                            else {
                                out << "x";
                                flag = false;
                            }
                        }
                        if (it.second < 0){
                            if (it.second != -1) {
                                out << "- " << fabs(it.second) << "x";
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
                    if (it.second > 0) {
                        if (it.second != 1)
                            out << " + " << it.second << "x^" << it.first;
                        else 
                            out << " + " << "x^" << it.first;
                    }
                    if (it.second < 0 )
                        if (it.second != -1)
                            out << " - " << fabs(it.second) << "x^" << it.first;
                        else
                            out << " - " << "x^" << it.first;
                }
                else if (flag) {
                    if (it.second > 0) {
                        if (it.second != 1) {
                            out << it.second << "x^" << it.first;
                            flag = false;
                        }
                        else {
                            out << "x^" << it.first;
                            flag = false;
                        }
                    }
                    if (it.second < 0) {
                        if (it.second != -1) {
                            out << "- " << fabs(it.second) << "x^" << it.first;
                            flag = false;
                        }
                        else {
                            out << "- " << "x^" << it.first;
                            flag = false;
                        }
                    }
                }
            }
            if (flag)
                out << 0; 
            out << "\n";
            return out;
        }

        friend Polynom& operator >> (std::istream &in, Polynom &other) {
            int deg;
            double coef;
            other.degs_coeffs.clear();
            while (in >> deg, in >> coef){
                other.degs_coeffs[deg] += coef;
            }
            zero_clean(other.degs_coeffs);
            return other;
        }
};
