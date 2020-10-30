function f(x)::Float64
    return sqrt(1 - x^2)
end

function simps(menor, maior, intervalo)
    sum1 = 0
    sum2 = 0

    h = (maior - menor) / intervalo
    y0 = f(menor + 0*h)
	yn = f(menor + intervalo*h)
    for i = 1:intervalo - 1
        if i%2 ==0
            sum1 +=f(menor + i*h)
        else
            sum2 += f(menor + i*h)
        end
    end

    sum = (h / 3) * (y0 + yn + 2*sum1 + 4*sum2)

    return sum
end

Pi = 4.0 * simps(0.0, 1.0, 10.0)

println("Valor: ", Pi)
println("Precisão: ", Pi-pi)