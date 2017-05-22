int extend_gcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = extend_gcd(b, a % b, x, y);
	int t = y;
	y = x - (int)(a / b) * y;
	x = t;
	return r;
}

int extend_gcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = extend_gcd(b, a % b, y, x);
	y -= x * (a / b);
	return r;
}

