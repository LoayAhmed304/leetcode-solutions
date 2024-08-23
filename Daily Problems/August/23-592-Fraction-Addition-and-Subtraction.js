/**
 * @param {string} expression
 * @return {string}
 */

function gcd(a, b){
    while(b!==0){
        const temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

function adding(frac1, frac2){
    if(!frac1) return frac2;
    let [n1, d1] = frac1.split('/').map(Number);
    let [n2, d2] = frac2.split('/').map(Number);

    let resN = n1 * d2 + n2 * d1;
    let resD = d1*d2;

    if(resN == resD) return '1/1';
    if(resN == -resD)return '-1/1';


    const division = gcd(Math.abs(resN), Math.abs(resD));

   
    
    return `${resN/division}/${resD/division}`;
 }
var fractionAddition = function(expression) {
    let fractions;
    if(expression[0] === '-'){
        fractions = expression.slice(1).split(/[+-]+/);
        fractions[0] = '-' + fractions[0];
    }
    else fractions = expression.split(/[+-]+/);

    let j=0;
    let res='';
    for(let i=0; i<expression.length;){
        if(expression[i] === '-' && i !== 0){
            fractions[j] = '-' + fractions[j];
        }
        res = adding(res, fractions[j]);
        i += fractions[j].length;

        while(i< expression.length && expression[i] !== '+' && expression[i] !== '-')
            i++;
        j++;
    }
    
    return res;
};
