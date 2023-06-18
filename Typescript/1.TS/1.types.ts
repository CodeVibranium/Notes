`
tsc filename complies ts and creates anew js file.
ts-node complies ts file and runs the js file
`;

const userName: string = "Mohammed Shahed Ali";
const userAge: number = 22;
const userVerified: boolean = true;
const userEmail: string | null = "shahed@beyondscale.com";
const nullValue: null = null;
const undefinedValue: undefined = undefined;
let isUserSingle: undefined | boolean;

interface User {
  name: string | null;
  age: number;
  email: string;
  phoneNumber: string;
  dob?: Date;
}
isUserSingle = undefined;
// Interface is a way to define an object
const userData: User = {
  name: "Shahed Ali",
  age: 22,
  email: "shahed@beyondscale.com",
  phoneNumber: "9515768704",
};
const Themecolors: string[] = ["red", "green", "yellow", "blue"];
const scores: number[] = [1, 2, 3, 4, 5];
const results: boolean[] = [true, true, false];

function sumUp(a: number, b: number): number {
  return a + b;
}

function greetUser(name: string): void {
  console.log(`Hello ${name}`);
  ``;
}
console.log(sumUp(5, 0));
greetUser("Shahed Ali");

class Vehicle {
  constructor(name: string) {
    this.name = name;
  }
}
const Bus = new Vehicle("Mercedes");
const hello: () => void = () => {};
const getStatus: (id: string) => void = (id: string) => {};

interface LoanDetails {
  personalDetails: { full_name: string };
  residenceDetails: {};
  inflows: {};
  outflows?: {};
}

const personalLoanData: LoanDetails[] = [
  {
    personalDetails: {},
    residenceDetails: {},
    inflows: {},
  },
];

interface userData {
  id: string;
  full_name: string;
  password: string;
  email: string;
  mobile: string;
}

function throwError(message: string): never {
  throw new Error(message);
}
interface findUser {
  is_user_present: boolean;
  userData?: {
    id: string;
    access_token: string;
    referesh_token: string;
  };
}
function findUser(userData: userData): findUser {
  return { is_user_present: false };
}

const newArray: (undefined | null | boolean | string | number)[] = [
  1,
  "0",
  null,
  true,
  undefined,
];
const data: number[] = newArray.map(
  (each: undefined | null | boolean | string | number): number => {
    return Number(each);
  }
);
const array2: Array<number | boolean> = [];
const matrix: Array<Array<number | boolean | null>> = [
  [1, 2, 3],
  [4, 5, null],
];

findUser({
  id: "a",
  full_name: "Shahed",
  password: "abc",
  mobile: "88",
  email: "ac",
});

`
TUPLE
1. Tuple is fixed in length
2. Cannot add || remove elements
3. It should have differnt datatypes
`;
const pepsico = {
  color: "brown",
  carbonated: true,
  sugar: 40,
};
const drink: [string, boolean, number] = ["brown", true, 40];
const drink2: [string, string] = ["1", "2"];
const drink3: Array<string> = ["1", "2"];

// Annotations -> We tell ts what is the  data type
// Inference   -> Typescript assumes data type
