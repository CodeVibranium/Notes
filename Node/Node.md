# Node

A runtime for js
Node.js is a c++ program with v8 embedded

## Node Core

Ecmascript dosent talk about js accessing DOM elements and manipulating DOM elements
AJAX request and other functions are added to js in browser by the browser and the V8.

## What does js need to manage servers?

1. Ways to deal with files
2. Ways to deal with database
3. Ways to communicated over the internet
4. Accept request and send responses in HTTP
5. Way to deal with work that takes long time']
   > And these things donot come out of the JS box
   > All of these are additions on top JS created by NODE

## How node modules work

> Require's are cached
> Encapsulation can be done using modules
> for ex

```js
var secretKey = SomeRandomKey;
function encryptPassword(password) {
  var hashedPassword = hasPasswordWithSecretKey(password, secretKey);
  return hashedPassword;
}
module.exports = { encryptPassword };
```

From tha bove example secret key and hasPassword function has not been revbelaled to the user
