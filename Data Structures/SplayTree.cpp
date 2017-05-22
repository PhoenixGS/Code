void rorate(int x, int &k)
{
	int y = fa[x], z = fa[y];
	int l, r;
	if (tr[y][0] == x)
	{
		l = 0;
	}
	else
	{
		l = 1;
	}
	r = l ^ 1;
	if (y == k)
	{
		k = x;
	}
	else
	{
		if (tr[z][0] == y)
		{
			tr[z][0] = x;
		}
		else
		{
			tr[z][1] = x;
		}
	}
	fa[x] = z;
	fa[y] = x;
	fa[tr[x][r]] = y;
	tr[y][l] = tr[x][r];
	tr[x][r] = y;
}

void splay(int x, int &k)
{
	int y, z;
	while (x != k)
	{
		y = fa[x], z = fa[y];
		if (y != k)
		{
			if ((tr[y][0] == x) ^ (tr[z][0] == y))
			{
				rorate(x, k);
			}
			else
			{
				rorate(y, k);
			}
		}
		rorate(x, k);
	}
}

void insert(int &k, int x, int father)
{
	if (k == 0)
	{
		size++;
		k = size;
		tree[size] = x;
		fa[size] = father;
		splay(k, root);
		return;
	}
	if (x < tree[k])
	{
		insert(tr[k][0], x, k);
	}
	else
	{
		insert(tr[k][1], x, k);
	}
}

void prev(int k, int x)
{
	if (k == 0)
	{
		return;
	}
	if (tree[k] <= x)
	{
		ansmax = tree[k];
		prev(tr[k][1], x);
	}
	else
	{
		prev(tr[k][0], x);
	}
}

void next(int root, int x)
{
	if (root == 0)
	{
		return;
	}
	if (tree[root] >= x)
	{
		ansmin = tree[root];
		next(tr[root][0], x);
	}
	else
	{
		next(tr[root][1], x);
	}
}

