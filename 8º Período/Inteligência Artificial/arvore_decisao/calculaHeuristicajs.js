let nomeVariavel = 'tempoEspera'

let caso0 = ['bar', 1, 1]

let caso1 = ['{10-30}', 1, 0]
let caso2 = ['{30-60}', 0, 1]
let caso3 = ['', 0, 0]
let caso4 = ['', 0, 0]

function heuristica(caso) {
    let total = caso[1] + caso[2]

    let p1 = caso[1] / total
    let p2 = caso[2] / total

    return (!isNaN((-p1 * Math.log2(p1)) - (p2 * Math.log2(p2))) ? (-p1 * Math.log2(p1)) - (p2 * Math.log2(p2)) : 0).toFixed(3)
}

function ganho() {
    let Total = caso0[1] + caso0[2]

    return (heuristica(caso0) - (((caso1[1] + caso1[2]) / Total) * heuristica(caso1) + ((caso2[1] + caso2[2]) / Total) * heuristica(caso2) +
        ((caso3[1] + caso3[2]) / Total) * heuristica(caso3) + ((caso4[1] + caso4[2]) / Total) * heuristica(caso4))).toFixed(3)
}

function texto() {
    let nv = nomeVariavel
    let t = caso0[1] + caso0[2]

    let a0 = caso1[0]
    let a1 = caso1[1]
    let a2 = caso1[2]
    let at = caso1[1] + caso1[2]

    let b0 = caso2[0]
    let b1 = caso2[1]
    let b2 = caso2[2]
    let bt = caso2[1] + caso2[2]

    let c0 = caso3[0]
    let c1 = caso3[1]
    let c2 = caso3[2]
    let ct = caso3[1] + caso3[2]

    let d0 = caso4[0]
    let d1 = caso4[1]
    let d2 = caso4[2]
    let dt = caso4[1] + caso4[2]

    let texto = '\n\n'

    if (a0 != '') texto += `\\par $S_{${nv}^${a0}} = [${a1},${a2}]$`
    if (b0 != '') texto += ` \\qquad $S_{${nv}^${b0}} = [${b1},${b2}]$`
    if (c0 != '') texto += `\\par $S_{${nv}^${c0}} = [${c1},${c2}]$`
    if (d0 != '') texto += ` \\qquad $S_{${nv}^${d0}} = [${d1},${d2}]$`

    if (a0 != '') texto += `\n\\par $H(S_{${nv}^${a0}}) = -\\frac{${a1}}{${at}} \\log_2 \\frac{${a1}}{${at}}- \\frac{${a2}}{${at}} \\log_2 \\frac{${a2}}{${at}} = ${heuristica(caso1)}$ `
    if (b0 != '') texto += `\n\\par $H(S_{${nv}^${b0}}) = -\\frac{${b1}}{${bt}} \\log_2 \\frac{${b1}}{${bt}}- \\frac{${b2}}{${bt}} \\log_2 \\frac{${b2}}{${bt}} = ${heuristica(caso2)}$ `
    if (c0 != '') texto += `\n\\par $H(S_{${nv}^${c0}}) = -\\frac{${c1}}{${ct}} \\log_2 \\frac{${c1}}{${ct}}- \\frac{${c2}}{${ct}} \\log_2 \\frac{${c2}}{${ct}} = ${heuristica(caso3)}$ `
    if (d0 != '') texto += `\n\\par $H(S_{${nv}^${d0}}) = -\\frac{${d1}}{${dt}} \\log_2 \\frac{${d1}}{${dt}}- \\frac{${d2}}{${dt}} \\log_2 \\frac{${d2}}{${dt}} = ${heuristica(caso4)}$ `

    texto += `\n\\par $Ganho(S, S_{${nv}}) = ${heuristica(caso0)}`


    if (a0 != '') texto += `-\\frac{${at}}{${t}} * ${heuristica(caso1)}`
    if (b0 != '') texto += `-\\frac{${bt}}{${t}} * ${heuristica(caso2)}`
    if (c0 != '') texto += `-\\frac{${ct}}{${t}} * ${heuristica(caso3)}`
    if (d0 != '') texto += `-\\frac{${dt}}{${t}} * ${heuristica(caso4)}`

    texto += ` = ${ganho()}`


    return texto + '$\n\n'
}



let heuristica_total = heuristica(caso0)
let heuristica_1 = heuristica(caso1)
let heuristica_2 = heuristica(caso1)
let heuristica_3 = heuristica(caso1)
let heuristica_4 = heuristica(caso1)

console.log(texto())