async function authorize(event, context, cb) {
  `there are two modes
	token mode (default), pass token in authorization header
	request mode: 
	`;

  console.log("EVENT DATA===>", event);
  const canAccess = event.authorizationToken;
  if (canAccess === "allow") {
    cb(null, generatePolicy("user", "Allow", event.methodArn));
  } else if (canAccess === "deny") {
    cb(null, generatePolicy("user", "Deny", event.methodArn));
  } else {
    cb("Error: Invalid Token");
  }
}

function generatePolicy(principleId, effect, resource) {
  let policyDocument = {};
  policyDocument.principalId = principleId;
  policyDocument.policyDocument = {
    Version: "2012-10-17", // needs to be valid Version Date, not any date
    Statement: [
      { Effect: effect, Resource: resource, Action: "execute-api:Invoke" },
    ],
  };
  policyDocument.context = { data: "My middleware data" };

  `this data within context will be in req event, under requestContext
  "requestContext": {
    "resourceId": "7qi9nk",
    "authorizer": {
        "data": "My middleware data",
        "principalId": "user",
        "integrationLatency": 0
    },
  `;
  console.log("POLICY-DOCUMENT\n", JSON.stringify(policyDocument));
  return policyDocument;
}
module.exports = { authorize };
