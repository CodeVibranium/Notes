# Request

## Properties

### req.app

### req.baseUrl

### req.body

Contains key value pairs data submitted in request body.

- Body is populated when using body=parser middleware

1. express.json()
2. express.urlencoded({extended:true}) // application/x-www-form-urlencoded
3. express.urlencoded()

### req.cookies

- parse cookire **COOKIE-PARSER**
- should use cookie-parse middleware.
- Contains an objects (key value) cookies sent by the request
- if cookie is signed you have touse `req.signedCookies`
- As HTTP is stateless we need to send some specific info to retreive some specific data.
- When u make a req to a web server, server sends you a cookie, holding a specific piece of data, and that cookie should be stored in client side and for any subsequent req u need to send those cookies to the server to get the required data.

```js
app.use(cookieParser());
response.headers.cookie; //raw cookie
response.cookie;
response.cookie("visited", true, { maxAge: 600000 });
```

### req.signedCookies

- look up for these today

### req.fresh

If response is still fresh cahche true is sent, else false

### req.stale

Tells if the response is stale.

### req.hostname

tells the hostname derived from HTTP header

### req.ip

Tells about the ip address of the request

### req.ips

- look up for these today

### req.method

Tells about the REQ method

### req.url

prints the incoming req.url

### req.originalUrl

It retains orinial req url allowing you to rewrite req.url freely for internal routing.
originalUrl is a combination of req.baseUrl and req.url

### req.params

This property conatins object mapped to name route parameters

### req.path

Contains the path partt of the url

```js
// baseUrl/group/:groupName/:groupId?member=ali&userId=10
// req.path = /group/:groupname/:groupId
```

### req.query

- this property return an object conaining key value pairs for for the query string
- route paramters are used to find out some data present in the database.
- a query param should be used when yop want to do some operation on that data which is not going the change the actual db data eg sort, limit, offset, min, max, filter,

### req.protocol

- Tells about the req protocol (https || http)

```js
var qs = require("qs");
app.setting("query parser", function (str) {
  return qs.parse(str, {
    /* custom options */
  });
});
```

### req.res

This property holds a reference to incoming response obj

### req.route

Contains currently matched route stack trace.

### req.secure

Tells if the established connection is secure (https)
