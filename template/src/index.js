// this is a (proxy) from `index.re` (index.bs.js) cause `react-scripts` entry point is `index.js`
import "./index.bs.js";
// we can move `reportWebVitals` to `index.re` but need to bind/interop it
import reportWebVitals from "./reportWebVitals";

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
