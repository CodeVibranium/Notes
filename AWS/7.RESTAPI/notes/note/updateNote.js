const db = require("../db");

async function updateNote(event, context, cb) {
  console.log("EVENT\n", event);
  console.log("context\n", context);
  const updateData = JSON.parse(event.body);
  const notesId = event.pathParameters.id;
  try {
    const res = db
      .update({
        TableName: "notes",
        Key: { notesId },
        AttributeUpdates: updateData,
      })
      .promise();
    console.log("RES", res);
    cb();
  } catch (error) {
    console.log("ERROR", error);
  }
  return {
    statusCode: 200,
    body: JSON.stringify(
      {
        message: `Note with ${event.pathParameters.id} has been updated successfully`,
        input: event,
      },
      null,
      2
    ),
  };
}

module.exports = updateNote;
