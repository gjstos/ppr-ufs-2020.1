function f(x)
    return 10 * x - x^2
end

function simps(menor, maior, intervalo)
    sum = 0
    h = (maior - menor) / intervalo
    for i = 1:intervalo - 1
        sum += f(menor) + f(menor + h)
        menor += h
    end
    sum *= h / 2
    return sum
end

result = simps(0, 10, 5)
println("Valor: ", result)