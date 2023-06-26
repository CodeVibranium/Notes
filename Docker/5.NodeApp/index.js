const express = require("express");
const app = express();

app.listen(8080, () => {
  console.log("server started in port 300");
});

app.get("/", (req, res, next) => {
  res.send("Response from Local backend web page 8080");
});

app.get("/greet/:user", (req, res, next) => {
  res.send("Welcome to Docker APP " + req.params.user);
});
