#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

#define MAX_N 100000

void print_array(const char *s, int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i) printf(", ");
    else printf("%s: [", s);
    printf("%d", a[i]);
  }
  printf("]\n");
}

void reconstruct_print(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}

int main() {
  int n = 6, A[] = {2,1,3,8,5,4};
  int L[MAX_N], L_id[MAX_N], P[MAX_N];

  int lis = 0, lis_end = 0;
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(L, L + lis, A[i]) - L;
    // int pos = lower_bound(L, L + lis, A[i], greater<int>()) - L;
    
    //se queda 
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    }

    // printf("Considering element A[%d] = %d\n", i, A[i]);
    // printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
    // reconstruct_print(i, A, P);
    // cout<<"lis_end so far is "<<lis_end<<endl;
    // print_array("L is now", L, lis);
    // print_array("L_id is now", L_id, lis);
    // print_array("p is now", P, n);
    // printf("\n");
  }

  printf("Final LIS is of length %d: ", lis);
  reconstruct_print(lis_end, A, P);
  return 0;
}