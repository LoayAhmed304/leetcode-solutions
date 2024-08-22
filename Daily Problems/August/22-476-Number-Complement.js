/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    const size = Math.floor(Math.log2(num)) + 1;
    const ones = (1 << size) -1;

    return ones ^ num;
};
