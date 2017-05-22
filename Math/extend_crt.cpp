ll ex_crt()
{
	ll M = m[1], R = r[1];
	for (int i = 2; i <= n; i++)
	{
		ll d = gcd(M, m[i]);
		ll c = r[i] - R;
		if (c % d != 0)
		{
			return -1;
		}
		ll x, y;
		ll t = extend_gcd(M / d, m[i] / d, x, y);
		x = (c / d * x) % (m[i] / d);
		R = R + x * M;
		M = M / d * m[i];
		R %= M;
	}
	if (R < 0)
	{
		R += M;
	}
	return R;
}
