let useRouter = () => ReasonReactRouter.useUrl()->Route.fromUrl;

let push = route => route->Route.toString->ReasonReactRouter.push;
let replace = route => route->Route.toString->ReasonReactRouter.replace;

// Component like `Link` from `react-router-dom` or similar.
module Link = {
  [@react.component]
  let make = (~route: Route.t', ~children, ~className=?) => {
    let location = route->Route.toString;

    <a
      ?className
      href=location
      onClick={event =>
        if (!event->ReactEvent.Mouse.defaultPrevented
            && event->ReactEvent.Mouse.button == 0
            && !event->ReactEvent.Mouse.altKey
            && !event->ReactEvent.Mouse.ctrlKey
            && !event->ReactEvent.Mouse.metaKey
            && !event->ReactEvent.Mouse.shiftKey) {
          event->ReactEvent.Mouse.preventDefault;
          location->ReasonReactRouter.push;
        }
      }>
      children
    </a>;
  };
};

open Route;
// this is an extra/bonus cause `reason-react` isn't have `goBack` API in ReasonReactRouter.
let goBack = route =>
  switch (route) {
  | Some(Home) => "im-from-home"->greeting->replace
  | _ => home->replace
  };
