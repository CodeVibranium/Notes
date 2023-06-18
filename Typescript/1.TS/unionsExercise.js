// **********************************************
// ******************* PART 1 *******************
// **********************************************
// Create a variable called highScore that can be a number OR a boolean
var highScore = false;
// **********************************************
// ******************* PART 2 *******************
// **********************************************
// create an array called stuff
// it can be an array of numbers OR an array of strings
// it cannot be an array of numbers and strings (mixed together)
var stuff = [1, 5];
var numstr = [1, "2", 3, 4, "5"];
var geoLoc = [{ x: 12, y: 23 }];
var zero = 0;
// Create an array called colors that can hold a mixture of RGB and HSL color types
var colorurs = [];
function greet(name) {
  if (typeof name == "string") {
    console.log("Hello" + name);
  } else {
    name.map(function (each) {
      console.log("Hello" + each);
    });
  }
}
var hsl = [0, 1, 2];
var goodRes = [200, "OK"];
goodRes.push("abc");
var Responses;
(function (Responses) {
  Responses[(Responses["no"] = 0)] = "no";
  Responses[(Responses["yes"] = 1)] = "yes";
  Responses[(Responses["maybe"] = 2)] = "maybe";
})(Responses || (Responses = {}));
// named set of constants
var move;
(function (move) {
  move["UP"] = "W";
  move["LEFT"] = "A";
  move["RIGHT"] = "D";
  move["DOWN"] = "S";
})(move || (move = {}));
var LoanStatus;
(function (LoanStatus) {
  LoanStatus[(LoanStatus["APPLIED"] = 0)] = "APPLIED";
  LoanStatus[(LoanStatus["INREVIEW"] = 1)] = "INREVIEW";
  LoanStatus[(LoanStatus["PENDING"] = 2)] = "PENDING";
  LoanStatus[(LoanStatus["APPROVED"] = 3)] = "APPROVED";
})(LoanStatus || (LoanStatus = {}));
function findApprovedLoans(status) {
  return [];
}
findApprovedLoans(LoanStatus.APPLIED);
console.log(move.DOWN, move.LEFT, move);
