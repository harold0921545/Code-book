# input many integers : 
a, b = map(int, input().split())
# input array : 
a = list(map(int, input().split()))
x = [int(i) for i in a]
# input 2D array
n = int(input())
line = [[0] * n] * n
for i in range(n):
    line[i] = input().split()
    line[i] = [int(j) for j in line[i]]
# set
st = set()
st.add()
st.remove()
x in st
max(st)
# list
lst = []
lst.pop(1) # pop index 1
lst.append()
# others
mp = {'A' : 1, 'B' : 2}
mp['A']
