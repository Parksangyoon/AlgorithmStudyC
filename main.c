#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct Point {
	int x, y;
	Point operator -(const Point A)const {
		return{ x - A.x,y - A.y };
	}
	bool operator <(const Point A)const {
		return x == A.x ? y<A.y : x<A.x;
	}
};

int ccw(Point A, Point B) {
	return A.x*B.y - B.x*A.y;
}
int ccw(Point A, Point B, Point C) {
	int t = ccw(B - A, C - A);
	return t<0 ? -1 : t>0;
}

int N;
Point d[10001];
vector<Point> uc, dc;
int us;

void monotoneChain() {
	uc.push_back(d[1]);
	uc.push_back(d[2]);
	us = 2;
	for (int i = 3; i <= N; i++) {
		while (us >= 2 && ccw(uc[us - 2], uc[us - 1], d[i]) >= 0) {
			uc.pop_back();
			us--;
		}
		uc.push_back(d[i]);
		us++;
	}
}

int main()
{
    int test_case;
    int T, answer=0;
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}
