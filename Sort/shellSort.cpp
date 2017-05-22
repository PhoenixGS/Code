insertionSort(int A[], int n, int g)
{
	for (int i = g; i < n; i++)
	{
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v)
		{
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int A[], int n)
{
	for (int h = 1; ; )
	{
		if (h > n)
		{
			break;
		}
		G.push_back(h);
		h = 3 * h + 1;
	}
}
