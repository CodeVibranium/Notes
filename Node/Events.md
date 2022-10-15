# Events

Something that has happend in our app that we can respon to.
System events such as done reading file, writing fle etc are handled by libuv

Custom events are events are handled by event emiiter

Event listener is some code that respons to an event

## Adding events

```js
// in emiiter.js
function Emitter() {
  this.events = {};
}

Emitter.prototype.on = function (eventName, eventCallback) {
  this.events[eventName] = this.events[eventName] || [];
  this.events[eventName].push(eventCallback);
};

Emitter.prototype.emit = function (type) {
  if (this.events[type]) {
    this.events[type].forEach(function (eachCallback) {
      eachCallback();
    });
  }
};
```

## Best events practices

```js
var eventConfig = require("./eventConfg").events;

// in eventConfig.js

module.exports.events = {
  GREET: "greet",
  WELCOME: "welcome",
};
```

## What is the differnce between Function and Events?
