import React, { useEffect, useState } from "react";
export function useFetch(url, method) {
  if (!url) throw new Error("URL is required");
  if (typeof url !== "string") throw new Error("URL must be a string");

  const [apiRes, setApiRes] = useState({
    data: null,
    loading: false,
    error: false,
  });
  async function fetchData() {
    setApiRes({ ...apiRes, loading: true });
    try {
      const res = await fetch(url, { method });
      if (!res.ok) throw new Error(res.statusText);
      const data = await res.json();
      setApiRes({ ...apiRes, data });
    } catch (error) {
      setApiRes({ ...apiRes, error: error.message });
    } finally {
      setApiRes({ ...apiRes, loading: false });
    }
  }

  useEffect(() => {
    fetchData();
  }, [url, method]);
  return apiRes;
}

function App() {
  const apiRes = useFetch("abc", "GET");
}
