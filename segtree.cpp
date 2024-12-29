// 구간 합을 반환하는 세그멘트 트리 class

class segtree
{
private:
	ll* A;
	ll* B;
	ll n;
	ll recseg(ll i, ll j, ll s, ll e, ll d)
	{
		if (i > e || j < s) return 0;
		if (i <= s && j >= e)
		{
			return A[d];
		}
		else
		{
			ll mid = (s + e) / 2;
			return recseg(i, j, s, mid, 2 * d) + recseg(i, j, mid + 1, e, 2 * d + 1);
		}
	}
public:
	segtree(ll siz)
	{
		n = siz;
		A = new ll[4 * (n + 1)];
		memset(A, 0, 4 * (n + 1) * sizeof(ll));
		B = new ll[n + 1];
		memset(B, 0, (n + 1) * sizeof(ll));
	}	
	void add(int i, ll c)
	{
		ll l = 1;
		ll r = n;
		ll mid = (l + r) / 2;
		ll d = 1;
		while (l != r)
		{
			A[d] += c;
			if (i <= mid)
			{
				r = mid;
				d = 2 * d;
			}
			else
			{
				l = mid + 1;
				d = 2 * d + 1;
			}
			mid = (l + r) / 2;
		}
		A[d] += c;
		B[i] += c;
	}
	void set(ll i, ll c)
	{
		add(i, c - B[i]);
	}
	
	ll find(ll i, ll j)
	{
		return recseg(i, j, 1, n, 1);
	}
	~segtree()
	{
		delete A;
		delete B;
	}
};
