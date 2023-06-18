import { faker } from "@faker-js/faker";

export default class Company {
  name: string;
  suffix: string[];
  catchPhrase: string;
  location: {
    lat: string;
    lng: string;
  };
  owner: string;
  mobile: string;
  constructor() {
    this.name = faker.company.name();
    this.suffix = faker.company.suffixes();
    this.catchPhrase = faker.company.catchPhrase();
    this.location = {
      lat: faker.address.latitude(),
      lng: faker.address.longitude(),
    };
    this.owner = faker.name.fullName();
    this.mobile = faker.phone.phoneNumber();
  }
  randomCompDetails() {
    return {
      name: this.name,
      suffix: this.suffix,
      catchPhrase: this.catchPhrase,
      location: {
        lat: this.location.lat,
        lng: this.location.lng,
      },
      owner: this.owner,
      mobile: this.mobile,
    };
  }
}
