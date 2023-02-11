#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;

constexpr ll INF = numeric_limits<long long>::infinity();

int n;
int arr[100000] = {0, };
int tree_sum[400000] = {0, };
int tree_min_index[400000] = {0, };

int init_min_index(int start, int end, int index) {
  if (start == end) {
    tree_min_index[index] = start - 1;
    return tree_min_index[index];
  }

  int mid = (start + end) / 2;
  int l = init_min_index(start, mid, index * 2);
  int r = init_min_index(mid + 1, end, index * 2 + 1);
  if (arr[l] < arr[r]) {
    tree_min_index[index] = l;
  } else {
    tree_min_index[index] = r;
  }
  return tree_min_index[index];
}

int query_min_index(int start, int end, int index, int left, int right) {
  if (end < left || start > right) {
    return -1;
  }
  if ((start >= left) && (end <= right)) {
    return tree_min_index[index];
  }
  int mid = (start + end) / 2;
  int l = query_min_index(start, mid, index, left, right);
  int r = query_min_index(mid + 1, end, index, left, right);

  if (l == -1) {
    return r;
  } 
  else if (r == -1) {
    return l;
  }
  else {
    if (arr[l] < arr[r]) {
        return l;
    }
    else {
        return r;
    }
  }
}

int init_sum(int start, int end, int index) {
    if (start == end) {
        tree_sum[index] = arr[start-1];
        return tree_sum[index];
    }
    int mid = (start+end) / 2;
    int l = init_sum(start, mid, index*2);
    int r = init_sum(mid+1, end, index*2+1);
    tree_sum[index] = l + r;
    return tree_sum[index];
}

ll query_sum(int start, int end, int index, int left, int right) {
    if ((end < left) || (start > right)) {
        return 0;
    }
    if ((start >= left) && (end <= right)) {
        return tree_sum[index];
    }

    int mid = (start+end) / 2;
    ll l = query_sum(start, mid, index*2, left, right);
    ll r = query_sum(mid+1, end, index*2+1, left, right);
    return l + r;
}

ll divide_and_conquer(int start, int end) {
    int min_index = query_min_index(1, n, 1, start, end);
    ll score = query_sum(1, n, 1, start, end) * arr[min_index];

    min_index++;
    if (start <= min_index - 1) {
        ll tmp_score = divide_and_conquer(start, min_index - 1);
        if (score < tmp_score) {
            score = tmp_score;
        }
    }

    if (end >= min_index + 1) {
        ll tmp_score = divide_and_conquer(min_index + 1, end);
        if (score < tmp_score) {
            score = tmp_score;
        }
    }

    return score;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) { 
        scanf("%d", arr+i);
    }
    init_min_index(1, n, 1);
    init_sum(1, n, 1);
    printf("%lld\n", divide_and_conquer(1, n));
}