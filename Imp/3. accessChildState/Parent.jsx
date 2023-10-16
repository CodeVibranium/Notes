import React, { useEffect } from "react";
import Child from "./child";

function Parent() {
  const childRef = useRef(null);
  useEffect(() => {
    if (childRef.current !== null) {
      console.log("GET-Name==", childRef.current.getName());
    }
  });
  return (
    <>
      <div>Parent</div>
      <Child ref={childRef} />
    </>
  );
}

export default Parent;
