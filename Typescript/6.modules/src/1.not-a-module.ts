// function add(x: number, y: number, z: number): number {
//   return x + y + z;
// }

export function add(x: number, y: number): number {
  return x + y;
}

function script<T>(data: T[]): T {
  return data[0];
}
