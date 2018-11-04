let Total = 2

let caso0 = [1, 1]

let caso1 = [0, 1]
let caso2 = [1, 0]
let caso3 = [0, 0]
let caso4 = [0, 0]

function heuristica(caso) {
    let total = caso[0] + caso[1]

    let p1 = caso[0] / total
    let p2 = caso[1] / total

    return (!isNaN((-p1 * Math.log2(p1)) - (p2 * Math.log2(p2))) ? (-p1 * Math.log2(p1)) - (p2 * Math.log2(p2)) : 0)
}

console.log(heuristica(caso0))
console.log(heuristica(caso1))
console.log(heuristica(caso2))
console.log(heuristica(caso3))
console.log(heuristica(caso4))

let ganho = heuristica(caso0) - (((caso1[0] + caso1[1]) / Total) * heuristica(caso1) + ((caso2[0] + caso2[1]) / Total) * heuristica(caso2) +
    ((caso3[0] + caso3[1]) / Total) * heuristica(caso3) + ((caso4[0] + caso4[1]) / Total) * heuristica(caso4))

console.log('GANHO: ' + ganho)