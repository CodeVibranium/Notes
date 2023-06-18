function giveValue(n) {
  return function takeValue(m) {
    return n + m;
  };
}

const take = giveValue(5);
console.log(take(1));
console.log(take(2));
console.log(take(3));
console.log(take(4));
console.log(take(5));
console.log(take(6));
