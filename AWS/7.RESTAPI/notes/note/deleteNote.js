const db = require("../db");

async function deleteANote(event, context, cb) {
  try {
    const id = event.pathParameters.id;
    console.log("ID \n", id);
    const res = await db
      .delete({
        TableName: "notes",
        Key: { notesId: id },
        // ConditionExpression: `attribute_not_exists(${id})`,
      })
      .promise();
    console.log("RES \n", res);
    cb(null, {
      statusCode: 201,
      body: JSON.stringify({
        data: res,
        message: "Note deleted successfully",
      }),
    });
  } catch (error) {
    console.log("error-ALI\n", error);
    cb(null, {
      message: error.message || "Something went wrong",
      statusCode: error.statusCode || 500,
      error,
    });
  }
}

module.exports = deleteANote;
