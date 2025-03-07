#include <stdio.h>
// code for finding all g sized groups into which n items can be divided such that each gets atleast 1

int grouping(int a[], int k, int g, int n)
{
  int ans = 0, i;
  if (g == 1)
  {
    a[k] = n;
    for (i = 0; i <= k; i++)
      printf("%d ", a[i]);
    printf("\n");
    return 1;
  }
  for (i = 1; i <= n - g + 1; i++)
  {
    a[k] = i;
    ans += grouping(a, k + 1, g - 1, n - i);
  }
  return ans;
}

int main()
{
  int a[100], n, g, ans;
  printf("Enter n and g (g < n): ");
  scanf("%d%d", &n, &g);
  ans = grouping(a, 0, g, n); // function call
  printf("#groupings = %d\n", ans);
  return 0;
}
