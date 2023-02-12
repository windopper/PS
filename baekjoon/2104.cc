#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
#include <functional>

typedef long long ll;

using namespace std;
const int MAX = 1000001;

int n;
int a[MAX];

ll dac(int start, int end) {

  if (start == end) {
    return (ll)a[start] * a[start];
  }

  if (start > end) {
    return 0;
  }

  int mid = (start + end) / 2;
  ll result = 0;
  result = max(dac(start, mid), dac(mid+1, end));

  int left = mid, right = mid+1;
  int tempMin = min(a[left], a[right]);
  ll tempSum = a[left] + a[right];
  ll tempMaxScore = (ll)tempSum * tempMin;

  while (left > start || right < end) {
    if (left > start && ( right == end || a[left-1] > a[right+1])) {
      tempMin = min(tempMin, a[--left]);
      tempSum += a[left];
    }
    else {
      tempMin = min(tempMin, a[++right]);
      tempSum += a[right];
    }
    tempMaxScore = max(tempMaxScore, (ll)tempSum * tempMin);
  }

  result = max(result, tempMaxScore);

  return result;
}

int main() {

  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  cout << dac(0, n-1);

  return 0;
}