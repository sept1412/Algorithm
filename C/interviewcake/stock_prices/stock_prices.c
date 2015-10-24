#include <stdio.h>
#include <string.h>

int find_max(int *stocks, size_t len)
{
  int i, max = stocks[0];
  for (i = 1; i < len; i++)
  {
    if (stocks[i] > max)
    {
      max = stocks[i];
    }
  }
  return max;
}

int find_min(int *stocks, size_t len)
{
  int i, min = stocks[0];
  for (i = 1; i < len; i++)
  {
    if (stocks[i] < min)
    {
      min = stocks[i];
    }
  }
  return min;
}

int max (int l, int r)
{
  if (l > r)
    return l;
  return r;
}

int min (int l, int r)
{
  if (l > r)
    return r;
  return l;
}

int best_profit (int *stocks, size_t stock_size)
{
  int best_profit = 0;
  int rmax, lmin = 0;
  int lbest, rbest, cbest;
  int half_size = (stock_size+1)/2;

  if (stock_size > 2)
  {
    
    rmax = find_max (stocks + half_size, half_size); 
    lmin = find_min (stocks, half_size;

    lbest  = best_profit (stocks, stock_size/2);
    rbest  = best_profit (stocks + stock_size/2, stock_size/2);
    cbest  = lmax - rmin;
    
    cbest = max(cbest, lbest);
    return max(cbest, rbest);
  }
  else
  {
    if (stock_size == 1)
      return stocks[0];
    return max(stocks[0], stocks[1]);
  }

  return best_profit;
}


int main()
{
  //divide
  int stocks[10000], stock_size;

  printf ("Best profit is %d\n", best_profie(stocks, stock_size));
  return 0;
}

