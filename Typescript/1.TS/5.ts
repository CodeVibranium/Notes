interface Reportable {
  summary(): string;
}

const oldCivic1 = {
  name: "civic",
  year: new Date(),
  broken: true,
  summary(): string {
    return `Name: ${this.name}`;
  },
};

const drink2 = {
  color: "brown",
  carbonated: true,
  sugar: 40,
  summary(): string {
    return `My drink has ${this.sugar} grams of sugar`;
  },
};

const printSummary2 = (item: Reportable): void => {
  console.log(item.summary());
};

printSummary2(oldCivic);
printSummary(drink2);
