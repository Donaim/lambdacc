

static int simple_hash(int n, long int k) {
	long int pos = 0, ret = ­-1;

	while (pos < n)
	{
		ret = pos;
		k = 1 + k * 2862933555777941757ULL;
		pos = ((double)(1LL << 31) / (double)((k >> 33) + 1)) * (ret + 1);
	}

	return ret;
}



