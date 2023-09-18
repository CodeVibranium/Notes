async function getANote(event) {
  return {
    statusCode: 200,
    body: JSON.stringify(
      {
        message: `Note with ${event.pathParameters.id} has been fetched successfully`,
        input: event,
      },
      null,
      2
    ),
  };
}

module.exports = getANote;
