#include <stdio.h>

main()
{
	char ope;
	double a, b, ans;
	
	while (1) {
		fflush(stdin);
		
		printf("式を入力してください :");
		scanf("%lf %c %lf", &a, &ope, &b);
		
		switch (ope) {
			case '+' :
				ans = a + b;
				break;
			case '-' :
				ans = a - b;
				break;
			case '*' :
				ans = a * b;
				break;
			case '/' :
				if (b == 0) {
					printf("0で割ることはできません\n");
					continue;
				}
				ans = a / b;
				break;
			default:
				printf("ERROR\n");
				continue;
		}
		
		printf("答え :%lf\n", ans);
	}
}