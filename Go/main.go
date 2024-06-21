package main

// package main defines the entry point and requires function `main`

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	TypesExample()
}

// Types in GO
// Default initialization value for each value
// 0 		-> uint*, int*, float*, rune
// "" 		-> string
// false 	-> bool

// Define values with
// <varName> := value 				# type deduction
// var <varName> <type> = <val>		# explicit
// const <varName> <type> = <val>	# explicit + no change

func TypesExample() {
	intNumbers()
	floatNumbers()
	strings()
	booleans()
}

func intNumbers() {
	var shortNum int16
	var intNum int32
	var longNum int64
	fmt.Printf("%v, %v, %v\n", intNum, shortNum, longNum)

	// type deduction
	shortNum2 := int16(1)
	intNum2 := 123
	longNum2 := int64(1)
	fmt.Printf("%v, %v, %v\n", intNum2, shortNum2, longNum2)
}

func floatNumbers() {
	var floatNum float32
	var longFloatNum float64
	fmt.Printf("%v, %v\n", floatNum, longFloatNum)
}

func strings() {
	var myString string = "Hello" + " " + "World"
	fmt.Println(myString)

	// !! This will print the number of bytes, not the number of characters !!
	fmt.Println(len(myString))

	// Correct number of chars
	fmt.Println(utf8.RuneCountInString(myString))

	// Whereas char(c++) is an alias for 8-bit integer,
	// rune is an alias for int32 representing Unicode
	var myRune rune = 'a'
	fmt.Println(myRune)
}

func booleans() {
	var myBool bool
	println(myBool)
}
