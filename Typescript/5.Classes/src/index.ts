console.log("Hello world !");
// classes allow to describe patterns which acts as blueprints
// class Player {
// 	score = 0;
// 	matches = 10;
// 	#score = 10; // private field
// 	static des = "Player in our game";
// 	// static thing will exist on the class not on the instances
// 	// can be accessed with Class name only
// 	constructor(first, last) {
// 	  // Automatically called for new instance of the class
// 	  this.first = first;
// 	  this.last = last;
// 	  this.score = 0;
// 	}
// 	taunt() {
// 	  console.log("Booya");
// 	}
// 	get fullname() {
// 	  console.log("THUS", this);
// 	  console.log(`${this.first}.${this.last}`);
// 	}
// 	get score() {
// 	  return this.#score;
// 	}
// 	set firstName(first) {
// 	  console.log("First", first);
// 	  this.first = first;
// 	}
// 	set lastName(last) {
// 	  this.last = last;
// 	}
// 	#secret() {
// 	  console.log("Player secret code");
// 	}
// 	static randomPlayer() {
// 	  return new Player("Chicha", "ki dukaan");
// 	}
//   }
//   const p1 = new Player("MD", "Shahed");
//   // console.log(p1, p1.taunt());
//   p1.fullname;
//   console.log("SCORE===>", p1.score);
//   p1.firstName = "Mohammed";
//   p1.lastName = "Shahed";
//   p1.fullname;
//   const p2 = Player.randomPlayer();

//   class AdminPlayer extends Player {
// 	#isAdmin = true;
// 	//   super()
// 	constructor(first, last, powers) {
// 	  super(first, last, powers); // refernces the constructor of the parent class a.k.a derived class
// 	  this.powers = powers;
// 	}
//   }
//   const admin1 = new AdminPlayer("Shahed", "Ali", ["C", "R", "U", "D", "S"]);

class Player {
  readonly first: string;
  readonly last: string;
  private _score: number = 0;
  protected numOfLives: number = 3;
  // private fields are only accessible within the class
  constructor(first: string, last: string) {
    this.first = first;
    this.last = last;
  }
  get fullName(): string {
    return `${this.first}.${this.last}`;
  }
  get score(): number {
    return this._score;
  }
  set score(score: number) {
    if (score < 0) {
      throw new Error("Score cannot be <0");
    }
    this._score = score;
  }
}
class AdminPlayer {
  constructor(public first: string, public last: string) {}
}

class SuperPlayer extends Player {
  constructor(public first: string, public last: string) {
    super(first, last);
    this.numOfLives = 5;
  }
}

interface Colorful {
  color: string;
}

class Bike implements Colorful {
  constructor(public color: string) {}
}

abstract class Employee {
  constructor(public first: string, public last: string) {}
  abstract get pay(): number;
}
// these classes arent allowed to created its own instances
// these class are only meant be inherited and must have the nescessary methods

const inputEl = document.querySelector<HTMLInputElement>("#name")!;
// console.dir(inputEl);
inputEl.value = "Hello Shahed Ali !";

const btnEl = document.querySelector<HTMLButtonElement>(".btn")!;
btnEl.innerHTML = "Hello";
