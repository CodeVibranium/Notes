const db = require("../db");
const NOTES_TABLE_NAME = process.env.NOTES_TABLE_NAME;
async function getAllNotes(event, context, cb) {
  console.log("NOTES_TABLE_NAME", NOTES_TABLE_NAME);
  try {
    const params = {
      TableName: NOTES_TABLE_NAME || "notes",
    };
    const notes = await db.scan(params).promise();
    console.log("params", params);
    console.log("NOTES", notes);
    cb(null, {
      statusCode: 200,
      body: JSON.stringify({
        notes,
      }),
    });
  } catch (error) {
    console.log("SHAHED ALI\n", error);
    cb(null, {
      statusCode: error.statusCode,
      message: error.message || "No message",
      error,
    });
  }
}

module.exports = getAllNotes;
