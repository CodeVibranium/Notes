function greetUsers(
  name: string[] | string | null | { name: string } | Date
): void {
  // this is called a truthy gaurd
  if (name) {
    // this is called a type gaurd
    if (typeof name === "string") {
      // this is called equality gaurd
      if (name === "Shahed") {
        console.log(`Hello BOSS`);
      } else console.log(`Hello ${name}`);
    } else if (name instanceof Array || Array.isArray(name))
      name.map((eachName) => {
        console.log(`Hello ${eachName}`);
      });
    // using the IN operator gaurd
    else if ("name" in name) {
      console.log(`Hello ${name}`);
    } else if (name instanceof Date) {
      console.log(`Hello ${name}`);
    }
  }
}
`
1. TYPE gaurd:checking the datatype in a conditional is called a type gaurd
2. Truthy Gaurd: checking the truthiness of the value in a conditional
3. Equality gaurd: checking for equality in a conditional
4. In Operator: 
5. instanceOf:
6. Type predicates: ------>
7. Discriminated Unions: Simply narrow type
	- nothing but add a key onto each 
	object in array with a key called "key":"interfaceName"
`;
