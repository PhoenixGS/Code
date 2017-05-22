//Case 1
void add(int x, int delta)
{
	for (int i = x; i <= n; i += i & (-i))
	{
		bit[i] += delta;
	}
}

int sum(int x)
{
	int ans = 0;
	for (int i = x; i > 0; i -= i & (-i))
	{
		ans += bit[i];
	}
	return ans;
}

int main()
{
	//*1
	add(x, delta);
	//*2
	sum(r) - sum(l - 1);
}

//Case 2
void add(int x, int delta)
{
	for (int i = x; i > 0; i -= i & (-i))
	{
		bit[i] += delta;
	}
}

int sum(int x)
{
	int ans = 0;
	for (int i = x; i <= n; i += i & (-i))
	{
		ans += bit[i];
	}
	return ans;
}

int main()
{
	//*1
	add(l - 1, -c);
	add(r, c);
	//*2
	sum(x);	
}

//Case 3
void add_B(int x, int delta)
{
	for (int i = x; i > 0; i -= i & (-i))
	{
		B[i] += delta;
	}
}

void add_C(int x, int delta)
{
	for (int i = x; i <= n; i += i & (-i))
	{
		C[i] += x * c;
	}
}

int sum_B(int x)
{
	int ans = 0;
	for (int i = x; i <= n; i += i & (-i))
	{
		ans += B[i];
	}
	return ans;
}

int sum_C(int x)
{
	int ans = 0;
	for (int i = x; i > 0; i -= i & (-i))
	{
		ans += C[i];
	}
	return ans;
}

int sum(int x)
{
	return x != 0 ? sum_B(x) * x + sum_C(x - 1) : 0;
}

int main()
{
	//*1
	add_B(r, c);
	add_C(r, c);
	if (l > 1)
	{
		add_B(l - 1, -c);
		add_C(l - 1, -c);
	}
	//*2
	sum(r) - sum(l - 1);
}
