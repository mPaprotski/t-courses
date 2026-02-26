package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func merge(arr, temp []int64, l, m, r int) int64 {
	i, j, k := l, m+1, l
	var inv int64 = 0

	for i <= m && j <= r {
		if arr[i] <= arr[j] {
			temp[k] = arr[i]
			i++
		} else {
			temp[k] = arr[j]
			j++
			inv += int64(m - i + 1)
		}
		k++
	}

	for i <= m {
		temp[k] = arr[i]
		i++
		k++
	}
	for j <= r {
		temp[k] = arr[j]
		j++
		k++
	}

	for idx := l; idx <= r; idx++ {
		arr[idx] = temp[idx]
	}

	return inv
}

func mergeSort(arr, temp []int64, l, r int) int64 {
	var inv int64 = 0
	if l < r {
		m := l + (r-l)/2
		inv += mergeSort(arr, temp, l, m)
		inv += mergeSort(arr, temp, m+1, r)
		inv += merge(arr, temp, l, m, r)
	}
	return inv
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	next := func() int64 {
		sc.Scan()
		val, _ := strconv.ParseInt(sc.Text(), 10, 64)
		return val
	}

	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	nStr := ""
	if sc.Scan() {
		nStr = sc.Text()
	}
	n, _ := strconv.Atoi(nStr)

	arr := make([]int64, n)
	temp := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = next()
	}

	inv := mergeSort(arr, temp, 0, n-1)

	fmt.Fprintln(writer, inv)

	for i := 0; i < n; i++ {
		if i > 0 {
			writer.WriteByte(' ')
		}
		fmt.Fprint(writer, arr[i])
	}
	writer.WriteByte('\n')
}
