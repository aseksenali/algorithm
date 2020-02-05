#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

long small(long a[], long k, long n) {
    long curr_sum = 0;
    long min_len = n + 1;
    long start = 0, end = 0;
    while (end < n)
    {
        while (curr_sum < k && end < n)
            curr_sum += a[end++];
        while (curr_sum >= k && start < n)
        {
            if (end - start < min_len)
                min_len = end - start;
            curr_sum -= a[start++];
        }
    }
    return min_len;
}

long bin(long a[], long k, long start, long n) {
    long r = n, l = start, mid;
    if (a[r - 1] < k)
        return 100000001;
    while ((r - l) > 1) {
        mid = (r + l) / 2;
        if (a[mid] == k)
        {
            return mid; 
            break;
        }
        if (k > a[mid]) 
            l = mid;
        else 
            r = mid;
    }
    return r;
}

long minim(long a, long b) {
    if (a < b) return a;
    return b;
}

long minlen(long a[], long k, long n) {
    long sum[n + 1];
    sum[0] = 0;
    sum[1] = a[0];
    for (long i = 2; i < n + 1; i++) 
        sum[i] = sum[i - 1] + a[i - 1];
    long min = n;
    
    for (long i = 0; i < n + 1; i++) {
        min = minim(bin(sum, k + sum[i], i, n + 1) - i, min);
    }
    
    return min;
}

int main() {
    for (int j = 0; j < 10; j++) {
        long n = 0, k = 0;
        long a[n];
    for (long i = 0; i < n; i++) { 
            a[i] = rand() % 10000 + 1;
        }
        cout << minlen(a, k, n) << endl;
        cout << small(a, k, n) << endl;
    }
    return 0;
}