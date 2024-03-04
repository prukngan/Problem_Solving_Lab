#include <bits/stdc++.h>
using namespace std;

struct section
{
	int	l, r;
};

bool	compare(section &sec1, section &sec2)
{
	return (sec1.l < sec2.l);
}

int	main()
{
	int	n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int	l, r, m;

		cin >> m;
		vector<section> lines(1);
        while (cin >> lines[0].l >> lines[0].r, lines[0].l || lines[0].r)
            lines.push_back(lines[0]);
        sort(lines.begin() + 1, lines.end(), compare);

		vector<int>	ans;
		int			newStart, start = 0;
		int			sec = 1;
		while (start < m)
		{
			newStart = start;
			int	ansSec = 0;
			for (; sec < lines.size(); sec++)
			{
				if (lines[sec].l > start)
					break ;
				if (lines[sec].r > newStart) {
					newStart = lines[sec].r;
					ansSec = sec;
				}
			}
			if (ansSec == 0)
				break;
			ans.push_back(ansSec);
			start = newStart;
		}

		if (start < m || ans.empty())
			cout << 0 << '\n';
		else
		{
			cout << ans.size() << '\n';
			for (auto &sec : ans)
				cout << lines[sec].l << ' ' << lines[sec].r << '\n';
		}

		if (i < n - 1)
			cout << '\n';
	}
	return (0);
}