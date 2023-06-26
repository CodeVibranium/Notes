const express = require("express");
const redis = require("redis");
const process = require("process");
const port = 3001;
const app = express();
const client = redis.createClient({
  host: "redis-server",
  port: 6379,
});
client.on("connect", () => {
  console.log("REDIS CONNECTED");
});
// actually here the redis || express dosent know about `redis-server` host
// it will be assuming that this is a valid connection string
// and when redis tells express to fetch me this connection string
// docker sees the connection req and then docker interprets that `redis-server` is
// nothing but redis image so docker connects our node app with that redis container.

app.listen(port, async () => {
  console.log("Server started on port " + port);
  console.log(client);
});

app.get("/", (req, res) => {
  process.exit(0);
  res.status(200).json(client);
});

app.get("/visits", async (req, res) => {
  client.get("visits", (err, visits) => {
    if (err) {
      res.status(500).send(err);
    }
    res.send(`
  <center><h1>Welcome to visits APP</h1></center>
  <h2>This page was visted ${visits} times</h2>
  `);
    client.set("visits", parseInt(visits) + 1);
  });
});
