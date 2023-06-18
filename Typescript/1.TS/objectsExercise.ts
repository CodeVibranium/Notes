// Write the Movie type alias to make the following two variables properly typed
// Make sure that "originalTitle" is optional and "title" is readonly
type Movie = {
  readonly title: string;
  originalTitle?: string;
  director: string;
  releaseYear: number;
  boxOffice: {
    budget: number;
    grossUS: number;
    grossWorldwide: number;
  };
};

const dune: Movie = {
  title: "Dune",
  originalTitle: "Dune Part One",
  director: "Denis Villeneuve",
  releaseYear: 2021,
  boxOffice: {
    budget: 165000000,
    grossUS: 108327830,
    grossWorldwide: 400671789,
  },
};

const cats: Movie = {
  title: "Cats",
  director: "Tom Hooper",
  releaseYear: 2019,
  boxOffice: {
    budget: 95000000,
    grossUS: 27166770,
    grossWorldwide: 73833348,
  },
};
function getProfit(movie: Movie): number {
  return movie.boxOffice.grossWorldwide - movie.boxOffice.budget;
}
// Write a function called getProfit that accepts a single Movie object
// It should return the movie's worldwide gross minus its budget

// For example...
console.log(getProfit(cats));
interface Persona {
  readonly id: number;
  name: string;
  address?: string;
  fullname(): string;
  greet: () => string;
}

interface Usero extends Persona {
  parents: { mother: string; father: string };
}
interface Bikes extends Usero {
  name: string;
  mileage: number;
  fuel: number;
  price: number;
}

interface Cars {
  name: string;
  engine: string;
}

interface MyGarage extends Cars, Bikes {}
const usero: Usero = {};
