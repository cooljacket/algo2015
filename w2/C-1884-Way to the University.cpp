// timus 1884-Way to the University
// 给大逗比的
#include <iostream>
#include <iomanip>
using namespace std;

// man的意义是：人横过马路这段时间内，汽车可以走过多少米，man = (20km/h) / (5km/h) * 2m = 8m
// car表示的是车的长度
const int MAX = 10100, man = 8, car = 5, LEFT = 1, RIGHT = 2, LR = 3;
double CarSpeed = 20 * 1000.0 / 3600.0;
int road[MAX];

/*
把一条路看成一个数轴（把右车道对折到跟左车道同侧），只看整数点。
对于每个整数点D，赋予它一个属性：
1）LEFT：只被左边的车占用；
2）RIGHT：只被右边的车占用；
3）LR：这一时刻上同时有左右的车
4）0（数组定义在全局，默认值为0）：空闲，人可以走

这样的话，问题就转化为——
从某点D开始，可以找到一个长度为man的区间，它是空闲的或者仅被右边占用，这样意味着它可以通过左边车道；
并且，从这个区间结束的地方开始，可以找到一个长度为man的区间，它是空闲的或者仅被左边占用，这样意味着它可以通过右边的车道。
*/

int main() {
	int n, m, tmp;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		for (int j = 0; j < car; ++j)
			road[tmp+j] = LEFT;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> tmp;
		// 注意车的长度为5米，所以要将其后连续的点标记为被左边的车占用，下面同理
		for (int j = 0; j < car; ++j)
			road[tmp+j] = ((road[tmp+j] == LEFT) ? LR : RIGHT);
	}

	for (int i = 0; i < MAX; ++i) {
		bool good = true;
		for (int j = 0; j < man; ++j) {
			if (road[i+j] == LEFT || road[i+j] == LR) {
				good = false;
				break;
			}
		}
		if (!good)
			continue;

		// good = true表示人可以走过左边的车道了，接下来只需要判断是否可以通过右车道了
		int base = i + man;
		for (int j = 0; j < man; ++j) {
			if (road[base+j] == RIGHT || road[base+j] == LR) {
				good = false;
				break;
			}
		}
		if (good) {
			cout << fixed << setprecision(8) << i * 1.0 / CarSpeed << endl;
			break;
		}
	}

	return 0;
}