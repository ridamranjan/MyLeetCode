function pow2(n){
  return n > 0 && parseInt(n.toString(2), 10) % (10 ** (n.toString(2).length - 1)) === 0;
}

let testcases = [-16, 0, 1, 2, 6, 16, 536870912];

testcases.forEach(i => {
  console.log("%d = %s", i, pow2(i));
});