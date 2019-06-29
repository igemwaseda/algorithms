n,m = map(int, input().split())

k = []
s = []
p = []

for i in range(m):
	int_arr = list(map(int , input().split()))
	k.append(int_arr[0])
	s.append(list(map(lambda x: x-1, int_arr[1:])))

p = list(map(int , input().split()))

on_pattern_cnt = 0

for s_pattern_int in range(2**n):
	s_pattern_binstr = str(bin(s_pattern_int)) # 2進数文字列化
	s_pattern_binstr = s_pattern_binstr[2:] # 0bの削除
	s_pattern_binstr = s_pattern_binstr.zfill(n)				# 上位を0で埋める
	s_pattern_binstr = s_pattern_binstr[::-1] # 反転

	s_pattern = []
	for c in s_pattern_binstr:
		s_pattern.append(int(c))

	all_on_flag = True
	for i in range(m): # 電球に関するループ
		on_cnt = 0
		for j in range(k[i]): # スイッチに関するループ
			if s_pattern[s[i][j]] == 1:
				on_cnt += 1

		if p[i] != on_cnt % 2:
			all_on_flag = False
			break

	if all_on_flag:
		on_pattern_cnt += 1

print(on_pattern_cnt)