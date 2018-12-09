//
// Created by Pankaj Birat on 28/11/18.
//

#include "headers.hpp"
#ifndef DSA_COMMON_FUNCTIONS_H
#define DSA_COMMON_FUNCTIONS_H

template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}
template<class T> T GCD(T a , T b) {if(b == 0)return a; else return GCD(b , a%b);}
template<class T>  T MulMod(T a , T b , T mod) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y)%mod; y = (y<<1)%mod;b >>= 1;}return x;}
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
template<class T>  T Multiply(T a , T b) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y);y = (y<<1);b >>= 1;}return x;}
template<class T>  T Power(T a , T b) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y);y = (y*y);b >>= 1;}return x;}
template <class F, class S>
ostream &operator<<(std::ostream &os, pair<F,S> const &pair) {
    return os << "{" << pair.F << ","<< pair.S << "}";
}
const int MAXE6 = 1e6+10;
const LLI MODE9_7 = 1e9+7;
const LLI MODE9_9 = 1e9+9;

#endif //DSA_COMMIN_FUNCTIONS_H
