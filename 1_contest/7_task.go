package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = i + 1
	}

	for i := 2; i < n; i++ {
		a[i], a[i/2] = a[i/2], a[i]
	}

	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	for i := 0; i < n; i++ {
		if i > 0 {
			writer.WriteByte(' ')
		}
		fmt.Fprint(writer, a[i])
	}
	writer.WriteByte('\n')
}
