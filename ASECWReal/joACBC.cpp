
std::vector<unsigned int> joACBC(unsigned int n, unsigned int m)
{
	std::vector<unsigned int> v(n+1,0), result(n,0);
	for (unsigned int x =0; x<n; ++x)
		v[x] = x+1;
	v[n] = 1;

	unsigned int c, k;
	unsigned int curr = 0;
	unsigned int dp = 0;
	for (k=0; k<n; ++k)
	{
		for (c = 1; c < m; c++)
			curr = v[curr];
		v[dp] = v[curr];
		v[curr] = v[ v[curr] ];
		dp = v[dp];
	}
	dp=0;
	for (k=0; k<n; ++k)
	{
		result[k] = v[dp];
		dp=v[dp];
	}
	return result;
}
