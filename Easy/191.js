function hammingweight(n){
  let result = 0;
  n = (n >>> 0).toString(2);
  for( let c of n){
    result += parseInt(c, 10);
  }
  return result;
}

let testcases = [11, 128, 2147483645];

testcases.forEach(n => {
  console.log('Test : ' + n);
  console.log("\t" + 'Result: ' + hammingweight(n));
})