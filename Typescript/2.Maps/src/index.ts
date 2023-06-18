import Company from "./Company";
import User from "./User";
import GoogleMap from "./GoogleMap";

const ali = new User();
const bys = new Company();
console.log(
  "%c Shahed Ali",
  "color: red; font-size: 120px; font-weight: bold;text-align: center, margin-left:60px; margin-right:120px"
);
const mapA = new GoogleMap("map");
mapA.addMark(ali);
mapA.addMarkInfo(
  `<h1>Hello world, iam  ALI at lat ${ali.location.lat} lng ${ali.location.lng}</h1>`
);
mapA.addMark(bys);
mapA.addMarkInfo(
  `<h1>Hello world, iam  BYS at lat ${bys.location.lat} lng ${bys.location.lng}</h1>`
);

// new GoogleMap("map2", parseInt(ali.location.lat), parseInt(ali.location.lng));
