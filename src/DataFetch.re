/* type Fetcher.data = {
     username: string,
     location: (float, float),
   }; */

type locationArray = array(Fetcher.data);

type action =
  | Load(locationArray);

type state = {locations: locationArray};

let component = ReasonReact.reducerComponent("DataFetch");

let make = _children => {
  ...component,
  initialState: () => {locations: [||]},
  reducer: (action, _state) =>
    switch (action) {
    | Load(locations) => ReasonReact.Update({locations: locations})
    },
  didMount: self => {
    let fetchCallback = locations => self.send(Load(locations));
    Fetcher.fetchGet(
      ~url="https://immense-river-25513.herokuapp.com/locations",
      ~cb=fetchCallback,
    );
  },
  render: self =>
    <ComposableMap width=1000 height=1000>
      <ZoomableGroup>
        <Geographies geography="world-50m.json">
          ...(
               (geographies, projection) =>
                 Js.Array.mapi(
                   (geography, index) =>
                     <Geography
                       geography
                       projection
                       key=(string_of_int(index))
                     />,
                   geographies,
                 )
             )
        </Geographies>
      </ZoomableGroup>
    </ComposableMap>,
  /* <Markers>
         ...(Js.Array.mapi(
           (marker: Fetcher.data, index) =>
             <Marker
               marker={coordinates: marker.location}
               key=(string_of_int(index))
             />,
           self.state.locations,
         ))
     </Markers> */
};

/* let yolofunc: string => unit = [%raw
     {|
     function(a) {
       alert("hello " + a);
     }

   |}
   ];
   yolofunc("aaa"); */