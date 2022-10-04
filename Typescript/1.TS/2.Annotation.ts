const Name: string = "shahed";
const age: number = 30;
// const skills: Array = [1, 2, 3, 4];
const hasNothing: null = null;
const notDefined: undefined = undefined;
const date: Date = new Date();
const colors: string[] = ["r", "g", "b"];
const numbers: number[] = [1, 2, 3, 4, 5];
const truths: boolean[] = [true, false];

class Car {}
let car: Car;

//Object literal
let point: { x: number; y: string } = {
  x: 10,
  y: "Shahed",
};

// function
// tell ts about args type and what will be return type
const logNumber: (i: number) => void = (i: number) => {
  console.log(i);
};
