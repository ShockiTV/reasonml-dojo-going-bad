type projectionType;
type geographyType;

[@bs.deriving abstract]
type geographyProps = {
  geography: geographyType,
  projection: projectionType,
};

[@bs.module "react-simple-maps"]
external geographyComponent : ReasonReact.reactClass = "Geography";

let make = (~geography, ~projection, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyComponent,
    ~props=geographyProps(~geography, ~projection),
    children,
  );