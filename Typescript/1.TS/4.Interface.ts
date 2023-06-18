`
# Interface

- Creates a new type describing the properties of the object.

`;

interface oldCivic {
  name: string;
  year: number;
  horsepower: number;
  weight: number;
  owner: string;
  summary(): string;
}

interface Reportable {
  summary(): string;
}
function getCatDetails(item: Reportable) {
  //   console.log(item.horsepower);
  //   console.log(item.name);
  //   console.log(item.weight);
  //   console.log(item.year);
  console.log(item.summary());
}
const hellCar: oldCivic = {
  name: "HellCat",
  year: 2023,
  horsepower: 450,
  weight: 3450,
  owner: "Shahed",
  summary() {
    return `${this.name} ${this.year} ${this.horsepower}`;
  },
};
getCatDetails({
  name: "HellCat",
  year: 2023,
  horsepower: 450,
  weight: 3450,
  owner: "Shahed",
  summary() {
    return `${this.name} ${this.year} ${this.horsepower}`;
  },
} as Reportable);

getCatDetails(hellCar);
const drink30 = {
  color: "brown",
  carbonated: true,
  sugar: 40,
  summary(): string {
    return `My drink has ${this.sugar} grams of sugar`;
  },
};
getCatDetails(drink30);
getCatDetails({
  color: "brown",
  carbonated: true,
  sugar: 40,
  summary(): string {
    return `My drink has ${this.sugar} grams of sugar`;
  },
} as Reportable);

getCatDetails({
  name: "HellCat",
  year: 2023,
  horsepower: 450,
  weight: 3450,
  owner: "Shahed",
  summary() {
    return `${this.name} ${this.year} ${this.horsepower}`;
  },
} as Reportable);
