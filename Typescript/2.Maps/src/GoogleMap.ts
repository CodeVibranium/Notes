// import User from "./User";
// import Company from "./Company";
`
1. contentString which is HTML

`;
interface Mapablle {
  location: {
    lat: string;
    lng: string;
  };
  title?: string;
}
export default class GoogleMap {
  private map = google.maps.Map;
  private infoWindow;
  private marker;
  constructor(divId: string, lat: number = 0, lng: number = 0) {
    this.map = new google.maps.Map(document.getElementById(divId), {
      zoom: 1,
      center: {
        lat,
        lng,
      },
    });
  }

  addMark(mapabble: Mapablle) {
    this.marker = new google.maps.Marker({
      map: this.map,
      position: {
        lat: parseInt(mapabble.location.lat),
        lng: parseInt(mapabble.location.lng),
      },
      title: "Hello",
    });
  }
  addMarkInfo(content: string) {
    this.infoWindow = new google.maps.InfoWindow({
      content,
    });
    console.log(this.marker);

    this.marker.addListener("click", () => {
      this.infoWindow.open(this.map, this.marker);
    });
  }
}
