import { faker } from "@faker-js/faker";
export default class User {
  name: string;
  location: {
    lat: string;
    lng: string;
  };
  constructor() {
    this.name = faker.name.fullName();
    this.location = {
      lat: faker.address.latitude(),
      lng: faker.address.longitude(),
    };
  }
  randomUserdetails(): { name: string; lat: string; lng: string } {
    return {
      name: this.name,
      lat: this.location.lat,
      lng: this.location.lng,
    };
  }
}
google;
