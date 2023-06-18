`
public

private

protected


`;

class Vehicle {
  color: string;
  // constructor function is executed as soon as instance is created
  constructor(color: string = "white") {
    this.color = color;
  }
  drive() {
    console.log("Vroom, Vroom");
  }
  clean() {
    console.log("Cleaning the car");
  }
  private configure() {
    console.log("Confuring the car");
    console.log("Done dona done");
  }
  // Private methods are only accessible within the class.
  protected greet(name: string) {
    console.log(`Welcome ${name}, starting up!`);
    this.drive();
  }
  // Protected methods are accessible within the class as well as child classes.
}
const vec1 = new Vehicle();
// vec1.greet();
class Car extends Vehicle {
  constructor(public doors: number, color: string) {
    super();
  }
  start(name: string): void {
    this.greet(name);
  }
}
const honda = new Car(5, "black");
// honda.configure();
honda.start("Mustang");
