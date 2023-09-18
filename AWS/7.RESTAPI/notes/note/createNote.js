const db = require("../db");
const { v4: uuidv4 } = require("uuid");

async function createNote(event, context, cb) {
  let data = JSON.parse(event.body);
  try {
    const inputData = {
      TableName: "notes",
      Item: {
        notesId: uuidv4(),
        ...data,
      },
    };
    const res = await db.put(inputData).promise();
    cb(null, {
      statusCode: 201,
      body: JSON.stringify(
        {
          message: "Created note successfully!",
          dbRes: res,
          input: event,
        },
        null,
        2
      ),
    });
  } catch (error) {
    console.log("ERROR", error);
    cb(null, {
      statusCode: error.statusCode || 500,
      body: JSON.stringify(
        {
          message: error.message || error.Message || "Something went wrong",
          error,
        },
        null,
        2
      ),
    });
  }
  return;
}

module.exports = createNote;
