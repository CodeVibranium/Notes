# Creating a function which return promise

## A function using callback

```js
readFile(
  "filepath",
  "encoding",
  (err,
  (data) => {
    if (err) {
      return err;
    }
    return data;
  })
);
```

## CONVERTING A NORMAL FUNC TO PROMISE

```js
const getText = (path) => {
  return new Promise((resolve, reject) => {
    readFile(
      path,
      "encoding",
      (err,
      (data) => {
        if (err) {
          reject(err);
        }
        resolve(data);
      })
    );
  });
};
```

> To convert any function in to a promise we can also use `util.promisify` method to convert that func into a promise and can be handled in a async await way.
