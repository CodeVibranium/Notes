console.log(this, "GLOABL");

function hello(name) {
  console.log("\n", name, this, "FUNC SCOPED");
}

const data = {
  name: "Shahed",
};
function scoop() {
  console.log("\n", "--> KING");
}

hello.call(scoop, "SHAHED");
