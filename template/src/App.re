/* import module from external (javascript module_*/
%raw
{j|require("./App.css")|j};

let logo = [%raw {j|require("./logo.svg")|j}];

/* an example implementation of router */
module AppRouter = {
  open Router;
  [@react.component]
  let make = () => {
    let route = Router.useRouter();
    let currentRoute =
      switch (route) {
      | Some(Home) => "Home"
      | Some(Greeting(greet)) => "Greeting: " ++ greet
      | None => "Handle Notfound"
      };
    <>
      <ul style={ReactDOM.Style.make(~listStyle="none", ~padding="0", ())}>
        <li>
          <Link route=Route.home className="App-link">
            "Home"->React.string
          </Link>
        </li>
        <li>
          <Link className="App-link" route={Route.greeting("reason-id")}>
            "Greeting: from @reason-id"->React.string
          </Link>
        </li>
        <li>
          <Link className="App-link" route={"/xyz/nothing#321"->Route.make}>
            "Random: make Notfound"->React.string
          </Link>
        </li>
      </ul>
      <code> {("Current Route: " ++ currentRoute)->React.string} </code>
    </>;
  };
};

[@react.component]
let make = () => {
  let (showRouter, setShowRouter) = React.useState(_ => false);
  <div className="App">
    <header className="App-header">
      <img src=logo className="App-logo" alt="logo" />
      <a
        style={ReactDOM.Style.make(
          ~cursor="pointer",
          ~textDecoration="underline",
          (),
        )}
        className="App-link"
        onClick={_ => setShowRouter(current => !current)}>
        "Click Me: for Show `AppRouter`"->React.string
      </a>
    </header>
    <section>
      {showRouter
         ? <AppRouter />
         : <>
             <p>
               "Edit "->React.string
               <code> "src/App.re"->React.string </code>
               " and save to reload."->React.string
             </p>
             <a
               className="App-link"
               href="https://reactjs.org"
               target="_blank"
               rel="noopener noreferrer">
               "Learn React"->React.string
             </a>
             <a
               className="App-link"
               href="https://github.com/reason-id/cra-template"
               target="_blank"
               rel="noopener noreferrer">
               "fork me on github"->React.string
             </a>
           </>}
    </section>
  </div>;
};
