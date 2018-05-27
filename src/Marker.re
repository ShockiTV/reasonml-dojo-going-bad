type markerProp = {coordinates: (float, float)};

[@bs.deriving abstract]
type markerProps = {marker: markerProp};

[@bs.module "react-simple-maps"]
external markerComponent : ReasonReact.reactClass = "Marker";

let make = (~marker, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerComponent,
    ~props=markerProps(~marker),
    children,
  );