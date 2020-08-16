type t =
  | Home
  | Greeting(string);

let fromUrl: ReasonReactRouter.url => option(t);

type t';

external make: string => t' = "%identity";
external toString: t' => string = "%identity";

let home: t';
let greeting: string => t';
