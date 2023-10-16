import React, { useEffect, useImperativeHandle, useState } from "react";

function Child(props, ref) {
  const [name, setName] = useState("");
  useImperativeHandle(ref, () => ({
    name,
    setName,
  }));

  useEffect(() => {
    props.logStateChange(name);
  }, [name]);
  return (
    <input
      placeholder="Child input"
      onChange={(e) => {
        props.updateState(e.target.value);
        setName(e.target.value);
      }}
      value={name}
    />
  );
}

export default React.forwardRef(Child);
