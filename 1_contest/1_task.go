package main

import (
	"bufio"
	"os"
	"strconv"
)

func binSearch(arr []int, x int) bool {
	l, r := 0, len(arr)-1
	for l <= r {
		m := l + (r-l)/2
		if arr[m] == x {
			return true
		}
		if arr[m] < x {
			l = m + 1
		} else {
			r = m - 1
		}
	}
	return false
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	next := func() int {
		scanner.Scan()
		val, _ := strconv.Atoi(scanner.Text())
		return val
	}

	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := next()
	m := next()

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = next()
	}

	for i := 0; i < m; i++ {
		x := next()
		if binSearch(arr, x) {
			writer.WriteString("YES ")
		} else {
			writer.WriteString("NO ")
		}
	}
	writer.WriteString("\n")
}
