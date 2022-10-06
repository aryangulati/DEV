// Merge sort is similar to the quick sort algorithm as works on the concept of divide and conquer. 
// It is one of the most popular and efficient sorting algorithm. It is the best example for divide 
// and conquer category of algorithms.

// It divides the given list in the two halves, calls itself for the two halves and then merges the two sorted halves.

package main

import "fmt"

func Merge(left_values, right_values []int) []int {
	final_array := []int{}
	i := 0
	j := 0
	for i < len(left_values) && j < len(right_values) {
		if left_values[i] < right_values[j] {
			final_array = append(final_array, left_values[i])
			i += 1
		} else {
			final_array = append(final_array, right_values[j])
			j += 1
		}
	}
	for ; i < len(left_values); i++ {
		final_array = append(final_array, left_values[i])
	}
	for ; j < len(right_values); j++ {
		final_array = append(final_array, right_values[j])
	}
	return final_array
}
func MergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}
	middle := len(arr) / 2
	left_values := MergeSort(arr[:middle])
	right_values := MergeSort(arr[middle:])
	return Merge(left_values, right_values)
}

func main() {
	arr := []int{1, 3, 2, 5, 1, 1, 8, 0}
	fmt.Println(MergeSort(arr)) //Works perfect

}