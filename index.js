function Employee(name, age, designation, salary) {
  this.name = name;
  this.age = age;
  this.designation = designation;
  this.salary = salary;
}

const emp1 = new Employee("Shahed", 22, "Web developer", 100000);
const emp2 = Employee("Shahed Ali", 22, "Web developer", 100000);
console.log(emp2);
