# React Testing Library.

- A default setup now a days is RTL + TS = a react project

## Types of testing

1. Manual testing

   - time consuming
   - not reliable

2. Automated testing (writing code to test code)
   - not time consuming
   - reliable, consistent and error prone
   - easy to identify,
   - confidence

---

## Jest vs RTL

- JEST

  - A js testing framework
  - Finds the test, and returns the result in a human readable manner

- RTL

  - provides a virtual dom for testing react components.
  - VDOM is required to interact and verify the behaviour of react components
  - core lib is called DOM testing library, RTL is a wrapper around this library to trst react apps in a easier way.

---

## Automated Tests

1. Unit Testing

   - focussed oon testing individual building blocks suc as a class, function, component etc..
   - each unit is tested in isolation
   - dependencies are mocked
   - runs in a short amount of time, **easy to pinpoint failures**
   - eaiser to write and maintain.

2. Integration Tests

   - testing combination of units and ensuring that they work together.
   - take longer than unit tets

3. E2E test

   - Focussed on testing enitre application flow and ensuring it works as designed from start to finish.
   - involves a real UI, a real backend database real services etc...
   - time consuming
   - has cost implication.

---

## RTL Philosophy

- refactoring will not effect your test as long as the ned result is the same.

## RTL

### Anatomy

- test (name, fn, timeout)
- name : identify the test
- fn : Expectations to test
- timeout : specify how long to wait before aborting the test, default 5 seconds

---

Methods from @testing-library/react

- render creates a virtual dom
- screen **obj which contains methods to query virtual dom**

## TDD Test driven development

- Write tests before writing code to ensure the tests pass
- create tests that verify the functionaluty of a specifc feature.
- write ocde that will run the tests successfully when re-executed
- refactor code for optimaztion while ensuring the continue to pass
  Also called **red-green** testing as all test go from a red failed state to green passed state.

## Jest Watch mode

- by default jest runs test only which are edited.
- `test.skip()`
- `test.only()`

## Grouping tests

- Describe ( a global method)
- anatomy => describe(test name, ()=>{tests})
- allowed to use `.only` and `.skip` with describe.
- describe blocks can be nested.
- can add multiple descibe blocks in the same file.

- Test suite -> a file which contains test.

## File name conventions

- .test.tsx
- .spec.js.tsx
- \_\_tests\_\_

## Alternative methods

- test -> it
- test.only -> fit
- text.skip -> xit

## Code coverage

- metric to understand how much of your code is tested

1. Statement coverage
   - How many statements of your code was tested
2. Branches coverage
   - How many if else conditions were tested
3. Function coverage
   - How many function definiations were called and tested
4. Line coverage
   - how many lines of code was tested

Address the red numbers

```json
{
  "coverage": "yarn test --coverage --watchAll --collectCoverageFrom='src/components/**/*.{ts,tsx}'"
}
```

## Coverage Threshold

```json
{
  "jest": {
    "coverageThreshold": {
      "global": {
        "branches": 80,
        "functions": 80,
        "lines": 80,
        "statements": -10
      }
    }
  }
}
```

- With this configuration jest will fail if,
  1. less than 80% branch, line or function coverage.
  2. if there as more than 10 statements which were not tested.

## Assertions

- Assertions are what checks if a value meets a certain condition.
- They decide whether the tests passed or failed
- They are run using the global `expect` method
- Expect is normally used with a matcher function to assert something about a value.

## Different matcher functions

- [Matchers](https://jestjs.io/docs/using-matchers)
- [Jest DOM](https://github.com/testing-library/jest-dom)

# What to TEST?

- Test
  1. Component render
  2. Component renders with proper props
  3. Component renders in different states
  4. Component reacts to events (BTN, Form CTRL)

## What not to TEST

- Not to test

  1.  Implementation details
  2.  Third party code.
  3.  Code not important in user POV.

# RTL Queries

- Every test generally involves these basic steps

  1.  Render the component.
  2.  Find an element rendered by the component.
  3.  Assert against the element found in step 2 which will pass or fail the test.

- To find a single element on the page.
  1.  getBy..
  2.  queryBy..
  3.  findBy..
- To find multiple elements on the page.
  1. getAllBy..
  2. queryAllBy..
  3. findAllBy..
- The suffix can be one of role, labeltext, placeholdertext, text, display text, altext, title etc..

## GetBy Query

1. getByRole
   - queries for elements with the given role.
   - role refers to **ARIA (Accessible Rich Internet App)** which provide sematic meaning to content to ensure people using assistive technologies are able to use them
