#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

bool canAchieve(vector<int>& A, vector<int>& B, vector<int>& C, int mid, long long& cost) {
int N = A.size();
 long long curCost = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> curA = A;

 for (int i = 0; i < N; ++i) {
 if (curA[i] > mid) {
pq.push({C[i], i});
}
}

 for (int i = 0; i < N; ++i) {
 while (curA[i] < mid) {
if (pq.empty()) return false;
 auto [costIdx, idx] = pq.top(); pq.pop();
if (curA[idx] <= mid || curA[idx] <= B[idx]) continue;

 int move = min(mid - curA[i], curA[idx] - max(B[idx], mid));
curA[i] += move;
 curA[idx] -= move;
curCost = (curCost + 1LL * move * costIdx) % MOD;

if (curA[idx] > mid) {
pq.push({C[idx], idx});
}
}
}
cost = curCost;
return true;
}

pair<int, long long> findMaxMin(vector<int>& A, vector<int>& B, vector<int>& C) {
int left = *min_element(B.begin(), B.end());
int right = *max_element(A.begin(), A.end());
int ans = left;
 long long minCost = LLONG_MAX;

 while (left <= right) {
 int mid = left + (right - left) / 2;
 long long cost = 0;
 if (canAchieve(A, B, C, mid, cost)) {
 ans = mid;
 minCost = cost;
 left = mid + 1;
 } else { right = mid - 1;
 }
}
return {ans, minCost};
}

intmain() {
int T;
cin >> T;
while (T--) {
 int N;
 cin >> N;
 vector<int> A(N), B(N), C(N);
 for (int i = 0; i < N; ++i) {
cin >> A[i];
 }
 for (int i = 0; i < N; ++i) {
cin >> B[i];
 }
 for (int i = 0; i < N; ++i) {
cin >> C[i];
 }
 pair<int, long long> result = findMaxMin(A, B, C);
 cout << "[" << result.first << ", " << result.second << "]" << endl;
}
return 0;
}
