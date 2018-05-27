type geographyItemType;

[@bs.deriving abstract]
type geographiesProps = {geography: string};

[@bs.module "react-simple-maps"]
external geographies : ReasonReact.reactClass = "Geographies";

let make = (~geography, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographies,
    ~props=geographiesProps(~geography),
    children,
  );