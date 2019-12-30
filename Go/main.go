package main

import (
	"fmt"
	"time"
)

const path string = "uploads"

// func getName(a, b) {
// 	fmt.Println(a, b)
// }

func main() {

	for j := 0; j < 10; j++ {
		if j%2 == 0 {
			fmt.Println(j)
		} else {
			fmt.Println("Fuck...")
		}
	}

	i := 2
	t := time.Now()

	switch i {
	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	case 3:
		fmt.Println("three")
	case t.Minute():
		fmt.Println("It's before noon")
	default:
		fmt.Println("It's after noon")
	}

	whatAmI := func(i interface{}) {
		switch t := i.(type) {
		case bool:
			fmt.Println("I'm a bool")
		case int:
			fmt.Println("I'm an int")
		default:
			fmt.Printf("Don't know type %T\n", t)
		}
	}
	whatAmI(true)
	whatAmI(1)
	whatAmI("hey")
}
