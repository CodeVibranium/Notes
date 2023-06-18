`
Blueprint to create an object with some field(values)
and methods (functions) tp represent a thing
`;

class Vehicle1 {
  drive(): void {
    console.log("Starting the car  \n");
    console.log("Broom, Broom....  \n");
  }
  honk(): void {
    console.log("Beep beep beep beep beep beep beep beep");
  }
}

`
When you extend a class in TypeScript,
any methods or properties that are inherited from the parent class
must have the same signature in the child class as they do in the parent class.
This is known as method signature compatibility.
`;

class Car1 extends Vehicle {
  drive(): void {
    console.log("\n Starting the car  \n");
    console.log("Vroom, Vroom....  \n");
  }
}

const mercedesGLA = new Vehicle1();
mercedesGLA.drive();
mercedesGLA.honk();
const mustang = new Car1();
mustang.drive();
