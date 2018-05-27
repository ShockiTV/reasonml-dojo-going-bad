[@bs.deriving abstract]
type composableMapProps = {
  width: int,
  height: int,
};

[@bs.module "react-simple-maps"]
external composableMap : ReasonReact.reactClass = "ComposableMap";

let make = (~width, ~height, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMap,
    ~props=composableMapProps(~width, ~height),
    children,
  );