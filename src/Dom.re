open Webapi.Dom;

[@bs.set_index] external setPropertyOnElement : (Element.t, string, 'a) => unit = "";

let setChildren = (element, child) =>
  switch (Util.typeof(child)) {
  | "string"
  | "number" =>
    /* Since `child` can be a number at runtime, but the type system
       thinks its always a stirng, we just always concatenate it with an empty
       string so that the runtime value will definitely be a string */
    Element.setTextContent(
      element,
      "" ++ child
    )
  /* @TODO this should probably throw if we're seeing non-primitive children here? */
  | _ => ignore()
  };

let setDangerousInnerHTML = (element, innerHTML: ReactFiber.dangerousInnerHTML) =>
  Element.setInnerHTML(element, innerHTML##__html);

let setUnreservedProperty = (element, props, key) =>
  /* let value = ReactFiber.getValueFromProps(props, key); */
  setPropertyOnElement(
    element,
    key,
    ReactFiber.getValueFromProps(props, key)
  );

let setCSSStyle = (element, style) => {
  /* setPropertyOnElement(element, "style", style); */
  CSS.setStyle(element, style);
};

let setInitialProperties = (element, props: ReactFiber.props) =>
  Js.Obj.keys(props)
  |> Js.Array.forEach(
       (key) =>
         switch key {
         /* Children may be strings or numbers */
         | "children" => setChildren(element, props##children)
         /* The CSS module handles setting the style value */
         | "style" => setCSSStyle(element, props##style)
         | "dangerouslySetInnerHTML" =>
           setDangerousInnerHTML(element, props##dangerouslySetInnerHTML)
         | _ => setUnreservedProperty(element, props, key)
         }
     );