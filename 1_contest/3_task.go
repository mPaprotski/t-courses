package main

import (
	"fmt"
)

func main() {
	var n int
	if _, err := fmt.Scan(&n); err != nil {
		return
	}

	l, r := 0, n
	for l < r {
		m := (l + r + 1) / 2
		fmt.Println(m)

		var ans string
		fmt.Scan(&ans)

		if ans == ">=" {
			l = m
		} else {
			r = m - 1
		}
	}

	fmt.Printf("! %d\n", l)
}
