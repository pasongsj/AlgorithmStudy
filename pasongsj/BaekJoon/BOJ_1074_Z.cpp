#include <iostream>
#include <vector>
#include <cmath>


int Getdiv(int n, int r, int c)
{
    if (n == 1)
    {
        return 0;
    }
    if (r < n / 2 && c < n / 2)
    {
        return Getdiv(n / 2, r, c);
    }
    else if (r < n / 2 && c >= n / 2)
    {
        return std::pow(n / 2, 2) + Getdiv(n / 2, r, c - n / 2);
    }
    else if (r >= n / 2 && c < n /2)
    {
        return std::pow(n / 2, 2) * 2 + Getdiv(n / 2, r - n / 2, c);
    }
    else
    {
		return std::pow(n / 2, 2) * 3 + Getdiv(n / 2, r - n / 2, c - n / 2);
    }
}

int main()
{
	int n, r, c;
    std::cin >> n >> r >> c;

    int N = std::pow(2, n);
    
    int answer = Getdiv(N, r, c);

    std::cout << answer;

    return 0;
}
