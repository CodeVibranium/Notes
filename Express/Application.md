# Application

## app.locals

It is an object that has properties that are local variables within the application

- These locals are also available in templates.
- The value of app.locals will persist throught the life of the application

## app.mounthpath

- need to know about it.

## app.all()

- This will be invoked for every http method which request a particular route (/secret)

```js
app.all("/secret", function (req, res, next) {
  console.log("Accessing the secret section ...");
  next(); // pass control to the next handler
});
```

## Enabled, enable, Disabled, Disable

```js
const express = require("express");
const app = express();

app.enable("SHAHED");
console.log(app.get("SHAHED"), "ENABLE");

app.disable("SHAHED");
console.log(app.get("SHAHED"), "DISABLE");

app.enable("K"); // returns true
app.enabled("K");
console.log(app.enabled("K"), "Checking ENABLED");
app.disable("K");
console.log(app.enabled("K"), "Checking ENABLED");

// what enabled does is it check if the kety exists and return `undefined` if key aint present
// if value exists return boolean

app.enable("K");
console.log(app.get("K"), "ENABLE");
app.disabled("K");
console.log(app.disabled("K"), "Checking DISABLED");
app.disable("K");
console.log(app.disabled("K"), "Checking DISABLED");
```

## SET

```js
app.set("SHAHED", "NAME");
app.get("SHAHED"); //return NAME
```

## GET

Routes HTTP GET request to the specified paths

## POST

Routes HTTP POST requests to the specified path with the specified callback functions

## PUT

Routes HTTP PUT requests to the specified path with the specified callback functions.

## app.all("\*")

## app.param()

This method will be triggered for each paramter decalred in it.
For ex:

```js
app.param([id, user], (req, res));
```

Now for any url having `id` , `user` path param the `app.param` will be triggered
If there are multiple paramters a call to `next()` will be done for every param callback.
And for the the last param the a cll to next will call the next middlewarfe for the route.

```js
app.param(['id', 'page'], function (req, res, next, value) {
  console.log('CALLED ONLY ONCE with', value)
  next()
})

app.get('/user/:id/:page', function (req, res, next) {
  console.log('although this matches')
  next()
})

app.get('/user/:id/:page', function (req, res) {
  console.log('and this matches too')
  res.end()
}
```

## app.render()

returns a rendered HTML.

## app.route()

This method is used to handle mutliple http methods with optional middleware,all at once.

```js
app
  .route("/meetings")
  .get((req, res) => {
    res.send("All Meetings");
  })
  .post((req, res) => {
    res.end("Meeting added successfully");
  });
```

## app.use()

Used to write middleware
What it will do is it will run for every request which starts with "/" as this is the default
behaviour which can be altered.
ex:

```js
app.use("/", (req, res, next) => {
  console.log(req.method, req, url, new Date().getFullYear());
});
```

Another ex:

```js
app.use(express.json());
app.use(express.urlencoded());
```

This will allow to send json,urlencoded to the server
