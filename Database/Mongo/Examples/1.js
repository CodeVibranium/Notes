// How to find values which are similar
const data = [
  {
    _id: {
      $oid: "6395471f80495752e7208c63",
    },
    elements: [
      {
        name: "Alice",
        age: 20,
      },
      {
        name: "Bob",
        age: 21,
      },
      {
        name: "Charlie",
        age: 23,
      },
    ],
  },
  {
    _id: {
      $oid: "6395486980495752e7208c67",
    },
    elements: [
      {
        name: "Alice",
        age: 20,
      },
      {
        name: "Bob",
        age: 21,
      },
      {
        name: "Bob",
        age: 24,
      },
    ],
  },
];
// Query
db.collection.find({
  elements: {
    $elemMatch: {
      name: "Bob",
    },
  },
  $expr: {
    $gt: [
      {
        $size: {
          $filter: {
            input: "$elements",
            cond: {
              $eq: ["$$this.name", "Bob"],
            },
          },
        },
      },
      1,
    ],
  },
});

// Accumulator
db.collection.aggregate([
  {
    $match: { department: "Finance" },
  },
  {
    $group: {
      _id: "$department",
      count: { $sum: 1 },
      data: {
        $accumulator: {
          init: function () {
            return { count: 0, maleCount: 0, femaleCount: 0 };
          },
          accumulate: function (state, gender) {
            if (gender === "Male") {
              state.maleCount + 1;
            }
            if (type === "Female") {
              state.femaleCount + 1;
            }
            state.count + 1;
            return state;
          },
          accumulateArgs: ["$user.gender"],
          merge: function (state1, state2) {
            return {
              count: state1.count + state2.count,
              maleCount: state1.maleCount + state2.maleCount,
              femaleCount: state1.femaleCount + state2.femaleCount,
            };
          },
          finalize: function (state) {
            return state;
          },
          lang: "js",
        },
      },
    },
  },
]);
