def is_achievable(N, X, jumps):
  dp = [[False for _ in range(X + 1)] for _ in range(N + 1)]
  dp[0][0] = True

  for i in range(1, N + 1):
    for j in range(X + 1):
      for jump in jumps[i - 1]:
        if j >= jump and dp[i - 1][j - jump]:
          dp[i][j] = True

  return "Yes" if dp[N][X] else "No"

N, X = map(int, input().split())
jumps = [tuple(map(int, input().split())) for _ in range(N)]

print(is_achievable(N, X, jumps))