`
type
interface
Both type and interface are used to define the shape of the object, what are the 
differences then?
1. interface can be extended while types cannot.
2. interface creates a new shape while type creates a new name for an existing shape
3. interfaces are used to represnt complex objects
`;

`
readonly
`;

`
Intersection types
- combine multiple types using " & "
`;

type User = {
  readonly id: number;
  username: string;
};

const user: User = {
  id: 1234,
  username: "ali",
};

type Circle = {
  radius: number;
};
type Color = {
  color: string;
};

type ColorfulCircle = Circle & Color;

const wheel: ColorfulCircle = {
  radius: 10,
  color: "black",
};

type Wheel = ColorfulCircle & {
  width: number;
  innerRadius: number;
  outerRadius: number;
};

const i20Wheel: Wheel = {
  radius: 30,
  color: "black",
  width: 10,
  innerRadius: 20,
  outerRadius: 30,
};
