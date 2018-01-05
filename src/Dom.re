open Webapi;

/* Lets us set an arbitrary property on an Element. We need this since we don't maintain
   a list of all possible properties (which we couldn't anyways if we allow arbitary attributes) */
[@bs.set_index] external setPropertyOnElement : (Dom.Element.t, string, 'a) => unit = "";

/* Returns true if the `key` starts with "on", which we assume means it's an event listener. We
   Do not validate whether the event is actually valid or not. Js.String.slice requires that we provide a ~to_
   value, so we just pass 50 assuming that no event name will be longer than that */
let isEventListener = (propKey) =>
  "on" == (propKey |> Js.String.slice(~from=2, ~to_=50) |> Js.String.toLowerCase);

/* Returns the event type which we can pass to addEventListener to listen to the event */
let getEventType = (propKey) =>
  propKey |> Js.String.slice(~from=2, ~to_=50) |> Js.String.toLowerCase;

let setChildren = (element, child) =>
  switch (Util.typeof(child)) {
  | "string"
  | "number" =>
    /* Since `child` can be a number at runtime, but the type system
       thinks its always a stirng, we just always concatenate it with an empty
       string so that the runtime value will definitely be a string */
    Dom.Element.setTextContent(element, "" ++ child)
  /* @TODO this should probably throw if we're seeing non-primitive children here? */
  | _ => ignore()
  };

let setDangerousInnerHTML = (element, innerHTML: ReactFiber.dangerousInnerHTML) =>
  Dom.Element.setInnerHTML(element, innerHTML##__html);

let setUnreservedProperty = (element, props, key) =>
  /* let value = ReactFiber.getValueFromProps(props, key); */
  if (isEventListener(key)) {
    let eventType = getEventType(key);
    let listener = ReactFiber.getValueFromProps(props, key);
    Dom.Element.addEventListener(eventType, listener, element) |> ignore
  } else {
    setPropertyOnElement(element, key, ReactFiber.getValueFromProps(props, key))
  };

let setInitialProperties = (element, props: ReactFiber.props) =>
  Js.Obj.keys(props)
  |> Js.Array.forEach(
       (key) =>
         switch key {
         /* Children may be strings or numbers */
         | "children" => setChildren(element, props##children)
         /* The CSS module handles setting the style value */
         | "style" => CSS.setStyle(element, props##style)
         | "dangerouslySetInnerHTML" =>
           setDangerousInnerHTML(element, props##dangerouslySetInnerHTML)
         | _ => setUnreservedProperty(element, props, key)
         }
     );