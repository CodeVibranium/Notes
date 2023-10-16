# Timelimits

- Api gateway 29 seconds
- Lambda 15 minutes
- Dynamobd

# API authorization and authentication

- make API key required true
- deploy the API.
- create a usage plan
- [enable throttling](https://www.petefreitag.com/item/853.cfm), rate and burst
- add some quota
- now add an api stage
- now assign each user with that key and people with that key can only access that API.

## Why not use API key for authentication and autorization

1.  because it is static
2.  if using same api key to multiple usercs can access all the apis

## When API is useful

1. For API daily quota.
   - burst and throttle

## Lambda authorizer

- A most flexible way to do authoriztio and authentication
- API gateway will call another lambda function (regular)
- This lambda function will acts as alayer where all the authentication logic is written
- This will also act as a Identity propvider
- A lmbda auth function will take, token & other auth data and in return it will validate given details
- and returns an IAM policy
- While creating any **AWS IAM policy the version should be valid date**
