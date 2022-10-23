# Sessions

- Cokies are not preferable to use as they are stored on client side
- the reason not to data on client side bcz they can be hacked by MIM Attack.

## npm i express-session

- used to persist information on our server
  ```js
  const session = require(express - session);
  app.use(
    session({
      secret: "randon text", // used to encrypt and decrypt cookie
      resave: false,
      saveuninitialized: false,
    })
  );
  ```
