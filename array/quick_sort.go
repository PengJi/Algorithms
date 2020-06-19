/**
 * 快速排序
 */

package main

import "fmt"

func paritition(arr []int, low, high int) int {
	pivot := arr[low]
	for low < high {
		for low < high && pivot <= arr[high] {
			high--
		}
		arr[low] = arr[high]

		for low < high && pivot >= arr[low] {
			low++
		}
		arr[high] = arr[low]
	}
	arr[low] = pivot
	return low
}

func quickSort(arr []int, low, high int) {
	if low < high {
		pivot := paritition(arr, low, high)
		quickSort(arr, low, pivot-1)
		quickSort(arr, pivot+1, high)
	}
}

func main(){
	arr := []int{0, 5, 1, 9, 6, 8, 19, 11, 3, 7}
	fmt.Printf("original arr: %+v\n", arr)
	quickSort(arr, 0, 9)
	fmt.Printf("sorted arr: %+v\n", arr)
}
