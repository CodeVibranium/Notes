# Router

` const {router}=require("express")`
A router in express helps us to seperate the endpoint into its own file, it makes code more modular and maintainable.

ex:

```js
// In todo.js file
const { router } = require("express");
router.get("/todos/", (req, res) => {
  res.status(200).send(db.todos);
});
router.post("/add/", (req, res) => {
  db.todos.push(req.body);
});
router.put("/update-todo/:id", (req, res) => {
  //update logic
});

module.exports = router;

// in index.js file

const todoRouter = require("./routes/todo");
app.use("/api", todoRouter);
```
