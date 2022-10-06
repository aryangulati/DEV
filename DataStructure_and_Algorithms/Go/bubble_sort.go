"""
Bubble Sort is the simplest sorting algorithm that works by 
repeatedly swapping the adjacent elements if they are in the wrong order.
This algorithm is not suitable for large data sets as its average and 
worst-case time complexity is quite high.
"""
package main

import "fmt"

func swap(a *int, b *int) {
	*a, *b = *b, *a
}
func bubblesort(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		var swappped bool
		for j := i + 1; j < len(arr); j++ {
			if arr[i] > arr[j] {
				swap(&arr[i], &arr[j])
				swappped = true
			}
		}
		if !swappped {
			break
		}
	}
	return arr
}
func main() {
	arr := []int{4, 3, 7, 1, 5}
	fmt.Println(bubblesort(arr))
}