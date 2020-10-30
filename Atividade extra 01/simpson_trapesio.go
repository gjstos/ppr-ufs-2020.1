package main

import "fmt"

func f(x float64) float64 {
	return 10*x - x*x
}

func integral(menor, maior, intervalo float64) float64 {
	var sum float64

	h := (maior - menor) / intervalo

	for i := 1; i < int(intervalo); i++ {
		sum += f(menor) + f(menor+h)
		menor += h
	}

	sum *= h / 2

	return sum
}

func main() {
	result := integral(0, 10, 5)

	fmt.Printf("Valor: %f", result)
}
