#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

long long hashi[1001], p_pow[1001];
long long p = 29;
long long t, n, k;
	

int main()
{
	string s;
	cin >> t;
	p_pow[0] = 1;
    for(long long i = 1; i < 1000; i++)
    {
        p_pow[i] = p_pow[i - 1] * p;
    }
	for(long long i = 0; i < t; i++)
	{
		set<long long> my_set;
		cin >> s;
		hashi[0] = s[0];
		for(long long j = 1; j < s.length(); j++)
		{
			hashi[j] = hashi[j - 1] + s[j] * p_pow[j];
		}
        for (int j = 1; j < s.length(); j++) {
            for(long long m = 0; m + j - 1 < s.length(); m++)
            {
                long long h = hashi[m + j - 1] - hashi[m - 1];
                long long number = h;
                number = number * p_pow[s.length() - m - 1];
                my_set.insert(number);
            }
        }
		cout << my_set.size() + 1 << "\n";
		my_set.clear();
	}
	return 0;
}