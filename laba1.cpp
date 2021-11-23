#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int main ()
{
std::vector<int>wts;
wts.push_back(3);
wts.push_back(2);
wts.push_back(1);
wts.push_back(11);
std::vector<int >cost;
cost.push_back(100);
cost.push_back(300);
cost.push_back(1200);
cost.push_back(300);
int W = 3;
size_t n = wts.size();
	std::vector<int> dp(W + 1);
	dp[0] = 0;
	for (int w = 1; w <= W; w++)
	{
		dp[w] = dp[w-1];
		for (size_t i = 0; i < n; i++)
		{
			if (wts[i] <= w)
			{
				dp[w] = std::max(dp[w], dp[w - wts[i]] + cost[i]);
			}
		}
	}
	std::cout << dp[W];
	}
