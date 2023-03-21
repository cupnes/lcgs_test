/* 線形合同法(Linear congruential generators, LCGs)の実験プログラム

LCGsについて：
- X_{n + 1} = (A * X_n + B) mod M
  - A, B, M :: const
    - M > A
    - M > B
    - A > 0
    - B >= 0
  - 生成される乱数列は周期性を持つ
  - 周期は最大でMであり、以下の条件が満たされたときに最大周期Mをもつ(☆)
    1. BとMが互いに素である(BとMの最大公約数が1である)
    2. A-1が、Mの持つ全ての素因数で割りきれる(A-1が、Mの全ての約数で割り切れる)
    3. Mが4の倍数である場合は、A-1も4の倍数である
- ref
  - 線形合同法 - Wikipedia
    https://ja.wikipedia.org/wiki/%E7%B7%9A%E5%BD%A2%E5%90%88%E5%90%8C%E6%B3%95
*/

#include <stdio.h>

/* ☆の条件を満たす例 */
/*
#define LCGS_A	13
#define LCGS_B	5
#define LCGS_M	24
*/
/*
#define LCGS_A	5
#define LCGS_B	3
#define LCGS_M	32768
*/
/*
#define LCGS_A	5
#define LCGS_B	3
#define LCGS_M	16
*/
/*
#define LCGS_A	5
#define LCGS_B	3
#define LCGS_M	256
*/

#define LCGS_A	5	// 5 - 1 = 4は、262144の持つ全ての素因数(2のみ)で割り切れる, 4の倍数
#define LCGS_B	3	// 3と262144の最大公約数は1
#define LCGS_M	262144	// = 0o1 000 000, 素因数は2のみ, 4の倍数

/* X_0 */
#define LCGS_X0	24

int lcgs(void)
{
	static int xn = LCGS_X0;
	xn = (LCGS_A * xn + LCGS_B) % LCGS_M;
	return xn;
}

int main(void)
{
	int i;
	for (i = 0; i < 1000; i++) {
		printf("%d ", lcgs());
	}
	return 0;
}
