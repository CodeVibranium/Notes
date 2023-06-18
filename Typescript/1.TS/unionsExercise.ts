// **********************************************
// ******************* PART 1 *******************
// **********************************************
// Create a variable called highScore that can be a number OR a boolean
const highScore: number | boolean = false;
// **********************************************
// ******************* PART 2 *******************
// **********************************************
// create an array called stuff
// it can be an array of numbers OR an array of strings
// it cannot be an array of numbers and strings (mixed together)
const stuff: number[] | string[] = [1, 5];
const numstr: (number | string)[] = [1, "2", 3, 4, "5"];
// **********************************************
// ******************* PART 3 *******************
// **********************************************
// Create a literal type called SkillLevel
// There are 4 allowed values: "Beginner", "Intermediate", "Advanced", and "Expert"

// **********************************************
// ******************* PART 4 *******************
// **********************************************
// Create a type called SkiSchoolStudent
// name must be a string
// age must be a number
// sport must be "ski" or "snowboard"
// level must be a value from the SkillLevel type (from above)
type Point = {
  x: number;
  y: number;
};
type Loc = {
  lng: number;
  lat: number;
};
const geoLoc: (Point | Loc)[] = [{ x: 12, y: 23 }];
type SkillLevel = "Beginner" | "Intermediate" | "Advanced" | "Expert";
let zero: 0 = 0;
type SkiSchoolStudent = {
  name: string;
  age: number;
  sport: "ski" | "snowboard";
  SkillLevel: SkillLevel;
};
// **********************************************
// ******************* PART 5 *******************
// **********************************************
// Define a type to represent an RGB color
// r should be a number
// g should be a number
// b should be a number
type RGB = {
  r: number;
  g: number;
  b: number;
};
// Define a type to represent an HSL color
// h should be a number
// s should be a number
// l should be a number
type HSL = {
  h: number;
  s: number;
  l: number;
};

// Create an array called colors that can hold a mixture of RGB and HSL color types
const colorurs: (RGB | HSL)[] = [];
// **********************************************
// ******************* PART 6 *******************
// **********************************************
// Write a function called greet that accepts a single string OR an array of strings
// It should print "Hello, <name>" for that single person OR greet each person in the array with the same format
type name = string | string[];
function greet(name: name) {
  if (typeof name == "string") {
    console.log("Hello" + name);
  } else {
    name.map((each) => {
      console.log("Hello" + each);
    });
  }
}

const hsl: [number, number, number] = [0, 1, 2];
type HTTPresp = [number, string];
const goodRes = [200, "OK"];
goodRes.push("abc");

enum Responses {
  no,
  yes,
  maybe,
}
// named set of constants

enum move {
  UP = "W",
  LEFT = "A",
  RIGHT = "D",
  DOWN = "S",
}

enum LoanStatus {
  APPLIED,
  INREVIEW,
  PENDING,
  APPROVED,
}
function findApprovedLoans(status: LoanStatus): [] {
  return [];
}

findApprovedLoans(LoanStatus.APPLIED);
console.log(move.DOWN, move.LEFT, move);
