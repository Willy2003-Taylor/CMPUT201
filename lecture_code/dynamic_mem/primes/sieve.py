
import sys
def primeSieve(n):
  arr = list(range(2,n))
  i = 0
  while i < len(arr):
    print(f"{arr[i]}", end=" ")
    iter = i + arr[i]
    while iter < len(arr):
      arr[iter] = 0
      iter = iter + arr[i]
    i = i + 1
    while (i < len(arr) and arr[i] == 0):
      i = i + 1
  print()

def main():
  num = int(input())
  primeSieve(num)

if __name__ == "__main__":
  main()
