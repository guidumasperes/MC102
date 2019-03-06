#include<stdio.h>

int main(void) {
	float p1, p2, ml, mp, m, e, f;

	scanf("%f", &p1);
	scanf("%f", &p2);
	scanf("%f", &ml);
	mp = (2*p1 + 3*p2) / 5;
	m = (3*mp*ml) / (mp + 2*ml);
	if(m < 2.5) {
		printf("%.1f\n", mp);
		printf("%.1f\n", m);
		printf("%.1f\n", m);
	} else if(m >= 2.5 && m < 5) {
		scanf("%f", &e);
		f = (m + e) / 2;
		if(f >= 5.0) {
			printf("%.1f\n", mp);
			printf("%.1f\n", m);
			printf("5.0\n");
		} else {
			printf("%.1f\n", mp);
			printf("%.1f\n", m);
			printf("%.1f\n", f);
		}
	} else {
		printf("%.1f\n", mp);
		printf("%.1f\n", m);
		printf("%.1f\n", m);
	}
	return 0;
}
