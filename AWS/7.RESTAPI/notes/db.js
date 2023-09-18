const DynamoDB = require("aws-sdk/clients/dynamodb");
const db = new DynamoDB.DocumentClient({
  region: "ap-south-1",
  maxRedirects: 3,
  httpOptions: {
    timeout: 5000,
  },
});
module.exports = db;
