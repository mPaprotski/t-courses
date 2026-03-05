package main

import (
	"bufio"
	"os"
	"strconv"
)

type node struct {
	val    int
	minVal int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	stack := make([]node, 0, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		opType := scanner.Text()

		switch opType {
		case "1":
			scanner.Scan()
			x, _ := strconv.Atoi(scanner.Text())
			if len(stack) == 0 {
				stack = append(stack, node{val: x, minVal: x})
			} else {
				currentMin := stack[len(stack)-1].minVal
				if x < currentMin {
					stack = append(stack, node{val: x, minVal: x})
				} else {
					stack = append(stack, node{val: x, minVal: currentMin})
				}
			}
		case "2":
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			}
		case "3":
			if len(stack) > 0 {
				out.WriteString(strconv.Itoa(stack[len(stack)-1].minVal) + "\n")
			}
		}
	}
}
