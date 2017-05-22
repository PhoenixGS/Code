//n <= 200000000
//1 <= a[i] <= (1 << 32) - 1

void radixSort()
{
	p = (1 << 16) - 1;
	for (int k = 0; k <= 65536; k++)
	{
		c[k] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		c[a[i] & p]++;
	}
	for (int i = 1; i <= p; i++)
	{
		c[i] += c[i - 1];
	}
	for (int i = n; i >= 1; i--)
	{
		b[c[a[i] & p]] = a[i];
		c[a[i] & p]--;
	}
	p = p << 16;
	for (int i = 1; i <= n; i++)
	{
		c[a[i] & p]++;
	}
	for (int i = 1; i <= p; i++)
	{
		c[i] += c[i - 1];
	}
	for (int i = n; i >= 1; i--)
	{
		b[c[a[i] & p]] = 
	}
}
