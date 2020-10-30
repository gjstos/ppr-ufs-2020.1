package main

import (
	"fmt"
	"math"
)

func f(x float64) float64 {
	return math.Sqrt(1 - x*x)
}

func simps(menor, maior, intervalo float64) float64 {
	var sum1, sum2 float64

	h := (maior - menor) / intervalo
	y0 := f(menor + 0*h)
	yn := f(menor + intervalo*h)

	for i := 1; i < int(intervalo); i++ {
		if i%2 == 0 {
			sum1 += f(menor + float64(i)*h)
		} else {
			sum2 += f(menor + float64(i)*h)
		}
	}
	sum := (h / 3) * (y0 + yn + 2*sum1 + 4*sum2)

	return sum
}

func main() {
	Pi := 4.0 * simps(0, 1, 10)

	fmt.Printf("Valor: %f", Pi)
	fmt.Printf("\nPrecisão: %f", Pi-math.Pi)
}
