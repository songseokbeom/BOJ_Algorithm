#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int arr[501], sum[501];
double avg, min2;

int main()
{
	int n, k, sum=0, cnt=0;
	min2 = 987654;

	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	for (int a = k; a <= n; a++)
	{
		for (int i = 0; i <= n - a; i++)
		{
			double temp = 0.0, avg = 0.0;

			for (int j = i; j < i + a; j++)
				avg += arr[j];
			avg = avg / a;

			for (int j = i; j < i + a; j++)
				temp += pow(arr[j] - avg, double(2));
			temp = sqrt(temp / a);

			if (temp < min2)
				min2 = temp;
		}
	}
	printf("%lf\n", min2);

	return 0;
}