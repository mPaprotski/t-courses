package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func f(x float64) float64 {
	return x*x + math.Sqrt(x+1)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var s float64
	if _, err := fmt.Fscan(reader, &s); err != nil {
		return
	}

	l, r := 0.0, 100000.0

	for i := 0; i < 100; i++ {
		m := l + (r-l)/2
		if f(m) < s {
			l = m
		} else {
			r = m
		}
	}

	fmt.Fprintf(writer, "%.15f\n", l)
}
