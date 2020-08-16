type t =
  | Home
  | Greeting(string);

let fromUrl = (url: ReasonReactRouter.url) =>
  switch (url.path) {
  | [] => Some(Home)
  | ["greeting", greet] => Some(Greeting(greet))
  | _ => None
  };

type t';

external make: string => t' = "%identity";
external toString: t' => string = "%identity";

let home = "/"->make;
let greeting = greet => ("/greeting/" ++ greet)->make;
// nothing definition for notfound cause all of undefined route is `Notfound`
