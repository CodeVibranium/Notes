`
tsc --init
do customizations
run tsc to  complie and convert ts to js code
run tsc -w to watch changes made in src dir

`;

console.log("Hi there!");
console.log("ABCDE");

class Sorter {
  public collection: number[] | string = [];
  constructor(collection: number[] | string) {
    this.collection = collection;
  }
  sort(): number[] | string {
    let collection = this.collection;
    // if (typeof collection === "string") {
    //   collection = collection.split("");
    // }
    if (collection instanceof Array) {
      for (let i = 0; i < collection.length; i++) {
        for (let j = 0; j < collection.length - i; j++) {
          if (collection[j] > collection[j + 1]) {
            let temp = collection[j];
            collection[j] = collection[j + 1];
            collection[j + 1] = temp;
          }
        }
      }
      return collection;
    }
    if (typeof collection === "string") {
      collection = collection.split("");
      for (let i = 0; i < collection.length; i++) {
        for (let j = 0; j < collection.length - i; j++) {
          if (collection[j] > collection[j + 1]) {
            let temp = collection[j];
            collection[j] = collection[j + 1];
            collection[j + 1] = temp;
          }
        }
      }
      return collection.join("");
    }
  }
}
function bubbleSort(...numbers: number[]): number[] {
  for (let i = 0; i < numbers.length; i++) {
    for (let j = 0; j < numbers.length - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        let temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }
  return numbers;
}

const myArray = new Sorter([1, 2, -4, 5, -5, 0, 3, 6, 7, 17, 8]);
const myArray1 = new Sorter("aqbpefwc");
const sorted1 = myArray1.sort();

const sorted = myArray.sort();
console.log("SORTED", sorted, "S");
console.log("SORTED", sorted1, "S");

// console.log(bubbleSort(1, 2, -4, 5, -5, 0, 3, 6, 7, 2, 7, 17, 8));
