# access child state from parent

- ## this is without pssing any function
- we can do this by forawrding the ref
- pass ref to child component
- useImperativeHandle()
  - u can update state from parent and vice versa
  - state update done from child will not reflect in parent but vice versa is possible
  - will not have access to updated state in parent
- ## pass read and write function as props
  - <ChildCOmp logStateChange={onStateChange} updateState={updateState}>
    function onStateChange(value)=>{console.log(value)}
      function updateState(value)={
    // import the exprted setState using useImpreativehandlie and update it
      }
