` A generic allow us to define reusable functions and classes that work with 
multiple types instead of a single type
give bool take bool
give str take str
`;

function doThing(thing: number | string): number | string {
  return 0;
}
// This is a generic
const nums: Array<number> = [];

// const inputEl = document.querySelector("#name");
// console.log(inputEl);

function identity<Type>(item: Type): Type {}
function genericType<T>(item: T): T {}

identity<string>("4");
identity<number>(4);

function getRandomEl<T>(item: T[]): T {
  return item[item.length / 2];
  // return a random value from an array
  // random will be the index val
}

console.log(getRandomEl<number>([1, 2, 3, 4, 5]));
